#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Region.h"

Region::Region(){
    _IdRegion=0;
    strcpy(_NombreRegion, "NO SE INGRESO EL NOMBRE");

}
void    Region::setIdRegion(int NuevoID){}
void    Region::setNombreRegion(char *NuevoNombre){}
void    Region::setActivo(bool NuevoEstado){}
int     Region::getIdRegion(){}
char    Region::*getNombreRegion(){}
bool    Region::getActivo(){}
void    Region::Cargar(){}
void    Region::Mostrar(){}
bool    Region::leerDeDisco(int pos){}
bool    Region::grabarEnDisco(){}
