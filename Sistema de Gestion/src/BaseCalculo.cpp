#include<iostream>
using namespace std;
#include<clocale>
#include <string.h>
#include "BaseCalculo.h"
#include "Cronograma.h"
#include "Region.h"
#include "Terminal.h"
#include "Agencia.h"


void BaseCalculo::setidAgencia ( int idAgencia ){
    _idAgencia = idAgencia;
}

void BaseCalculo::setidRegion ( int idRegion ){
    _idRegion = idRegion;

}

void BaseCalculo::setidGiro ( int idGiro ){
    _idGiro = idGiro;
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
//    _calculoRecepcionCnt = _calculoETA ||| _CalculoCOF - restaDias;

// TODO: Habría que ponerle validación para que no siga restando si terminó días de semana
// también si depende de ETA o COF
}

void BaseCalculo::setMismaSemana ( bool misma ){
    _mismaSemana = misma;

}

void BaseCalculo::setIdReferencia( int idAgencia , int idRegion , int idGiro ){
    _idReferencia[0] = idAgencia;
    _idReferencia[1] = idRegion;
    _idReferencia[2] = idGiro;
}

////////////////// GETS ////////////////////////////


int BaseCalculo::getidAgencia (){
    return _idAgencia;
}

int BaseCalculo::getidRegion (){
    return _idRegion;
}

int BaseCalculo::getidGiro (){
    return _idGiro;

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

bool BaseCalculo::getMismaSemana(){
    return _mismaSemana;
}

int *BaseCalculo::getIdReferencia(){
    return _idReferencia;
}

////////////////// OTROS ////////////////////////////


void BaseCalculo::cargar(){
    cout << "ID AGENCIA: ";
    cin >> _idAgencia;
    cout << "ID REGION: ";
    cin >> _idRegion;
    cout << "ID TERMINAL DE GIRO: ";
    cin >> _idGiro;

    cout << "DIAS DE SEMANA (Dom 0,  Lun 1, Mart 2, Mier 3, Juev 4, Vier 5, Sab 6) " << endl;
    cout << "DIA ETA: ";
    cin >> _diaETA;
    cout << "DIA CUT OFF FISICO: ";
    cin >> _diaCTF;
    cout << "HORA CUT OFF FISICO: ";
    cin >> _horaCTF;
    cout << "DIA CUT OFF DOCUMENTAL: ";
    cin >> _diaCTD;
    cout << "HORA CUT OFF DOCUMENTAL: ";
    cin >> _horaCTD;

    cout << "CUANTOS DIAS SE SUMAN PARA EL CALCULO DE LA ETD: ";
    cin >> _calculoETD;
    cout << "CUANTOS DIAS SE RESTAN PARA EL CALCULO DE LA RECEPCION DEL CONTENEDOR: ";
    cin >> _calculoETD;

    cout << "CUT OFF EN MISMA SEMANA QUE ETA (1-SI, 0-NO): ";
    cin >> _mismaSemana;

    setIdReferencia( _idAgencia , _idRegion , _idGiro );
    _activo = true;

    cout << endl << endl;
    system("pause");
    system("cls");
}

void BaseCalculo::mostrar(){
    cout << "\t\t\t\t\t" << "REFERENCIA: ";
    mostrarIdReferencia();
    cout <<  "\t\t\t\t\t" << "AGENCIA: ";
    BuscarAgencia(_idAgencia);
    cout  << endl;
    cout <<  "\t\t\t\t\t" << "REGION: ";
    BuscarRegion(_idRegion);
    cout << endl;
    cout <<  "\t\t\t\t\t" << "TERMINAL DE GIRO: ";
    BuscarTerminal(_idGiro);
    cout << endl;

    cout <<  "\t\t\t\t\t" << "DIA ETA: ";   //TODO: HACER UNA FUNCION PARA Q MUESTRE SEMANA
    diaSemana(_diaETA);
    cout << endl;
    cout <<  "\t\t\t\t\t" << "DIA CUT OFF FIS: ";
    diaSemana(_diaCTF);
    cout << " " << _horaCTF << " HRS" << endl;
    cout <<  "\t\t\t\t\t" << "DIA CUT OFF DOC: ";
    diaSemana(_diaCTD);
    cout << " " << _horaCTD << " HRS" << endl;

    cout <<  "\t\t\t\t\t" << "DIAS QUE SE SUMAN A ETD: " << _calculoETD << endl;
    cout <<  "\t\t\t\t\t" << "DIAS QUE RESTAN PARA RECEP DEL CNT: " << _calculoETD << endl;

    cout <<  "\t\t\t\t\t" << "CUT OFF EN MISMA SEMANA QUE ETA: ";
    if ( _mismaSemana ) cout << "SI" << endl;
    else cout << "NO" << endl;

}

void BaseCalculo::mostrarIdReferencia(){
    for ( int i = 0 ; i < 3 ; i++){
        cout << _idReferencia[i] << " ";
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








