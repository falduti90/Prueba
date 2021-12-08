#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Agencia.h"
#include "../Validaciones.h"

Agencia::Agencia() {
    _idAgencia = 0;
    strcpy( _nombreAgencia , "NO SE INGRESO EL NOMBRE DE LA AGENCIA");
    _disponibilidadMensual = 0;
    _gastosLocales = 0;
    _activo = true;
}

int  Agencia::setIdAgencia(int nuevoID) {
    _idAgencia = nuevoID;
}

char Agencia::setNombreAgencia(char *nuevoNombre) {
    strcpy( _nombreAgencia , nuevoNombre );
}

int  Agencia::setDisponibilidadMensual(int nuevoCupo) {
    _disponibilidadMensual = nuevoCupo;
}

float Agencia::setGastosLocales(float nuevoGasto) {
    _gastosLocales = nuevoGasto;
}

bool Agencia::setActivo(bool nuevoEstado) {
    _activo = nuevoEstado;
}

int Agencia::getIdAgencia(){
    return _idAgencia;
}

char *Agencia::getNombreAgencia() {
    return _nombreAgencia;
}

int Agencia::getDisponibilidadMensual() {
    return _disponibilidadMensual;
}

float Agencia::getGastosLocales() {
    return _gastosLocales;
}

bool Agencia::getActivo() {
    return _activo;
}

void Agencia::cargar() {
    bool aux;

    do{
        aux = false;
        cout<< "INGRESE EL ID DE LA AGENCIA: ";
        cin>> _idAgencia;
        if (validaIdAgencia ( _idAgencia) ){
                aux = true;
                cout << endl << "YA EXISTE UNA AGENCIA CON ESE ID." << endl << endl;
        }
        if (_idAgencia <= 0 ){
                aux = true;
                cout << endl << "HA INGRESADO UN ID INVALIDO." << endl << endl;
        }
    } while ( aux );


        cout<< "INGRESE EL NOMBRE DE LA AGENCIA: ";
        cin.ignore();
        cin.getline( _nombreAgencia , 99 );
        while (validaNombreAgencia ( _nombreAgencia)){
                cout << endl << "YA EXISTE UNA AGENCIA CON ESE NOMBRE." << endl << endl;
                cout<< "INGRESE EL NOMBRE DE LA AGENCIA: ";
                cin.getline( _nombreAgencia , 99 );
        }

    do {
        cout<< "INGRESE LA DISPONIBILIDAD MENSUAL: ";
        cin>> _disponibilidadMensual;
    } while ( !validaPositivo ( _disponibilidadMensual));

    do {
        cout<< "INGRESE LOS GASTOS LOCALES: USD";
        cin>> _gastosLocales;
    } while ( !validaPositivo ( _gastosLocales));


    cout << endl << endl;
    system("pause");
    system("cls");

}

void Agencia::mostrar() {
    if(_activo == true){
        cout << "\t\t\t\t" << "ID AGENCIA            : " << _idAgencia << endl ;
        cout << "\t\t\t\t" << "NOMBRE AGENCIA        : " << _nombreAgencia << endl;
        cout << "\t\t\t\t" << "DISPONIBILIDAD MENSUAL: " << _disponibilidadMensual << endl;
        cout << "\t\t\t\t" << "GASTOS FIJOS          : " << _gastosLocales << endl;
    }
}

bool Agencia::leerDeDisco(int pos) {
    FILE *p;
    p = fopen("Agencias.dat","rb");
    if ( p == NULL ){
    cout << "No se pudo abrir el archivo";
    return false;
    }

    fseek ( p , sizeof(Agencia)*pos , 0 );
    bool leyo = fread( this , sizeof(Agencia) , 1 , p);
    fclose(p);
    return leyo;

}

bool Agencia::grabarEnDisco() {

    FILE *p;
    p = fopen("Agencias.dat","ab");
    if ( p == NULL ){
        cout<< "No se pudo abrir el archivo ";
        return false;
    }

    bool ok =  fwrite( this , sizeof(Agencia) , 1 , p);
    if ( ok == true){
        cout << "Registro guardado"<<endl;
    }
    else {
        cout << "No se guardo el registro"<<endl;
    }
    fclose(p);
    return ok;

}


//-------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES

void BuscarAgencia(int idAgencia){
    int pos = 0;
    Agencia reg;

    while(reg.leerDeDisco(pos++)){
        if (idAgencia == reg.getIdAgencia()){
        cout << reg.getNombreAgencia();
        }
    }
}

char *BuscarAgencia(int idAgencia, bool i){
    int pos = 0;
    Agencia reg;

    while(reg.leerDeDisco(pos++)){
        if (idAgencia == reg.getIdAgencia()){
            return reg.getNombreAgencia();
        }
    }
}


bool BorrarRegistroAgencia(){

    Agencia reg;
    int IdAgencia, pos;

    cout << "\t\t\t\t\t\t***ELIMINAR REGISTRO***" << endl << endl;
    cout << "\t\t\t\t*******************************************" << endl << endl;
    cout << "\t\t\t\t\tINGRESE ID DE AGENCIA: ";
    cin  >> IdAgencia;

    pos = AgenciaAborrar(IdAgencia);

    if(pos == -1){
        cout << endl << endl,
        cout << "\t\t\t\t\tNO EXISTE EL ID INGRESADO." << endl << endl,
        cout << "\t\t\t\t\t" << system("pause");
        system("cls");
        return false;
    }
    reg.leerDeDisco(pos);
    reg.setActivo(false);

    if(reg.ModificarEnDiscoAgencia(pos)){
        cout << "\t\t\t\t\t" << "REGISTRO BORRADO.";
        cout << endl << endl,
        cout << "\t\t\t\t\t" << system("pause");
        system("cls");
        return true;
    }
    else{
        cout << endl << endl;
        cout << "\t\t\t\t\tNO SE PUDO ABRIR EL ARCHIVO." << endl;
        return false;
    }
    cout << endl << endl,
    cout << "\t\t\t\t\t" << system("pause");
}

int AgenciaAborrar(int idAgencia){

    Agencia reg;
    int pos = 0;

    while(reg.leerDeDisco(pos)){
        if (idAgencia == reg.getIdAgencia()){
            return pos;
        }
        pos++;
    }
    return -1;
}

bool Agencia::ModificarEnDiscoAgencia(int pos){

    FILE *p;
    p = fopen("Agencias.dat","rb+");
    if ( p == NULL){
        return false;
    }
    fseek(p , sizeof(Agencia)*pos , 0 );
    bool ok = fwrite(this, sizeof(Agencia), 1, p);
    fclose(p);
    return ok;
}



