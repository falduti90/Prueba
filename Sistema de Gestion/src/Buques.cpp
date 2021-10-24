#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Buques.h"
#include "Terminal.h"

Buques::Buques(){
    _idBuque=0;
     strcpy(_nombreBuque,"NO SE INGRESO NOMBRE");
    strcpy(_banderaBuque, "NO SE INGRESO BANDERA");
    _numeroViaje=0;
    _activo= true;
    //cout<<



}
void Buques::setIdBuque(int NuevoId)
{
    _idBuque=NuevoId;
}
void Buques::setnombreBuque(char* NuevoNombre)
{
    strcpy(_nombreBuque,NuevoNombre);
}
void Buques::setBanderaBuque(char *NuevaBandera)
{
    strcpy(_banderaBuque,NuevaBandera);
}

void Buques::setNumeroViaje(int NuevoNro)
{
    _numeroViaje=NuevoNro;
}
void Buques::setGiro(Terminal NuevoGiro)
{
    _giro=NuevoGiro;
}
void Buques::setActivo(bool NuevoEstado)
{
    _activo=NuevoEstado;
}
int  Buques::getIdBuque()
{
    return _idBuque;
}
char *Buques::getnombreBuque()
{
    return _nombreBuque;
}
char *Buques::getBanderaBuque()
{
    return _banderaBuque;
}
int  Buques::getNumeroViaje()
{
    return _numeroViaje;
}
Terminal  Buques::getGiro()
{
    return _giro;
}
bool Buques::getActivo()
{
    return _activo;
}
void Buques::cargar()
{
    cout<< "INGRESE EL ID DEL BUQUE : "<<endl;
    cin >> _idBuque;

    cout<< "INGRESE EL NOMBRE DEL BUQUE :"<<endl;
    cin >> _nombreBuque;

    cout<< "INGRESE LA BANDERA DEL BUQUE :"<<endl;
    cin >> _banderaBuque;

    cout<< "INGRESE EL NUMERO DE VIAJE :"<<endl;
    cin >> _numeroViaje;

    // SE CARGA INFO DE TERMINAL
    _giro.cargar();



}
void Buques::mostrar()
{
    cout<< "NUMERO DE ID BUQUE-:"<< "/"<< _idBuque<<endl;
    cout<< "NOMBRE DEL BUQUE---:"<< "/"<< _nombreBuque<<endl;
    cout<< "BANDERA------------:"<< "/"<< _banderaBuque<<endl;
    cout<< "NUMERO DE VIAJE----:"<< "/"<< _numeroViaje<<endl;

    //SE MUESTRA INFO DE TERMINAL
    _giro.mostrar();

}
bool Buques::grabarEnDisco()
{
    FILE *p;
    p=fopen("Buque.dat","ab");
    if(p==NULL)
    {
        cout<< "No se pudo abrir el archivo docentes";
        return false;
    }
    bool ok=  fwrite(this,sizeof(Buques),1,p);
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
bool Buques::leerDeDisco(int pos) {

    FILE *p;
    p=fopen("Buque.dat","rb");
    if(p==NULL){
        cout<< "No se pudo abrir el archivo docentes";
    return false;
    }

        fseek(p,sizeof(Buques)*pos,0);
        bool leyo=fread(this, sizeof(Buques), 1, p);
        fclose(p);
        return leyo;

}
//---------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES
void ListadoBuques() {



    FILE *p;
    Buques reg;
    p=fopen("Buque.dat","rb");
    if(p==NULL){
        cout<< "No se pudo abrir el archivo docentes";
    return ;
    }

    while(fread(&reg,sizeof(Buques),1,p)==1){
        reg.mostrar();

    }

    fclose(p);
}
