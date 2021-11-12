#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Terminal.h"
#include "Domicilio.h"


Terminal::Terminal(){
    _idTerminal = 0;
    strcpy( _nombreTerminal , "NO SE INGRESO NOMBRE DE TERMINAL" );
    strcpy( _email , "NO SE INGRESO UN E-MAIL" );
    _gastosFijos = 0;
    _activo = true;

}

void Terminal::setIdTerminal(int nuevoID){
    _idTerminal = nuevoID;

}

void Terminal::setNombreTerminal(char *nuevoNombre){
    strcpy( _nombreTerminal , nuevoNombre );

}

void Terminal::setDireccion (Domicilio nuevaDir){
    _direccion = nuevaDir;
}

void Terminal::setEmail(char* nuevoEMail){
   strcpy( _email , nuevoEMail );
}

void Terminal::setGastosFijos(float nuevoGasto){
    _gastosFijos = nuevoGasto;
}

void Terminal::setActivo(bool nuevoEstado){
    _activo = nuevoEstado;
}

char *Terminal::getNombreTerminal(){
    return _nombreTerminal;
}

Domicilio Terminal::getDireccion(){
    return _direccion;
}

int Terminal::getIdTerminal(){
    return _idTerminal;
}

char *Terminal::getEmail(){
    return _email;
}

float Terminal::getGastosFijos(){
    return _gastosFijos;
}

void Terminal::cargar(){
    cout<< "INGRESE EL ID DE LA TERMINAL    : ";
    cin >> _idTerminal;

    cout<< "INGRESE EL NOMBRE DE LA TERMINAL: ";
    cin.ignore();
    cin.getline( _nombreTerminal , 99 );

    cout<< "INGRESE EL EMAIL DE LA TERMINAL : ";
    cin.getline( _email , 99 );

    cout<< "INGRESE EL GASTO FIJO           : ";
    cin >> _gastosFijos;

    _direccion.cargar();

}

void Terminal::mostrar(){

    cout<< "ID TERMINAL     : "<< _idTerminal << endl;
    cout<< "NOMBRE TERMINAL : "<< _nombreTerminal << endl;
    cout<< "EMAIL           : "<< _email << endl;
    cout<< "GASTOS FIJOS    : "<< _gastosFijos << endl;
    _direccion.mostrar();



}

bool Terminal::leerDeDisco(int pos){
    FILE *p;
    p = fopen("Terminal.dat","rb");
    if ( p == NULL ){
    cout << "No se pudo abrir el archivo";
    return false;
    }

    fseek ( p , sizeof(Terminal)*pos , 0 );
    bool leyo = fread (this , sizeof(Terminal) , 1, p );
    fclose(p);
    return leyo;
}

bool Terminal::grabarEnDisco(){
    FILE *p;
    p = fopen("Terminal.dat","ab");
    if ( p == NULL ){
        cout << "No se pudo abrir el archivo";
        return false;
    }

    bool ok =  fwrite(this,sizeof(Terminal),1,p);

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

void ListadoDeTerminales(){

    FILE *p;
    Terminal reg;
    p = fopen("Terminal.dat","rb");
    if ( p == NULL ){
        cout << "No se pudo abrir el archivo";
    return ;
    }

    while( fread ( &reg , sizeof(Terminal) , 1 ,  p) == 1){
        reg.mostrar();
        cout << endl;
    }

    fclose(p);
}

void BuscarTerminal(int idTerminal){
    int pos = 0;
    Terminal reg;

    while(reg.leerDeDisco(pos++)){
        if (idTerminal == reg.getIdTerminal()){
        cout << reg.getNombreTerminal();
        }
    }
}



