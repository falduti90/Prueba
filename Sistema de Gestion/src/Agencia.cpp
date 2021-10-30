#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Agencia.h"

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
    cout<< "INGRESE EL NUMERO DE ID DE LA AGENCIA: ";
    cin>> _idAgencia;

    cout<< "INGRESE EL NOMBRE DE LA AGENCIA: ";
    cin.ignore();
    cin.getline( _nombreAgencia , 99 );

    cout<< "INGRESE LA DISPONIBILIDAD MENSUAL: ";
    cin>> _disponibilidadMensual;

    cout<< "INGRESE LOS GASTOS LOCALES: ";
    cin>> _gastosLocales;

}

void Agencia::mostrar() {
    cout<< "ID AGENCIA            : "<< _idAgencia << endl ;
    cout<< "NOMBRE AGENCIA        : "<< _nombreAgencia << endl;
    cout<< "DISPONIBILIDAD MENSUAL: "<< _disponibilidadMensual << endl;
    cout<< "GASTOS FIJOS          : "<< _gastosLocales << endl;

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

void ListadoDeAgencias(){

    FILE *p;
    Agencia reg;
    p = fopen("Agencias.dat","rb");
    if( p == NULL ){
        cout << "No se pudo abrir el archivo";
    return ;
    }

    while ( fread( &reg , sizeof(Agencia) , 1 , p ) == 1 ){
        reg.mostrar();
        cout << endl;
    }

    fclose(p);
}
