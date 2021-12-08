#include<iostream>
using namespace std;
#include<clocale>
#include "Estadistica.h"
#include "../Validaciones.h"
#include "Cronograma.h"
#include "Agencia.h"
#include "Region.h"
#include "Buque.h"
#include <ctime>

Estadistica::Estadistica(){
    _mesCarga = 0;          //VERRRR, SI ES COMPOSICION, USA CONSTRUCTOR DEL ORIGINAL?
    _anioCarga = 0;
    _idAgencia = 0;
    _idRegion = 0;
    _idBuque = 0;
    _idTerminal = 0;
    _cantContenedores = 0;
    _costoAgencia = 0;
    _costoTerminal = 0;
    _costoTotalAgencia = 0;
    _costoTotalTerminal = 0;
    _activo = true;
}

int Estadistica::getMesCarga(){
    return _mesCarga;
}

int Estadistica::getAnioCarga(){
    return _anioCarga;
}

int Estadistica::getIdAgencia(){
    return _idAgencia;
}

int Estadistica::getCantContenedores(){
    return _cantContenedores;
}

float Estadistica::getCostoAgencia(){
    return _costoAgencia;
}

float Estadistica::getCostoTerminal(){
    return _costoTerminal;
}

float Estadistica::getCostoTotalAgencia(){
    return _costoTotalAgencia;
}

float Estadistica::getCostoTotalTerminal(){
    return _costoTotalTerminal;
}

void  Estadistica::cargar(){
    time_t tSac = time(NULL);  // instante actual
    struct tm* pt1 = localtime(&tSac);
    tm tm2 = *gmtime(&tSac);   // deferencia y asignación
    _anioCarga = tm2.tm_year+1900;

    do{ // PIDE MES DE CARGA
        cout << "MES DE CARGA: ";
        cin >> _mesCarga;
    } while ( !validaMesCarga( _mesCarga));

    cout << "ID AGENCIA: ";
    cin >> _idAgencia;
    while (!validaIdAgencia ( _idAgencia)){
            cout << endl << "NO SE ENCUENTRA AGENCIA CON ESE ID." << endl << endl;
            cout << "INGRESE ID AGENCIA: ";
            cin >> _idAgencia;
        }

    cout << "ID REGION: ";
    cin >> _idRegion;
    while (!validaIdRegion ( _idRegion)){
            cout << endl << "NO SE ENCUENTRA REGION CON ESE ID." << endl << endl;
            cout << "INGRESE ID REGION: ";
            cin >> _idRegion;
    }

    cout << "ID BUQUE: ";
    cin >> _idBuque;
    while (!validaIdBuque ( _idBuque)){
            cout << endl << "NO SE ENCUENTRA BUQUE CON ESE ID." << endl << endl;
            cout << "INGRESE ID BUQUE: ";
            cin >> _idBuque;
    }

    _idTerminal = BuscarIdTerminal(_idBuque);

    do{
        cout << "CANTIDAD DE CONTENEDORES: ";
        cin >> _cantContenedores;
    } while ( !validaMayorCero ( _cantContenedores));

    int espacioDisponible;
    // - SI ES EL PRIMER REGISTROS DE ESE MES, LE ASIGNA EL VALOR QUE TIENE EL ARCHIVO DE AGENCIAS COMO ESPACIO INICIAL
    if ( primerRegistroMes(_anioCarga , _idAgencia , _mesCarga)){
        espacioDisponible  = consultaEspacioInicial(_idAgencia);
        }
        else {   // SINO, LE ASIGNA EL VALOR QUE TIENE EL ARCHIVO DE ESTADISTICA.
            espacioDisponible = calculaEspacioDisponible(_idAgencia , _anioCarga , _mesCarga);
        }


    // VERIFICA QUE LA CANTIDAD DE CONTENEDORES A REGISTRAR NO SUPERE EL ESPACIO DISPONIBLE. Si esta ok, GRABA
    if ( espacioDisponible - _cantContenedores < 0) {
            cout << "NO ES POSIBLE REALIZAR EL REGISTRO." << endl;
            if ( espacioDisponible == 1) cout << "SOLO QUEDA 1 ESPACIO DISPONIBLE. " << endl;
                else if ( espacioDisponible == 0) cout << "YA NO QUEDA ESPACIO DISPONIBLE." << endl;
                    else cout << "HAY " << espacioDisponible << " ESPACIOS DISPONIBLES" << endl;
    } else {
        _costoAgencia           = consultaCostoAgencia(_idAgencia);
        _costoTerminal          = consultaCostoTerminal(_idTerminal);
        _costoTotalAgencia      = _costoAgencia * _cantContenedores;
        _costoTotalTerminal     = _costoTerminal * _cantContenedores;
        //grabarEnDisco();
    }

}

