#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Terminal.h"
#include "Domicilio.h"
#include "Buque.h"
#include "../Validaciones.h"


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
    bool aux;

    do{
        aux = false;
        cout<< "INGRESE EL ID DE LA TERMINAL: ";
        cin>> _idTerminal;
        if (validaIdTerminal ( _idTerminal)){
                aux = true;
                cout << endl << "YA EXISTE UNA TERMINAL CON ESE ID." << endl << endl;
        }
        if (_idTerminal <= 0 ){
                aux = true;
                cout << endl << "HA INGRESADO UN ID INVALIDO." << endl << endl;
        }
    } while ( aux );

    cout<< "INGRESE EL NOMBRE DE LA TERMINAL: ";
    cin.ignore();
    cin.getline( _nombreTerminal , 99 );
    while (validaNombreTerminal ( _nombreTerminal)){
            cout << endl << "YA EXISTE UNA TERMINAL CON ESE NOMBRE." << endl << endl;
            cout<< "INGRESE EL NOMBRE DE LA TERMINAL: ";
            cin.getline( _nombreTerminal , 99 );
    }

    cout<< "INGRESE EL EMAIL DE LA TERMINAL : ";
    cin.getline( _email , 99 );

    do{
        cout<< "INGRESE EL GASTO FIJO           : ";
        cin >> _gastosFijos;
    } while ( !validaPositivo ( _gastosFijos));

    _direccion.cargar();

}

void Terminal::mostrar(){
    if(_activo){
        cout << "\t\t\t\t" << "ID TERMINAL     : "<< _idTerminal << endl;
        cout << "\t\t\t\t" << "NOMBRE TERMINAL : "<< _nombreTerminal << endl;
        cout << "\t\t\t\t" << "EMAIL           : "<< _email << endl;
        cout << "\t\t\t\t" << "GASTOS FIJOS    : "<< _gastosFijos << endl;
        _direccion.mostrar();
    }
}

bool Terminal::leerDeDisco(int pos){
    FILE *p;
    p = fopen("Terminales.dat","rb");
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
    p = fopen("Terminales.dat","ab");
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

void BuscarTerminal(int idTerminal){
    int pos = 0;
    Terminal reg;

    while(reg.leerDeDisco(pos++)){
        if (idTerminal == reg.getIdTerminal()){
        cout << reg.getNombreTerminal();
        }
    }
}


char *BuscarTerminal(int idBuque, bool i){
    int pos = 0;
    Terminal reg;
    Buque aux;
    int idTerminal = 0;

    if (i){

        while(aux.leerDeDisco(pos++)){
            if (idBuque == aux.getIdBuque()){
                idTerminal = aux.getTerminalDeGiro();
            }
        }
    }
    else{
        idTerminal = idBuque;
    }

    pos = 0;
    while(reg.leerDeDisco(pos++)){
        if (idTerminal == reg.getIdTerminal()){
            return reg.getNombreTerminal();
        }
    }
}


bool BorrarRegistroTerminal(){

    Terminal reg;
    int IdTerminal, pos;

    cout << "\t\t\t\t\t\t***ELIMINAR REGISTRO***" << endl << endl;
    cout << "\t\t\t\t*******************************************" << endl << endl;
    cout << "\t\t\t\t\tINGRESE ID DE TERMINAL: ";
    cin  >> IdTerminal;

    pos = TerminalAborrar(IdTerminal);

    if(pos == -1){
        cout << endl << endl,
        cout << "\t\t\t\t\tNO EXISTE EL ID INGRESADO." << endl << endl,
        cout << "\t\t\t\t\t" << system("pause");
        system("cls");
        return false;
    }
    reg.leerDeDisco(pos);
    reg.setActivo(false);

    if(reg. ModificarEnDiscoTerminal(pos)){
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

int TerminalAborrar(int idTerminal){

    Terminal reg;
    int pos = 0;

    while(reg.leerDeDisco(pos)){
        if (idTerminal == reg.getIdTerminal()){
            return pos;
        }
        pos++;
    }
    return -1;
}

bool Terminal::ModificarEnDiscoTerminal(int pos){

    FILE *p;
    p = fopen("Terminales.dat","rb+");
    if ( p == NULL ){
        return false;
    }
    fseek(p , sizeof(Terminal)*pos , 0 );
    bool ok = fwrite(this, sizeof(Terminal), 1, p);
    fclose(p);
    return ok;
}



