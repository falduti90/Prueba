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

void  Domicilio::setCalle(char *NuevaCalle) {
    strcpy(_Calle,NuevaCalle);
}

void  Domicilio::setAltura(int NuevaAltura) {
    _Altura=NuevaAltura;
}

void  Domicilio::setLocalidad(char *NuevaLocalidad) {
    strcpy(_Localidad,NuevaLocalidad);
}


char* Domicilio::getCalle() {
    return _Calle;
}

int   Domicilio::getAltura() {
    return _Altura;
}

char* Domicilio::getLocalidad() {
    return _Localidad;
}

void  Domicilio::Cargar() {

    cout<<"INGRESE EL NOMBRE DE CALLE:  ";
    cin.ignore();
    cin.getline(_Calle,30);
    cout<<"INGRESE LA ALTURA DE LA CALLE:  ";
    cin>> _Altura;
    cout<<"INGRESE LA LOCALIDAD:  ";
    cin.ignore();
    cin.getline(_Localidad,30);
}

void  Domicilio::Mostrar() {
    cout<< "DOMICILIO       :"<<"\t"<<_Calle<<endl;
    cout<< "ALTURA          :"<<"\t"<<_Altura<<endl;
    cout<< "LOCALIDAD       :"<<"\t"<<_Localidad<<endl;
}

bool  Domicilio::leerDeDisco(int pos) {
        FILE *p;
        p=fopen("Domicilios.dat","rb");
        if(p==NULL){
        cout<< "No se pudo abrir el archivo";
        return false;
        }

        fseek(p,sizeof(Domicilio)*pos,0);
        bool leyo=fread(this, sizeof(Domicilio), 1, p);
        fclose(p);
        return leyo;
}

bool  Domicilio::grabarEnDisco() {
    FILE *p;
    p=fopen("Domicilios.dat","ab");
    if(p==NULL)
    {
        cout<< "No se pudo abrir el archivo";
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
    p=fopen("Domicilios.dat","rb");
    if(p==NULL){
        cout<< "No se pudo abrir el archivo";
    return ;
    }

    while(fread(&reg,sizeof(Domicilio),1,p)==1){
        reg.Mostrar();

    }

    fclose(p);
}
