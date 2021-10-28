#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Buque.h"
#include "Terminal.h"

Buque::Buque(){
    _idBuque=0;
     strcpy(_nombreBuque,"NO SE INGRESO NOMBRE");
    strcpy(_banderaBuque, "NO SE INGRESO BANDERA");
//    _numeroViaje=0;
    _activo= true;



}
void Buque::setIdBuque(int NuevoId){
    _idBuque=NuevoId;
}

void Buque::setnombreBuque(char* NuevoNombre){
    strcpy(_nombreBuque,NuevoNombre);
}

void Buque::setBanderaBuque(char *NuevaBandera){
    strcpy(_banderaBuque,NuevaBandera);
}
/*
void Buque::setNumeroViaje(int NuevoNro){
    _numeroViaje=NuevoNro;
}*/

void Buque::setGiro(int NuevoGiro){
    _giro=NuevoGiro;
}

void Buque::setActivo(bool NuevoEstado){
    _activo=NuevoEstado;
}

int  Buque::getIdBuque(){
    return _idBuque;
}

char *Buque::getnombreBuque(){
    return _nombreBuque;
}

char *Buque::getBanderaBuque(){
    return _banderaBuque;
}
/*
int  Buque::getNumeroViaje(){
    return _numeroViaje;
}*/

int  Buque::getGiro(){
    return _giro;
}

bool Buque::getActivo(){
    return _activo;
}

void Buque::cargar(){

    cout<< "INGRESE EL ID DEL BUQUE: ";
    cin >> _idBuque;

    cout<< "INGRESE EL NOMBRE DEL BUQUE: ";
    cin.ignore();
    cin.getline(_nombreBuque,30);

    cout<< "INGRESE LA BANDERA DEL BUQUE: ";
    cin.getline(_banderaBuque,30);

   /* cout<< "INGRESE EL NUMERO DE VIAJE: ";
    cin >> _numeroViaje;*/

    cout<< "INGRESE ID TERMINAL: ";
    cin >> _giro;   /// Acá habría que agregar alguna validación que revise que el ID existe...

}

void Buque::mostrar(){
    cout<< "NUMERO DE ID BUQUE-:"<< "\t"<< _idBuque<<endl;
    cout<< "NOMBRE DEL BUQUE---:"<< "\t"<< _nombreBuque<<endl;
    cout<< "BANDERA------------:"<< "\t"<< _banderaBuque<<endl;
   /* cout<< "NUMERO DE VIAJE----:"<< "\t"<< _numeroViaje<<endl;*/

    cout<< "GIRO---------------:"<< "\t";
    buscarTerminal(_giro); /// Acá busca con el ID y trae (muestra) el nombre de la terminal...
    cout << endl;
}

bool Buque::grabarEnDisco(){
    FILE *p;
    p=fopen("Buques.dat","ab");
    if(p==NULL)
    {
        cout<< "No se pudo abrir el archivo";
        return false;
    }
    bool ok =  fwrite(this,sizeof(Buque),1,p);
    if (ok==true)  {
        cout<< "Registro guardado"<<endl;
    }
    else{
        cout<< "No se guardo el registro"<<endl;
    }
    fclose(p);

}


bool Buque::leerDeDisco(int pos) {

    FILE *p;
    p=fopen("Buques.dat","rb");
    if(p==NULL){
        cout<< "No se pudo abrir el archivo";
    return false;
    }

        fseek(p,sizeof(Buque)*pos,0);
        bool leyo=fread(this, sizeof(Buque), 1, p);
        fclose(p);
        return leyo;

}

//---------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES
void ListadoBuques() {

    FILE *p;
    Buque reg;
    p=fopen("Buques.dat","rb");
    if(p==NULL){
        cout<< "No se pudo abrir el archivo";
    return ;
    }

    while(fread(&reg,sizeof(Buque),1,p)==1){
        reg.mostrar();
        cout << endl;
    }

    fclose(p);
}

void buscarTerminal(int giro){
    int pos = 0;
    Terminal reg;

    while(reg.leerDeDisco(pos++)){
        if (giro == reg.getIdTerminal()){
        cout << reg.getNombreTerminal();
        }
    }
}
