#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Region.h"

Region::Region(){
    _idRegion = 0;
    strcpy( _nombreRegion , "NO SE INGRESO EL NOMBRE" );
    _activo = true;

}

void Region::setIdRegion(int nuevoID){
    _idRegion = nuevoID;
}

void Region::setNombreRegion(char *nuevoNombre){
    strcpy( _nombreRegion , nuevoNombre );
}

void Region::setActivo(bool nuevoEstado){
    _activo = nuevoEstado;
}

int  Region::getIdRegion(){
    return _idRegion;
}

char *Region::getNombreRegion(){
    return _nombreRegion;
}

bool Region::getActivo(){
    return _activo;
}

void Region::cargar(){

    cout<< "INGRESE EL NUMERO DE ID REGION: ";
    cin >> _idRegion;

    cout<< "INGRESE  EL NOMBRE DE LA REGION: ";
    cin.ignore();
    cin.getline( _nombreRegion , 99 );

}


void Region::mostrar(){
    cout<< "NUMERO DE ID     : "<< _idRegion << endl;
    cout<< "NOMBRE DE REGION : "<< _nombreRegion << endl;

}


bool Region::leerDeDisco(int pos){
    FILE *p;
    p = fopen("Region.dat","rb");
    if ( p == NULL ){
    cout << "No se pudo abrir el archivo";
    return false;
    }

    fseek ( p , sizeof(Region)*pos , 0);
    bool leyo = fread ( this , sizeof(Region) , 1 , p);
    fclose(p);
    return leyo;
}

bool Region::grabarEnDisco(){
    FILE *p;
    p = fopen("Region.dat","ab");
    if ( p == NULL ) {
        cout << "No se pudo abrir el archivo";
        return false;
    }
    bool ok =  fwrite(this,sizeof(Region),1,p);
    if ( ok == true ) {
        cout << "Registro guardado"<<endl;
    }
    else {
        cout << "No se guardo el registro"<<endl;
    }
    fclose(p);
    return ok;

}


//---------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES

void ListadoDeRegiones(){

    FILE *p;
    Region reg;
    p = fopen("Region.dat","rb");
    if ( p == NULL ){
        cout << "No se pudo abrir el archivo";
    return ;
    }

    while ( fread ( &reg , sizeof(Region) , 1 , p ) == 1 ){
        reg.mostrar();

    }

    fclose(p);
}
