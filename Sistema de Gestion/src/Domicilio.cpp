#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Domicilio.h"

Domicilio::Domicilio() {
    _altura = 0;
    strcpy( _calle , "NO SE INGRESO EL NOMBRE DE LA CALLE" );
}

void  Domicilio::setCalle(char *nuevaCalle) {
    strcpy( _calle , nuevaCalle );
}

void  Domicilio::setAltura(int nuevaAltura) {
    _altura = nuevaAltura;
}

void  Domicilio::setLocalidad(char *nuevaLocalidad) {
    strcpy( _localidad , nuevaLocalidad );
}


char* Domicilio::getCalle() {
    return _calle;
}

int   Domicilio::getAltura() {
    return _altura;
}

char* Domicilio::getLocalidad() {
    return _localidad;
}

void  Domicilio::cargar() {

    cout<<"INGRESE EL NOMBRE DE CALLE:  ";
    cin.ignore();
    cin.getline( _calle , 99 );
    cout<<"INGRESE LA ALTURA DE LA CALLE:  ";
    cin>> _altura;
    cout<<"INGRESE LA LOCALIDAD:  ";
    cin.ignore();
    cin.getline( _localidad , 99 );
}

void  Domicilio::mostrar() {
    cout<< "DOMICILIO       : " << _calle << endl;
    cout<< "ALTURA          : " << _altura << endl;
    cout<< "LOCALIDAD       : " << _localidad << endl;
}

bool  Domicilio::leerDeDisco(int pos) {
    FILE *p;
    p = fopen("Domicilios.dat","rb");
    if ( p == NULL ){
    cout << "No se pudo abrir el archivo";
    return false;
    }

    fseek ( p , sizeof(Domicilio)*pos , 0 );
    bool leyo = fread( this , sizeof(Domicilio) , 1 , p );
    fclose(p);
    return leyo;
}

bool  Domicilio::grabarEnDisco() {
    FILE *p;
    p = fopen("Domicilios.dat","ab");
    if ( p == NULL )
    {
        cout << "No se pudo abrir el archivo";
        return false;
    }

    bool ok=  fwrite(this,sizeof(Domicilio),1,p);
    if (ok==true) {
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

void ListadoDeDomicilios(){

    FILE *p;
    Domicilio reg;
    p = fopen("Domicilios.dat","rb");
    if ( p == NULL ){
        cout << "No se pudo abrir el archivo";
    return ;
    }

    while ( fread ( &reg , sizeof(Domicilio) , 1 , p ) ==1 ){
        reg.mostrar();

    }

    fclose(p);
}
