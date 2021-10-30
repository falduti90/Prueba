#include <iostream>
using namespace std;
#include "Cronograma.h"
#include "Fecha.h"
#include "Buque.h"
#include "Agencia.h"
#include <cstdlib>
#include <cstring>
#include <cstdio>


void Cronograma::setIdCronograma(char *idCronograma){
    strcpy( _idCronograma , idCronograma );
}

void Cronograma::setNumSemana(int num){
    _numSemana = num;

}

void Cronograma::setFechaRecepcionCnt(Fecha f){
    _fechaRecepcionCnt = f;
}

void Cronograma::setFechaETA(Fecha f){
    _fechaETA = f;

}

void Cronograma::setFechaETD(Fecha f){
        _fechaETD = f;
}

void Cronograma::setFechaCutoffFisico(Fecha f){
        _fechacutoffFisico = f;
}

void Cronograma::setFechaCutoffDoc(Fecha f){
        _fechacutoffDoc = f;
}

void Cronograma::setActivo(bool nuevoEstado){
    _activo = nuevoEstado;

}

char *Cronograma::getIdCronograma(){
    return _idCronograma;
}

Fecha Cronograma::getFechaRecepcionCnt(){
    return _fechaRecepcionCnt;
}

Fecha Cronograma::getFechaETA(){
    return _fechaETA;
}

Fecha Cronograma::getFechaETD(){
    return _fechaETD;
}

Fecha Cronograma::getFechaCutoffFisico(){
    return _fechacutoffFisico;
}

Fecha Cronograma::getFechaCutoffDoc(){
    return _fechacutoffDoc;
}

int Cronograma::getNumSemana(){
    return _numSemana;
}

bool Cronograma::getActivo(){
    return _activo;
}

void Cronograma::cargar(){

    int dia, mes, anio;
    Fecha obj;

    cout<< "INGRESE ID CRONOGRAMA: ";  //TODO armar que se concatene agencia + terminal
    cin.ignore();
    cin.getline( _idCronograma , 99 );

    cout << "INGRESE ID AGENCIA: ";
    cin >> _idAgencia;

    cout << "INGRESE ID BUQUE: ";
    cin >> _idBuque;

    cout << "INGRESE NUMERO DE VIAJE: ";
    cin >> _numeroViaje;

    cout << "INGRESE FECHAS: " << endl;
    cout << "-------------- " << endl;
    cout << "ETA: ";
    cin >> dia >> mes >> anio;
    obj = BuscarEnCalendario(dia, mes, anio);
    setFechaETA(obj);
    setNumSemana(obj.getNumeroSemana());

    cout << "ETD: ";
    cin >> dia >> mes >> anio;
    obj = BuscarEnCalendario(dia, mes, anio);
    setFechaETD(obj);

    cout << "CUT OFF FISICO: ";
    cin >> dia >> mes >> anio;
    obj = BuscarEnCalendario(dia, mes, anio);
    setFechaCutoffFisico(obj);

    cout << "CUT OFF DOCUMENTAL: ";
    cin >> dia >> mes >> anio;
    obj = BuscarEnCalendario(dia, mes, anio);
    setFechaCutoffDoc(obj);

    cout << "INICIO DE RECEPCION: ";
    cin >> dia >> mes >> anio;
    obj = BuscarEnCalendario(dia, mes, anio);
    setFechaRecepcionCnt(obj);

}

void Cronograma::mostrar(){

    cout << _idCronograma << ", ";
    BuscarAgencia(_idAgencia);
    cout << ", ";
    BuscarBuque(_idBuque);
    cout << ", ";
    cout << _numeroViaje << ", ";
    getFechaETD().mostrar();
    cout << ", ";
    getFechaETA().mostrar();
    cout << ", ";
    getFechaCutoffDoc().mostrar();
    cout << ", ";
    getFechaCutoffFisico().mostrar();
    cout << ", ";
    getFechaRecepcionCnt().mostrar();
}

bool Cronograma::leerDeDisco(int pos){
    FILE *p;
    p = fopen("Cronograma.dat","rb");
    if ( p == NULL ){
        cout << "No se pudo abrir el archivo";
    return false;
    }

    fseek ( p , sizeof(Cronograma)*pos , 0);
    bool leyo = fread( this , sizeof(Cronograma) , 1 , p );
    fclose(p);
    return leyo;

}

bool Cronograma::grabarEnDisco(){
    FILE *p;
    p = fopen("Cronograma.dat","ab");
    if ( p == NULL ) {
        cout << "No se pudo abrir el archivo";
        return false;
    }

    bool ok =  fwrite( this , sizeof(Cronograma) , 1 , p );
    if ( ok == true ) {
        cout << "Registro guardado"<<endl;
    }
    else{
        cout << "No se guardo el registro"<<endl;
    }
    fclose(p);
    return ok;
}

//---------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES
void ListadoCronograma() {

    FILE *p;
    Cronograma reg;
   p=fopen("Cronograma.dat","rb");
    if(p==NULL){
        cout<< "No se pudo abrir el archivo";
    return ;
    }

    while(fread(&reg,sizeof(Cronograma),1,p)==1){
        reg.mostrar();
        cout << endl;
    }

    fclose(p);
}


Fecha BuscarEnCalendario(int dia, int mes, int anio){
    Fecha f;
    int i = 0;
    while (f.leerDeDisco(i)){
        if (f.getDia() == dia && f.getMes() == mes && f.getAnio() == anio){
            return f;
        }
        i++;
    }

}

void BuscarBuque(int idBuque){
    int pos = 0;
    Buque reg;

    while(reg.leerDeDisco(pos++)){
        if (idBuque == reg.getIdBuque()){
        cout << reg.getnombreBuque();
        }
    }
}

void BuscarAgencia(int idAgencia){
    int pos = 0;
    Agencia reg;

    while(reg.leerDeDisco(pos++)){
        if (idAgencia == reg.getIdAgencia()){
        cout << reg.getNombreAgencia();
        }
    }
}

