#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Terminal.h"
#include "Domicilio.h"

Terminal::Terminal(){
    _IdTerminal=0;
    strcpy(_NombreTerminal,"NO SE INGRESO NOMBRE DE TERMINAL");
    strcpy(_Email, "NO SE INGRESO UN E-MAIL");
    _GastosFijos=0;
    _Activo=true;


}
void    Terminal::setIdTerminal(int NuevoID )  {
    _IdTerminal=NuevoID;

}
void    Terminal::setNombreTerminal(char *NuevoNombre){
    strcpy(_NombreTerminal,NuevoNombre);

}
void    Terminal::setDireccion (Domicilio NuevaDir){
    _Direccion=NuevaDir;
}
void    Terminal::setEmail(char * NuevoEMail){

   strcpy (_Email,NuevoEMail);
}
void    Terminal::setGastosFijos(float NuevoGasto){
    _GastosFijos=NuevoGasto;
}
void    Terminal::setActivo(bool NuevoEstado){
    _Activo=NuevoEstado;
}
char *  Terminal::getNombreTerminal(){
    return _NombreTerminal;
}
Domicilio Terminal::getDireccion (){
    return _Direccion;
}

char *  Terminal::getEmail(){
    return _Email;
}
float   Terminal::getGastosFijos(){
    return _GastosFijos;
}
void    Terminal::cargar(){
    cout<< "INGRESE EL ID DE LA TERMINAL    :"<<endl;
    cin >> _IdTerminal;

    cout<< "INGRESE EL NOMBRE DE LA TERMINAL:"<<endl;
    cin >> _NombreTerminal;

    cout<< "INGRESE EL EMAIL DE LA TERMINAL :"<<endl;
    cin >> _Email;

    cout<< "INGRESE EL GASTO FIJO           :"<<endl;
    cin >> _GastosFijos;

    _Direccion.Cargar();

}
void    Terminal::mostrar(){

    cout<< "ID TERMINAL     :"<<"/"<<_IdTerminal<<endl;
    cout<< "NOMBRE TERMINAL :"<<"/"<<_NombreTerminal<<endl;
    cout<< "EMAIL           :"<<"/"<<_Email<<endl;
    cout<< "GASTOS FIJOS    "<<"/"<<_GastosFijos<<endl;
    _Direccion.Mostrar();



}
bool    Terminal::leerDeDisco(int pos){
        FILE *p;
        p=fopen("Terminal.dat","rb");
        if(p==NULL){
        cout<< "No se pudo abrir el archivo docentes";
        return false;
    }

        fseek(p,sizeof(Terminal)*pos,0);
        bool leyo=fread(this, sizeof(Terminal), 1, p);
        fclose(p);
        return leyo;
}
bool    Terminal::grabarEnDisco(){
    FILE *p;
    p=fopen("Terminal.dat","ab");
    if(p==NULL)
    {
        cout<< "No se pudo abrir el archivo docentes";
        return false;
    }
    bool ok=  fwrite(this,sizeof(Terminal),1,p);
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

void ListadoDeTerminales(){

    FILE *p;
    Terminal reg;
    p=fopen("Terminal.dat","rb");
    if(p==NULL){
        cout<< "No se pudo abrir el archivo docentes";
    return ;
    }

    while(fread(&reg,sizeof(Terminal),1,p)==1){
        reg.mostrar();

    }

    fclose(p);
}
