#include <iostream>
using namespace std;
#include "Cronograma.h"
#include "BaseCalculo.h"
#include "Buque.h"
#include "Agencia.h"
#include "Fecha.h"
#include <cstdlib>
#include <cstring>
#include <cstdio>


void Cronograma::setIdCronograma( int idAgencia , int idRegion , int idGiro ){
    _idCronograma[0] = idAgencia;
    _idCronograma[1] = idRegion;
    _idCronograma[2] = idGiro;
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

int *Cronograma::getIdCronograma(){
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

    cout << "INGRESE NUMERO DE SEMANA: ";
    cin >> _numSemana;

    cout << "INGRESE ID AGENCIA: ";
    cin >> _idAgencia;

    cout << "INGRESE ID REGION: ";
    cin >> _idRegion;

    cout << "INGRESE ID BUQUE: ";
    cin >> _idBuque;

    cout << "INGRESE NUMERO DE VIAJE: ";
    cin >> _numeroViaje;

    int giro = BuscarIdTerminal(_idBuque);
    setIdCronograma(_idAgencia , _idRegion , giro);
//    int ds = BuscarDiaSemana(_idCronograma);

}

void Cronograma::mostrar(){

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

int BuscarDiaSemana( Cronograma crono ){
    int pos = 0;
    BaseCalculo reg;

    while(reg.leerDeDisco(pos++)){
       if (crono == reg.getIdReferencia())
        return reg.getDiaETA();

    }
}


bool Cronograma::operator ==(int *aux){

   // cout << "ESTOY ACA";

 if( _idCronograma[0] != aux[0] ) return false;
 if( _idCronograma[1] != aux[1] ) return false;
 if( _idCronograma[2] != aux[2] ) return false;

 return true;
}
