#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Buque.h"
#include "Terminal.h"

Buque::Buque(){
    _idBuque = 0;
     strcpy( _nombreBuque , "NO SE INGRESO NOMBRE" );
    strcpy( _banderaBuque , "NO SE INGRESO BANDERA" );
    _activo = true;

}

void Buque::setIdBuque(int nuevoId){
    _idBuque = nuevoId;
}

void Buque::setnombreBuque(char* nuevoNombre){
    strcpy( _nombreBuque , nuevoNombre );
}

void Buque::setBanderaBuque(char *nuevaBandera){
    strcpy( _banderaBuque , nuevaBandera );
}

void Buque::setGiro(int nuevoGiro){
    _giro = nuevoGiro;
}

void Buque::setActivo(bool nuevoEstado){
    _activo = nuevoEstado;
}

int  Buque::getIdBuque(){
    return _idBuque;
}

char *Buque::getnombreBuque(){
    return _nombreBuque;
}

char *Buque::getBanderaBuque(){
    return _banderaBuque;
}

int  Buque::getGiro(){
    return _giro;
}

bool Buque::getActivo(){
    return _activo;
}

void Buque::cargar(){

    cout<< "INGRESE EL ID DEL BUQUE     : ";
    cin >> _idBuque;

    cout<< "INGRESE EL NOMBRE DEL BUQUE : ";
    cin.ignore();
    cin.getline(_nombreBuque,99);

    cout<< "INGRESE LA BANDERA DEL BUQUE: ";
    cin.getline(_banderaBuque,99);

    cout<< "INGRESE ID TERMINAL         : ";
    cin >> _giro;   /// TODO Acá habría que agregar alguna validación que revise que el ID existe...
    cout << endl;
    grabarEnDisco();

}

void Buque::mostrar(){
    cout<< "NUMERO DE ID BUQUE-: "<< _idBuque << endl;
    cout<< "NOMBRE DEL BUQUE---: "<< _nombreBuque << endl;
    cout<< "BANDERA------------: "<< _banderaBuque << endl;
    // cout<< "GIRO---------------: "<< _giro << endl << endl;
    cout<< "GIRO---------------: ";
    buscarTerminal(_giro);
    cout << endl;
}

bool Buque::grabarEnDisco(){
    FILE *p;
    p = fopen("Buques.dat","ab");
    if ( p == NULL ){
        cout << "No se pudo abrir el archivo";
        return false;
    }

    bool ok =  fwrite( this , sizeof(Buque) , 1 , p );
    if ( ok == true )  {
        cout << endl << "Registro guardado" << endl << endl;
    }
    else {
        cout << "No se guardo el registro"<<endl;
    }
    fclose(p);

}


bool Buque::leerDeDisco(int pos) {

    FILE *p;
    p=fopen("Buques.dat","rb");
    if ( p == NULL ){
        cout<< "No se pudo abrir el archivo";
    return false;
    }

    fseek ( p , sizeof(Buque)*pos , 0 );
    bool leyo = fread( this , sizeof(Buque) , 1 , p );
    fclose(p);
    return leyo;

}

//---------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES
void ListadoBuques() {

    FILE *p;
    Buque reg;
    p = fopen("Buques.dat","rb");
    if ( p == NULL ){
        cout << "No se pudo abrir el archivo";
    return ;
    }

    while ( fread ( &reg , sizeof(Buque) , 1 , p ) == 1 ){
        reg.mostrar();
        cout << endl;
    }

    fclose(p);
}

void buscarTerminal(int giro){
    int pos = 0;
    Terminal reg;
    while(reg.leerDeDisco(pos++)){
        if (giro == reg.getIdTerminal()){
        cout << reg.getNombreTerminal();
        }
    }
}

void BuscarBuque(int idBuque){
    int pos = 0;
    Buque reg;

    while(reg.leerDeDisco(pos++)){
        if (idBuque == reg.getIdBuque()){
        printf("%-4.28s",reg.getnombreBuque());
//        cout << reg.getnombreBuque();
        cout << ", ";
        BuscarTerminal(reg.getGiro());
        return;
        }
    }
}

int BuscarIdTerminal(int idBuque){
    int pos = 0;
    Buque reg;

    while(reg.leerDeDisco(pos++)){
        if (idBuque == reg.getIdBuque()){
        return reg.getGiro();
        }
    }
}