void  Estadistica::mostrar(){
        cout << "ANIO                          : " << _anioCarga << endl;
        cout << "MES                           : " << _mesCarga << endl;
        cout << "AGENCIA                       : ";
        BuscarAgencia(_idAgencia);
        cout << endl;
        cout << "REGION                        : ";
        BuscarRegion(_idRegion);
        cout << endl;
        cout << "BUQUE, TERMINAL               : ";
        BuscarBuque(_idBuque);
        cout << endl;
        cout << "CANT CONTENEDORES             : " <<  _cantContenedores << endl;
        cout << "COSTO UNITARIO AGENCIA        : USD " <<  _costoAgencia << endl;
        cout << "COSTO UNITARIO TERMINAL       : USD " <<  _costoTerminal << endl;
        cout << "COSTO TOTAL AGENCIA           : USD " <<  _costoTotalAgencia << endl;
        cout << "COSTO TOTAL TERMINAL          : USD " <<  _costoTotalTerminal << endl << endl;
}

bool Estadistica::leerDeDisco(int pos){
    FILE *p;
    p = fopen("Estadistica.dat","rb");
    if ( p == NULL ){
        cout << "No se pudo abrir el archivo";
    return false;
    }

    fseek ( p , sizeof(Estadistica)*pos , 0);
    bool leyo = fread( this , sizeof(Estadistica) , 1 , p );
    fclose(p);
    return leyo;

}

bool Estadistica::grabarEnDisco(){
    FILE *p;
    p = fopen("Estadistica.dat","ab");
    if ( p == NULL ) {
        cout << "No se pudo abrir el archivo";
        return false;
    }

    bool ok =  fwrite( this , sizeof(Estadistica) , 1 , p );
    if ( ok == true ) {
        cout << "Registro guardado"<<endl;
    }
    else{
        cout << "No se guardo el registro"<<endl;
    }
    fclose(p);
    return ok;
}



//------------ GLOBALES ------------------
/////////////////////////////////////////////

bool primerRegistroMes(int idAg , int anio , int mes){
    Estadistica reg;
    int pos = 0;

    while( reg.leerDeDisco(pos++)){
            if (reg.getIdAgencia() == idAg && reg.getAnioCarga() == anio && reg.getMesCarga() == mes) return false;
    }

    return true;
}


int consultaEspacioInicial(int idAg){
    Agencia a;
    int pos = 0;
    while ( a.leerDeDisco(pos++)){
        if (a.getIdAgencia() == idAg) return a.getDisponibilidadMensual();
    }

    return 0;
}


float consultaCostoAgencia(int idAg){
    Agencia a;
    int pos = 0;
    while ( a.leerDeDisco(pos++)){
        if (a.getIdAgencia() == idAg) return a.getGastosLocales();
    }

    return 0;
}


float consultaCostoTerminal(int idT){
    Terminal t;
    int pos = 0;
    while ( t.leerDeDisco(pos++)){
        if (t.getIdTerminal() == idT) return t.getGastosFijos();
    }

    return 0;
}


float sumaTotalAgencia(int idAg , int anio ,int mes){
    Estadistica reg;
    int pos = 0 , total = 0;
    while ( reg.leerDeDisco(pos++)){
        if (reg.getIdAgencia() == idAg && reg.getAnioCarga() == anio && reg.getMesCarga() == mes){
            total += reg.getCostoTotalAgencia();
        }
    }

    return total;
}


float sumaTotalTerminal(int idAg , int anio , int mes){
    Estadistica reg;
    int pos = 0 , total = 0;
    while ( reg.leerDeDisco(pos++)){
        if (reg.getIdAgencia() == idAg && reg.getAnioCarga() == anio && reg.getMesCarga() == mes){
        total += reg.getCostoTotalTerminal();
        }
    }
    return total;
}



int cuentaContenedores(int idAg , int anio , int mes ){
    Estadistica reg;
    int cnt  = 0 , pos = 0;

    while ( reg.leerDeDisco(pos++)){
        if (reg.getIdAgencia() == idAg && reg.getAnioCarga() == anio && reg.getMesCarga() == mes) {
            cnt += reg.getCantContenedores();
        }
    }
    return cnt;
}

int calculaEspacioDisponible(int idAg , int anio , int mes ){

    int espacio = consultaEspacioInicial(idAg) - cuentaContenedores(idAg, anio, mes);
    return espacio;
}

int BuscarIdAgencia(int pos){
    Agencia reg;

    reg.leerDeDisco(pos);
    return reg.getIdAgencia();
}


