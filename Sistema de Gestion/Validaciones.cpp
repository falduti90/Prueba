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
    return false;
}

bool validaIdRegion( int idReg ){
    Region reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++)){
        if ( reg.getIdRegion() == idReg) return true;
    }
    return false;
}

bool validaIdBuque( int idBuq ){
    Buque reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++)){
        if ( reg.getIdBuque() == idBuq) return true;
    }
    return false;
}


bool validaIdTerminal( int idTerm ){
    Terminal reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++)){
        if ( reg.getIdTerminal() == idTerm) return true;
    }
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

bool validaNombreAgencia ( char *nomAgencia){
    Agencia reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++)){
        if (strcmp( reg.getNombreAgencia() , nomAgencia ) == 0) return true;
        }

    return false;
}

bool validaNombreBuque ( char *nomBuque){
    Buque reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++)){
        if (strcmp( reg.getnombreBuque() , nomBuque ) == 0) return true;
        }

    return false;
}

bool validaCodigoRegion ( char *codRegion){
    Region reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++)){
        if (strcmp( reg.getCodRegion() , codRegion ) == 0) return true;
        }

    return false;
}


bool validaNombreRegion ( char *nomRegion){
    Region reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++)){
        if (strcmp( reg.getNombreRegion() , nomRegion ) == 0) return true;
        }

    return false;
}

bool validaNombreTerminal ( char *nomTerm){
    Terminal reg;
    int pos = 0;
    while (reg.leerDeDisco(pos++)){
        if (strcmp( reg.getNombreTerminal() , nomTerm ) == 0) return true;
        }

    return false;
}
