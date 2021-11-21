#include<iostream>
using namespace std;
#include<clocale>
#include "BaseCalculo.h"
#include "Cronograma.h"
#include "Region.h"
#include "Terminal.h"
#include "Agencia.h"
#include "Buque.h"



/// VALIDACIONES AL CARGAR

bool validaNroSemana( int ns ){
    while ( ns < 0 || ns > 53){
        cout << endl << "NUMERO DE SEMANA INVALIDO." << endl << endl;
        return false;
    }
    return true;
}

bool validaIdAgencia( int idAg ){
    Agencia reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++)){
        if ( reg.getIdAgencia() == idAg) return true;
    }
    cout << endl << "NO SE ENCUENTRA AGENCIA CON ESE ID." << endl << endl;
    return false;
}

bool validaIdRegion( int idReg ){
    Region reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++)){
        if ( reg.getIdRegion() == idReg) return true;
    }
    cout << endl << "NO SE ENCUENTRA REGION CON ESE ID." << endl << endl;
    return false;
}

bool validaIdBuque( int idBuq ){
    Buque reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++)){
        if ( reg.getIdBuque() == idBuq) return true;
    }
    cout << endl << "NO SE ENCUENTRA BUQUE CON ESE ID." << endl << endl;
    return false;
}


bool validaIdTerminal( int idTerm ){
    Terminal reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++)){
        if ( reg.getIdTerminal() == idTerm) return true;
    }
    cout << endl << "NO SE ENCUENTRA TERMINAL CON ESE ID." << endl << endl;
    return false;
}


bool validaDiaSemana( int ds ){
    while ( ds < 0 || ds > 6){
        cout << endl << "NUMERO DE SEMANA INVALIDO." << endl << endl;
        return false;
    }
    return true;
}


bool validaHora( int hr ){
    while ( hr < 0 || hr > 23){
        cout << endl << "HORA INVALIDA." << endl << endl;
        return false;
    }
    return true;
}

bool validaPositivo( int num ){
        while ( num < 0){
        cout << endl << "NO PUEDE INGRESAR UN VALOR NEGATIVO." << endl << endl;
        return false;
    }
    return true;
}

