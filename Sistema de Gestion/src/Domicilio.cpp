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
    return _Calle;
}
int   Domicilio::getAltura() {
    return _Altura;
}
void  Domicilio::Cargar() {

    cout<<"INGRESE EL NOMBRE DE CALLE    :"<<endl;
    cin>> _Calle;
    cout<<"INGRESE LA ALTURA DE LA CALLE :"<<endl;
    cin>> _Altura;
}
void  Domicilio::Mostrar() {
    cout<< "DOMICILIO :"<<"/"<<_Calle<<endl;
    cout<< "ALTURA    :"<<"/"<<_Altura<<endl;
}
bool  Domicilio::leerDeDisco(int pos) {
        FILE *p;
        p=fopen("Domicilio.dat","rb");
        if(p==NULL){
        cout<< "No se pudo abrir el archivo docentes";
        return false;
    }

        fseek(p,sizeof(Domicilio)*pos,0);
        bool leyo=fread(this, sizeof(Domicilio), 1, p);
        fclose(p);
        return leyo;
}
bool  Domicilio::grabarEnDisco() {
        FILE *p;
    p=fopen("Domicilio.dat","ab");
    if(p==NULL)
    {
        cout<< "No se pudo abrir el archivo docentes";
        return false;
    }
    bool ok=  fwrite(this,sizeof(Domicilio),1,p);
    if (ok==true)
    {
        cout<< "Registro guardado"<<endl;
    }
    else
    {
        cout<< "No se guardo el registro"<<endl;
    }
    fclose(p);
}

//-------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES

void ListadoDeDomicilios(){

    FILE *p;
    Domicilio reg;
    p=fopen("Domicilio.dat","rb");
    if(p==NULL){
        cout<< "No se pudo abrir el archivo docentes";
    return ;
    }

    while(fread(&reg,sizeof(Domicilio),1,p)==1){
        reg.Mostrar();

    }

    fclose(p);
}
