#include<iostream>
using namespace std;
#include<clocale>
#include <string.h>
#include "BaseCalculo.h"
#include "Cronograma.h"
#include "Region.h"
#include "Terminal.h"
#include "Agencia.h"
#include "../Validaciones.h"



void BaseCalculo::setidAgencia ( int idAgencia ){
    _idAgencia = idAgencia;
}

void BaseCalculo::setidRegion ( int idRegion ){
    _idRegion = idRegion;

}

void BaseCalculo::setidGiro ( int idGiro ){
    _idTerminalDeGiro = idGiro;
}

void BaseCalculo::setDiaETA ( int diaSem ){
    _diaETA = diaSem;
}

void BaseCalculo::setCalculoETD ( int sumaDias ){
    _calculoETD = _diaETA + sumaDias;  // TODO: Habría que ponerle validación para que no siga sumando si excede días de semana
}

void BaseCalculo::setDiaCTF ( int diaSem ){
    _diaCTF = diaSem;
}

void BaseCalculo::setHoraCTF ( int hora ){
    _horaCTF = hora;
}

void BaseCalculo::setDiaCTD ( int diaSem ){
    _diaCTD = diaSem;
}

void BaseCalculo::setHoraCTD ( int hora ){
    _horaCTD = hora;
}

void BaseCalculo::setCalculoRecepcionCnt ( int restaDias ){
    _calculoRecepcionCnt = restaDias;

// TODO: Habría que ponerle validación para que no siga restando si terminó días de semana
}

void BaseCalculo::setIdBaseCalculo( int idAgencia , int idRegion , int idGiro ){
    _idBaseCalculo[0] = idAgencia;
    _idBaseCalculo[1] = idRegion;
    _idBaseCalculo[2] = idGiro;
}

////////////////// GETS ////////////////////////////


int BaseCalculo::getidAgencia (){
    return _idAgencia;
}

int BaseCalculo::getidRegion (){
    return _idRegion;
}

int BaseCalculo::getidGiro (){
    return _idTerminalDeGiro;

}

int BaseCalculo::getDiaETA (){
    return _diaETA;
}

int BaseCalculo::getCalculoETD (){
    return _calculoETD;
}

int BaseCalculo::getDiaCTF (){
    return _diaCTF;
}

int BaseCalculo::getHoraCTF (){
    return _horaCTF;
}

int BaseCalculo::getDiaCTD (){
    return _diaCTD;
}

int BaseCalculo::getHoraCTD (){
    return _horaCTD;
}

int BaseCalculo::getCalculoRecepcionCnt (){
    return _calculoRecepcionCnt;
}

int *BaseCalculo::getIdBaseCalculo(){
    return _idBaseCalculo;
}

////////////////// OTROS ////////////////////////////


void BaseCalculo::cargar(){
    cout << "INGRESE ID AGENCIA: ";
    cin >> _idAgencia;
    while (!validaIdAgencia ( _idAgencia)){
            cout << endl << "NO SE ENCUENTRA AGENCIA CON ESE ID." << endl << endl;
            cout << "INGRESE ID AGENCIA: ";
            cin >> _idAgencia;
        }

    cout << "INGRESE ID REGION: ";
    cin >> _idRegion;
    while (!validaIdRegion ( _idRegion)){
            cout << endl << "NO SE ENCUENTRA REGION CON ESE ID." << endl << endl;
            cout << "INGRESE ID REGION: ";
            cin >> _idRegion;
    }


    cout << "INGRESE ID TERMINAL DE GIRO: ";
    cin >> _idTerminalDeGiro;
    while (!validaIdTerminal ( _idTerminalDeGiro)){
            cout << endl << "NO SE ENCUENTRA TERMINAL CON ESE ID." << endl << endl;
            cout << "INGRESE ID TERMINAL DE GIRO: ";
            cin >> _idTerminalDeGiro;
    }


    cout << "DIAS DE SEMANA: Dom 0,  Lun 1, Mart 2, Mier 3, Juev 4, Vier 5, Sab 6 " << endl;
    do{
        cout << "DIA ETA: ";
        cin >> _diaETA;
    } while ( !validaDiaSemana ( _diaETA));

    do{
        cout << "DIA CUT OFF FISICO: ";
        cin >> _diaCTF;
    } while ( !validaDiaSemana ( _diaCTF));

    do{
        cout << "HORA CUT OFF FISICO: ";
        cin >> _horaCTF;
    } while ( !validaHora ( _horaCTF));

    do{
        cout << "DIA CUT OFF DOCUMENTAL: ";
        cin >> _diaCTD;
    } while ( !validaDiaSemana ( _diaCTD));

    do{
        cout << "HORA CUT OFF DOCUMENTAL: ";
        cin >> _horaCTD;
    } while ( !validaHora ( _horaCTD));

    do{
        cout << "ETD (CUANTOS SE ADICIONAN A LA ETA): ";
        cin >> _calculoETD;
    } while ( !validaPositivo ( _calculoETD));

    do{
        cout << "RECEPCION DEL CNT (CUANTOS DIAS SE RESTAN A LA ETA): ";
        cin >> _calculoRecepcionCnt;
    } while ( !validaPositivo ( _calculoRecepcionCnt));

    setIdBaseCalculo( _idAgencia , _idRegion , _idTerminalDeGiro );
    _activo = true;

}

