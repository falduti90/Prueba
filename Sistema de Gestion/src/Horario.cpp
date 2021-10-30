#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Horario.h"


Horario::Horario(){
    _hora = 0;
    _minutos = 0;

}
void Horario::setHora(int nuevaHora){
    _hora = nuevaHora;

}

void Horario::setMinutos(int nuevosMin){
    _minutos = nuevosMin;
}

int Horario::getHora(){
    return _hora;
}

int Horario::getMinutos(){
    return _minutos;
}

void Horario::cargar(){
    cout << "INGRESE LA HORA : ";
    cin >> _hora;
    cout << "INGRESE LOS MINUTOS : " ;
    cin >> _minutos;

}

void Horario::mostrar(){
    cout << "HORA: " << _hora << " - " << "MINUTOS: " << _minutos;
}

bool Horario::leerDeDisco(int pos){
    FILE *p;
    p = fopen("Horario.dat","rb");
    if ( p == NULL ){
    cout << "No se pudo abrir el archivo";
    return false;
    }

    fseek ( p , sizeof(Horario)*pos , 0 );
    bool leyo = fread( this, sizeof(Horario) , 1 , p );
    fclose(p);
    return leyo;
}

bool Horario::grabarEnDisco(){
    FILE *p;
    p = fopen("Horario.dat","ab");
    if( p == NULL ) {
        cout << "No se pudo abrir el archivo";
        return false;
    }
    bool ok =  fwrite(this,sizeof(Horario),1,p);
    if ( ok == true) {
        cout << "Registro guardado"<<endl;
    }
    else {
        cout << "No se guardo el registro"<<endl;
    }
    fclose(p);
    return ok;

}
