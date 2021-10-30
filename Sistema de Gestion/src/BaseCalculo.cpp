#include<iostream>
using namespace std;
#include<clocale>
#include "BaseCalculo.h"

BaseCalculo::BaseCalculo(){
    //ctor
}


void BaseCalculo::setidAgencia ( int idAgencia ){
    _idAgencia = idAgencia;
}

void BaseCalculo::setidRegion ( int idRegion ){
    _idRegion = idRegion;

}

void BaseCalculo::setidGiro ( int idGiro ){
    _idGiro = idGiro;
}

void BaseCalculo::setCalculoETA ( int diaSem ){
    _calculoETA = diaSem;
}

void BaseCalculo::BaseCalculo::setCalculoETD ( int sumaDias ){
    _calculoETD = _calculoETA + sumaDias;  // TODO: Habría que ponerle validación para que no siga sumando si excede días de semana
}

void BaseCalculo::setCalculoCTF ( int diaSem ){
    _calculoCTF = diaSem;   ///sERÍA FECHA DE LA SEMANA ANTERIOR...
}

void BaseCalculo::setHoraCTF ( int hora ){
    _horaCTF = hora;
}

void BaseCalculo::setCalculoCTD ( int diaSem ){
    _calculoCTD = diaSem;
}

void BaseCalculo::setHoraCTD ( int hora ){
    _horaCTD = hora;
}

void BaseCalculo::setCalculoRecepcionCnt ( int restaDias ){
//    _calculoRecepcionCnt = _calculoETA ||| _CalculoCOF - restaDias;

// TODO: Habría que ponerle validación para que no siga restando si terminó días de semana
// también si depende de ETA o COF
}

int BaseCalculo::getidAgencia (){
    return _idAgencia;
}

int BaseCalculo::getidRegion (){
    return _idRegion;
}

int BaseCalculo::getidGiro (){
    return _idGiro;

}

int BaseCalculo::getCalculoETA (){
    return _calculoETA;
}

int BaseCalculo::getCalculoETD (){
    return _calculoETD;
}

int BaseCalculo::getCalculoCTF (){
    return _calculoCTF;
}

int BaseCalculo::getHoraCTF (){
    return _horaCTF;
}

int BaseCalculo::getCalculoCTD (){
    return _calculoCTD;
}

int BaseCalculo::getHoraCTD (){
    return _horaCTD;
}

int BaseCalculo::getCalculoRecepcionCnt (){
    return _calculoRecepcionCnt;
}

void BaseCalculo::cargar(){

}

void BaseCalculo::mostrar(){

}

bool BaseCalculo::leerDeDisco(int pos){

}

bool BaseCalculo::grabarEnDisco(){

}

bool BaseCalculo::grabarEnDisco(int){

}


