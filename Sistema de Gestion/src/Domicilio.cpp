#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Domicilio.h"

Domicilio::Domicilio() {
    _Altura=0;
    strcpy(_Calle,"NO SE INGRESO EL NOMBRE DE LA CALLE");
}

void  Domicilio::setCalle(char * NuevaCalle) {
    strcpy(_Calle,NuevaCalle);
}
void  Domicilio::setAltura(int NuevaAltura) {
    _Altura=NuevaAltura;
}
char* Domicilio::getCalle() {
    return _
}
int   Domicilio::getAltura() {}
void  Domicilio::Cargar() {}
void  Domicilio::Mostrar() {}
bool  Domicilio::leerDeDisco(int pos) {}
bool  Domicilio::grabarEnDisco() {}
