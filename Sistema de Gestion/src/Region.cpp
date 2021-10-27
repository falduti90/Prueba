#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Region.h"

Region::Region(){
    _IdRegion=0;
    strcpy(_NombreRegion, "NO SE INGRESO EL NOMBRE");
    _Activo=true;

}
void    Region::setIdRegion(int NuevoID){
    _IdRegion=NuevoID;
    strin
}
void    Region::setNombreRegion(char *NuevoNombre){
    strcpy(_NombreRegion,NuevoNombre);
}
void    Region::setActivo(bool NuevoEstado){
    _Activo=NuevoEstado;
}
int     Region::getIdRegion(){
    return _IdRegion;
}
char   * Region::getNombreRegion(){
    return _NombreRegion;
}
bool    Region::getActivo(){
    return _Activo;
}
void    Region::Cargar(){

    cout<< "INGRESE EL NUMERO DE ID REGION:"<<endl;
    cin >> _IdRegion;

    cout<< "INGRESE  EL NOMBRE DE LA REGION : "<<endl;
    cin.ignore();
    cin.getline(_NombreRegion,30);



}
void    Region::Mostrar(){
    cout<< "NUMERO DE ID :"<<" "<< _IdRegion<< endl;
    cout<< "NOMBRE DE REGION :"<< " "<< _NombreRegion<<endl;

}
bool    Region::leerDeDisco(int pos){
        FILE *p;
        p=fopen("Region.dat","rb");
        if(p==NULL){
        cout<< "No se pudo abrir el archivo";
        return false;
    }

        fseek(p,sizeof(Region)*pos,0);
        bool leyo=fread(this, sizeof(Region), 1, p);
        fclose(p);
        return leyo;
}

bool    Region::grabarEnDisco(){
    FILE *p;
    p=fopen("Region.dat","ab");
    if(p==NULL)
    {
        cout<< "No se pudo abrir el archivo";
        return false;
    }
    bool ok=  fwrite(this,sizeof(Region),1,p);
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

void ListadoDeRegiones(){

    FILE *p;
    Region reg;
    p=fopen("Region.dat","rb");
    if(p==NULL){
        cout<< "No se pudo abrir el archivo";
    return ;
    }

    while(fread(&reg,sizeof(Region),1,p)==1){
        reg.Mostrar();

    }

    fclose(p);
}