void BaseCalculo::mostrar(){
    cout << "\t\t\t\t\t" << "ID: ";
    mostrarIdBaseCalculo();
    cout <<  "\t\t\t\t\t" << "AGENCIA: ";
    BuscarAgencia(_idAgencia);
    cout  << endl;
    cout <<  "\t\t\t\t\t" << "REGION: ";
    BuscarRegion(_idRegion);
    cout << endl;
    cout <<  "\t\t\t\t\t" << "TERMINAL DE GIRO: ";
    BuscarTerminal(_idTerminalDeGiro);
    cout << endl;

    cout <<  "\t\t\t\t\t" << "DIA ETA: ";
    diaSemana(_diaETA);
    cout << endl;
    cout <<  "\t\t\t\t\t" << "DIA CUT OFF FIS: ";
    diaSemana(_diaCTF);
    cout << " " << _horaCTF << " HRS" << endl;
    cout <<  "\t\t\t\t\t" << "DIA CUT OFF DOC: ";
    diaSemana(_diaCTD);
    cout << " " << _horaCTD << " HRS" << endl;

    cout <<  "\t\t\t\t\t" << "DIAS QUE SUMA PARA ETD: " << _calculoETD << endl;
    cout <<  "\t\t\t\t\t" << "DIAS QUE RESTA PARA RECEPCION DEL CNT: " << _calculoRecepcionCnt << endl;
}

void BaseCalculo::mostrarIdBaseCalculo(){
    for ( int i = 0 ; i < 3 ; i++){
        cout << _idBaseCalculo[i] << " ";
    }
    cout << endl;
}


bool BaseCalculo::leerDeDisco(int pos){
    FILE *p;
    p = fopen("BasesCalculos.dat","rb");
    if ( p == NULL ){
        cout << "No se pudo abrir el archivo";
    return false;
    }

    fseek ( p , sizeof(BaseCalculo)*pos , 0);
    bool leyo = fread( this , sizeof(BaseCalculo) , 1 , p );
    fclose(p);
    return leyo;

}

bool BaseCalculo::grabarEnDisco(){
    FILE *p;
    p = fopen("BasesCalculos.dat","ab");
    if ( p == NULL ) {
        cout << "No se pudo abrir el archivo";
        return false;
    }

    bool ok =  fwrite( this , sizeof(BaseCalculo) , 1 , p );
    if ( ok == true ) {
        cout << "Registro guardado"<<endl;
    }
    else{
        cout << "No se guardo el registro"<<endl;
    }
    fclose(p);
    return ok;
}

bool BaseCalculo::grabarEnDisco(int){
    //TODO
}


//---------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES

void diaSemana(int dia){

//Domingo  = 0,  Lunes = 1, Martes = 2, Miercoles = 3, Jueves  =4, Viernes = 5, Sabado = 6
 string d[] = {"Dom", "Lun", "Mar", "Mie", "Jue", "Vie", "Sab"};

 cout << d[dia];


}



