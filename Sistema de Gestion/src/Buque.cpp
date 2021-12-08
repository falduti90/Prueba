#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Buque.h"
#include "Terminal.h"
#include "Cronograma.h"
#include "Rlutil.h"
#include "../Validaciones.h"

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

void Buque::setTerminalDeGiro(int nuevoGiro){
    _terminalDeGiro = nuevoGiro;
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

int  Buque::getTerminalDeGiro(){
    return _terminalDeGiro;
}

bool Buque::getActivo(){
    return _activo;
}

void Buque::cargar(){
    bool aux;

    do{
        aux = false;
        cout<< "INGRESE EL ID DEL BUQUE: ";
        cin>> _idBuque;
        if (validaIdBuque ( _idBuque)){
                aux = true;
                cout << endl << "YA EXISTE UN BUQUE CON ESE ID." << endl << endl;
        }
        if (_idBuque <= 0 ){
                aux = true;
                cout << endl << "HA INGRESADO UN ID INVALIDO." << endl << endl;
        }
    } while ( aux );


    cout<< "INGRESE EL NOMBRE DEL BUQUE: ";
    cin.ignore();
    cin.getline( _nombreBuque , 99 );
    while (validaNombreBuque ( _nombreBuque)){
            cout << endl << "YA EXISTE UN BUQUE CON ESE NOMBRE." << endl << endl;
            cout<< "INGRESE EL NOMBRE DEL BUQUE: ";
            cin.getline( _nombreBuque , 99 );
    }


    cout<< "INGRESE LA BANDERA DEL BUQUE: ";
    cin.getline(_banderaBuque,99);

    cout << "INGRESE ID TERMINAL DE GIRO: ";
    cin >> _terminalDeGiro;
    while (!validaIdTerminal ( _terminalDeGiro)){
            cout << endl << "NO SE ENCUENTRA TERMINAL CON ESE ID." << endl << endl;
            cout << "INGRESE ID TERMINAL DE GIRO: ";
            cin >> _terminalDeGiro;
    }

    cout << endl;
   // grabarEnDisco();
    cout << endl << endl;
    system("pause");
    system("cls");

}

void Buque::mostrar(){
    system("color 9F");
    if(_activo){
        cout << "\t\t\t\t\t" << "NUMERO DE ID BUQUE: "<< _idBuque << endl;
        cout << "\t\t\t\t\t" << "NOMBRE DEL BUQUE  : "<< _nombreBuque << endl;
        cout << "\t\t\t\t\t" << "BANDERA           : "<< _banderaBuque << endl;
        cout << "\t\t\t\t\t" << "GIRO              : ";
        buscarTerminal(_terminalDeGiro);
        cout << endl;
    }
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
        cout << reg.getnombreBuque();
        cout << ", ";
        BuscarTerminal(reg.getTerminalDeGiro());
        return;
        }
    }
}

char *BuscarBuque(int idBuque, bool b){
    int pos = 0;
    Buque reg;

    while(reg.leerDeDisco(pos++)){
        if (idBuque == reg.getIdBuque()){
        //BuscarTerminal(reg.getTerminalDeGiro());
        return reg.getnombreBuque();
        }
    }
}

int BuscarIdTerminal(int idBuque){
    int pos = 0;
    Buque reg;

    while(reg.leerDeDisco(pos++)){
        if (idBuque == reg.getIdBuque()){
        return reg.getTerminalDeGiro();
        }
    }
}

void ListarPorBuque(){
    system("color 9F");
    Buque reg;
    Cronograma obj;
    int pos = 0, opc;
    char *posicion;
    cout << "\t\t\t\t\tSELECCIONE BUQUE: " << endl << endl;
    cout << "\t\t\t\t*******************************************" << endl << endl;
    while(reg.leerDeDisco(pos++)){
        if(reg.getActivo()){
            if(pos < 10){
            cout << "\t\t\t\t\t" << pos << ".  " << reg.getnombreBuque() << endl;
            }
            else{
            cout << "\t\t\t\t\t" << pos << ". " << reg.getnombreBuque() << endl;
            }
        }
    }
    rlutil::locate(60,1);
    cin >> opc;
    system("cls");
    BuqueSeleccionado(opc);
}

void BuqueSeleccionado(int opc){
    int pos = 0;
    Cronograma reg;

    while(reg.leerDeDisco(pos++)){
        if (opc == reg.getIdBuque()){
            reg.mostrar();
        }
    }
    cout << endl << endl;
    cout << "\t\t\t\t\t" << system("pause");
    system("cls");
}

bool BorrarRegistroBuque(){

    Buque reg;
    int IdBuque, pos;

    cout << "\t\t\t\t\t\t***ELIMINAR REGISTRO***" << endl << endl;
    cout << "\t\t\t\t*******************************************" << endl << endl;
    cout << "\t\t\t\t\tINGRESE ID DE BUQUE: ";
    cin  >> IdBuque;

    //ListadoBuques();

    pos = BuqueAborrar(IdBuque);

    if(pos == -1){
        cout << endl << endl,
        cout << "\t\t\t\t\tNO EXISTE EL ID INGRESADO." << endl << endl,
        cout << "\t\t\t\t\t" << system("pause");
        system("cls");
        return false;
    }
    reg.leerDeDisco(pos);
    reg.setActivo(false);

    if(reg.ModificarEnDiscoBuques(pos)){
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

int BuqueAborrar(int idBuque){

    Buque reg;
    int pos = 0;

    while(reg.leerDeDisco(pos)){
        if (idBuque == reg.getIdBuque()){
            return pos;
        }
        pos++;
    }
    return -1;
}

bool Buque::ModificarEnDiscoBuques(int pos){

    FILE *p;
    p = fopen("Buques.dat","rb+");
    if ( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Buque)*pos , 0 );
    bool ok = fwrite(this, sizeof(Buque), 1, p);
    fclose(p);
    return ok;
}


