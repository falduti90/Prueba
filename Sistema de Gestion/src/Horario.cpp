#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Horario.h"


Horario::Horario(){
    _Hora=0;
    _Minutos=0;

}
void    Horario::setHora(int NuevaHora){
    _Hora=NuevaHora;

}
void    Horario::setMinutos(int NuevosMin){
    _Minutos=NuevosMin;
}
int     Horario::getHora(){
    return _Hora;
}
int     Horario::getMinutos(){
    return _Minutos;
}
void    Horario::Cargar(){
    cout<< "INGRESE LA HORA :"<<endl;
    cin >> _Hora;
    cout<< "INGRESE LOS MINUTOS :"<<endl;
    cin >> _Minutos;

}
void    Horario::Mostrar(){
    cout<<"HORA :"<< " "<< _Hora<< " " << "MINUTOS :"<< "/" << _Minutos;
}
bool    Horario::LeerDeDisco(int pos){
     FILE *p;
        p=fopen("Horario.dat","rb");
        if(p==NULL){
        cout<< "No se pudo abrir el archivo";
        return false;
    }

        fseek(p,sizeof(Horario)*pos,0);
        bool leyo=fread(this, sizeof(Horario), 1, p);
        fclose(p);
        return leyo;


}
bool    Horario::GrabarEnDisco(){
        FILE *p;
    p=fopen("Horario.dat","ab");
    if(p==NULL)
    {
        cout<< "No se pudo abrir el archivo";
        return false;
    }
    bool ok=  fwrite(this,sizeof(Horario),1,p);
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