int cantidadAgencias(){
    int bytes, cant;
    FILE *p;
    p = fopen("Agencias.dat", "rb");
    if (p == NULL){
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant = bytes / sizeof(Agencia);
    return cant;
}

bool buscarEnArchivo( int id){
    Estadistica reg;
    int pos = 0;

    while (reg.leerDeDisco(pos++)) {
        if ( reg.getIdAgencia() == id) return true;
    }
    return false;
}

bool buscarAnio( int anio){
    Estadistica reg;
    int pos = 0;

    while (reg.leerDeDisco(pos++)) {
        if ( reg.getAnioCarga() == anio) return true;
    }
    return false;
}


void  resumenAnual(){
    int anio;
    cout << "INGRESE EL ANIO A CONSULTAR: ";
    cin  >> anio;
    if (!buscarAnio(anio)) {
        cout << endl << "NO HAY REGISTROS DEL ANIO " << anio << endl;
        return;
    }

    int i , j ;
    int cantTotalContenedores = 0 , espacioDisponible = 0;
    float costoTotalAgencia = 0 , costoTotalTerminal = 0;
    int cant = cantidadAgencias();

    for ( j = 0 ; j < cant ; j++){
        int idAg = BuscarIdAgencia(j);
            if ( buscarEnArchivo(idAg)){
                cout << "AGENCIA:  ";
                BuscarAgencia(idAg);
                cout << endl;

                for ( i = 0 ; i < 12 ; i++){
                    int mes = i + 1;
                    cout << "MES / ANIO: ";
                    printf("%2d",mes);
                    cout << "/" << anio << endl;
                    cout << "----------------------- ";
                    cantTotalContenedores = cuentaContenedores(idAg , anio , mes);  // = Espacio utilizado
                    if (cantTotalContenedores == 0) cout << " - SIN CARGA - " << endl;
                    else {
                        cout << endl;
                        costoTotalAgencia     = sumaTotalAgencia(idAg , anio , mes );
                        costoTotalTerminal    = sumaTotalTerminal(idAg, anio , mes );
                        espacioDisponible     = consultaEspacioInicial(idAg) - cantTotalContenedores;
                        cout << "ESPACIO UTILIZADO    : "     <<  cantTotalContenedores << endl;
                        cout << "ESPACIO DISPONIBLE   : "     <<  espacioDisponible << endl;
                        cout << "COSTO TOTAL AGENCIA  : USD " <<  costoTotalAgencia << endl;
                        cout << "COSTO TOTAL TERMINAL : USD " <<  costoTotalTerminal << endl << endl;
                    }
                }
        }
    }
}



void  resumenMensual(){
    int anio , mes;
    cout << "INGRESE EL ANIO Y MES A CONSULTAR. " << endl;
    do{
        cout << "ANIO: ";
        cin  >> anio;
        if (!buscarAnio(anio)) cout << endl << "NO HAY REGISTROS DEL ANIO " << anio << endl;
    } while ( !buscarAnio(anio));

    do{
        cout << "MES: ";
        cin >> mes;
    } while ( !validaMesCarga(mes));

    cout << endl;
    int i , j ;
    int cantTotalContenedores = 0 , espacioDisponible = 0;
    float costoTotalAgencia = 0 , costoTotalTerminal = 0;
    int cant = cantidadAgencias();

    for ( j = 0 ; j < cant ; j++){
        int idAg = BuscarIdAgencia(j);
            if ( buscarEnArchivo(idAg)){
                cout << "AGENCIA:  ";
                BuscarAgencia(idAg);
                cout << endl;

                cout << "MES / ANIO: ";
                printf("%2d",mes);
                cout << "/" << anio << endl;
                cout << "----------------------- ";
                cantTotalContenedores = cuentaContenedores(idAg , anio , mes);  // = Espacio utilizado
                if (cantTotalContenedores == 0) cout << " - SIN CARGA - " << endl;
                else {
                    cout << endl;
                    costoTotalAgencia     = sumaTotalAgencia(idAg , anio , mes );
                    costoTotalTerminal    = sumaTotalTerminal(idAg, anio , mes );
                    espacioDisponible     = consultaEspacioInicial(idAg) - cantTotalContenedores;
                    cout << "ESPACIO UTILIZADO    : "     <<  cantTotalContenedores << endl;
                    cout << "ESPACIO DISPONIBLE   : "     <<  espacioDisponible << endl;
                    cout << "COSTO TOTAL AGENCIA  : USD " <<  costoTotalAgencia << endl;
                    cout << "COSTO TOTAL TERMINAL : USD " <<  costoTotalTerminal << endl << endl;
                }
        }
    }
}
