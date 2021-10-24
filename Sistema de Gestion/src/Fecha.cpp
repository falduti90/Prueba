#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Fecha.h"


Fecha::Fecha(){
    _Dia=0;
    _Mes=0;
    _Anio=0;
}
void Fecha::setDia(int NuevoDia){
    _Dia=NuevoDia;
}
void Fecha::setMes(int NuevoMes){
    _Mes=NuevoMes;
}
void Fecha::setAnio(int NuevoAnio){
    _Anio=NuevoAnio;
}
void Fecha::setNumeroSemana(int NuevaSemana){
// COMPLETAR
}
void Fecha::setActivo(bool NuevoEstado){
    _Activo;
}
int  Fecha::getDia(){
    return _Dia;
}
int  Fecha::getMes(){
    return _Mes;
}
int  Fecha::getAnio(){
   return  _Anio;
}
int  Fecha::getNumeroSemana(){
// COMPLETAR

}
bool Fecha::getActivo(){
    return  _Activo;
}
void Fecha::Cargar(){
    int dia,mes,anio;
    int vec[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    bool DiaOk,MesOk,AnioOk;
    DiaOk=MesOk=AnioOk=false;


    cout<< "INGRESE EL DIA  :"<<endl;
    cin >> dia;

    cout<< "INGRESE EL MES  :"<<endl;
    cin >> mes;

    cout<< "INGRESE EL ANIO :"<<endl;
    cin >> anio;

    if(mes>0 && mes<=12)
    {
        MesOk=true;
        if(dia>0 && dia <= vec[mes-1])
        {
            DiaOk=true;

        }
        if(anio>0){
            AnioOk=true;
        }

    }

   if(DiaOk && MesOk && AnioOk ){
     _Dia=dia;
     _Mes= mes;
     _Anio=anio;

   }
   else{
    cout<< "LA FECHA INGRESADA ES INCORRECTA"<<endl;
   }




}
void Fecha::Mostrar(){
    cout<< "FECHA  :"<<endl;
    cout<< _Dia<<"/"<<_Mes<< "/"<<_Anio<<endl;
}
bool Fecha::leerDeDisco(int pos){
        FILE *p;
        p=fopen("Fecha.dat","rb");
        if(p==NULL){
        cout<< "No se pudo abrir el archivo docentes";
        return false;
    }

        fseek(p,sizeof(Fecha)*pos,0);
        bool leyo=fread(this, sizeof(Fecha), 1, p);
        fclose(p);
        return leyo;

}
bool Fecha::grabarEnDisco(){
    FILE *p;
    p=fopen("Fecha.dat","ab");
    if(p==NULL)
    {
        cout<< "No se pudo abrir el archivo docentes";
        return false;
    }
    bool ok=  fwrite(this,sizeof(Fecha),1,p);
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


//---------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES

void ListadoDeFechas(){

    FILE *p;
    Fecha reg;
    p=fopen("Fecha.dat","rb");
    if(p==NULL){
        cout<< "No se pudo abrir el archivo docentes";
    return ;
    }

    while(fread(&reg,sizeof(Fecha),1,p)==1){
        reg.Mostrar();

    }

    fclose(p);
}
