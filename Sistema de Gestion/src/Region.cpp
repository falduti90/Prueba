#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Region.h"
#include "../Validaciones.h"

Region::Region(){
    _idRegion = 0;
    strcpy( _codRegion , "VACIO" );
    strcpy( _nombreRegion , "NO SE INGRESO EL NOMBRE" );
    _activo = true;

}

void Region::setIdRegion(int nuevoID){
    _idRegion = nuevoID;
}

void Region::setNombreRegion(char *nuevoNombre){
    strcpy( _nombreRegion , nuevoNombre );
}

void Region::setCodRegion(char *codRegion){
    strcpy( _codRegion , codRegion );
}

void Region::setActivo(bool nuevoEstado){
    _activo = nuevoEstado;
}

int  Region::getIdRegion(){
    return _idRegion;
}

char *Region::getNombreRegion(){
    return _nombreRegion;
}

char *Region::getCodRegion(){
    return _codRegion;
}

bool Region::getActivo(){
    return _activo;
}

void Region::cargar(){
    bool aux;

    do{
        aux = false;
        cout<< "INGRESE EL ID DE LA REGION: ";
        cin>> _idRegion;
        if (validaIdRegion ( _idRegion)){
                aux = true;
                cout << endl << "YA EXISTE UNA REGION CON ESE ID." << endl << endl;
        }
        if (_idRegion <= 0 ){
                aux = true;
                cout << endl << "HA INGRESADO UN ID INVALIDO." << endl << endl;
        }
    } while ( aux );


    cout<< "INGRESE EL CODIGO DE LA REGION: ";  //TODO : Validación para que no igrese mas de 9 letras?
    cin.ignore();
    cin.getline( _codRegion , 9 );
    while (validaCodigoRegion ( _codRegion)){
            cout << endl << "YA EXISTE UNA REGION CON ESE CODIGO." << endl << endl;
            cout<< "INGRESE EL CODIGO DE LA REGION: ";
            cin.getline( _codRegion , 99 );
    }

    cout<< "INGRESE EL NOMBRE DE LA REGION: ";
    cin.getline( _nombreRegion , 99 );
    while (validaNombreRegion ( _nombreRegion)){
            cout << endl << "YA EXISTE UNA REGION CON ESE NOMBRE." << endl << endl;
            cout<< "INGRESE EL NOMBRE DE LA REGION: ";
            cin.getline( _nombreRegion , 99 );
    }

    cout << endl << endl;
    system("pause");
    system("cls");
}

void Region::mostrar(){
    if(_activo){
        cout<<  "\t\t\t\t\t" << "NUMERO DE ID     : "<< _idRegion << endl;
        cout<<  "\t\t\t\t\t" << "CODIGO DE REGION : "<< _codRegion << endl;
        cout<<  "\t\t\t\t\t" << "NOMBRE DE REGION : "<< _nombreRegion << endl;
    }
}

bool Region::leerDeDisco(int pos){
    FILE *p;
    p = fopen("Regiones.dat","rb");
    if ( p == NULL ){
    cout << "No se pudo abrir el archivo";
    return false;
    }

    fseek ( p , sizeof(Region)*pos , 0);
    bool leyo = fread ( this , sizeof(Region) , 1 , p);
    fclose(p);
    return leyo;
}

bool Region::grabarEnDisco(){
    FILE *p;
    p = fopen("Regiones.dat","ab");
    if ( p == NULL ) {
        cout << "No se pudo abrir el archivo";
        return false;
    }
    bool ok =  fwrite(this,sizeof(Region),1,p);
    if ( ok == true ) {
        cout << "Registro guardado"<<endl;
    }
    else {
        cout << "No se guardo el registro"<<endl;
    }
    fclose(p);
    return ok;

}


//---------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES

void BuscarRegion(int idRegion){
    int pos = 0;
    Region reg;

    while(reg.leerDeDisco(pos++)){
        if (idRegion == reg.getIdRegion()){
        cout << reg.getCodRegion();
        }
    }
}

char *BuscarRegion(int idRegion, bool b){
    int pos = 0;
    Region reg;

    while(reg.leerDeDisco(pos++)){
        if (idRegion == reg.getIdRegion()){
        return reg.getNombreRegion();
        }
    }
}

bool BorrarRegistroRegion(){

    Region reg;
    int IdRegion, pos;

    cout << "\t\t\t\t\t\t***ELIMINAR REGISTRO***" << endl << endl;
    cout << "\t\t\t\t*******************************************" << endl << endl;
    cout << "\t\t\t\t\tINGRESE ID DE REGION: ";
    cin  >> IdRegion;

    pos = RegionAborrar(IdRegion);

    if(pos == -1){
        cout << endl << endl,
        cout << "\t\t\t\t\tNO EXISTE EL ID INGRESADO." << endl << endl,
        cout << "\t\t\t\t\t" << system("pause");
        system("cls");
        return false;
    }
    reg.leerDeDisco(pos);
    reg.setActivo(false);

    if(reg.ModificarEnDiscoRegion(pos)){
        cout << "\t\t\t\t\t" << "REGISTRO BORRADO.";
        cout << endl << endl,
        cout << "\t\t\t\t\t" << system("pause");
        system("cls");
        return true;
    }
    else{
        cout << endl << endl;
        cout << "\t\t\t\t\tNO SE PUDO ABRIR EL ARCHIVO." << endl;
        return false;
    }
    cout << endl << endl,
    cout << "\t\t\t\t\t" << system("pause");
}

int RegionAborrar(int idRegion){

    Region reg;
    int pos = 0;

    while(reg.leerDeDisco(pos)){
        if (idRegion == reg.getIdRegion()){
            return pos;
        }
        pos++;
    }
    return -1;
}

bool Region::ModificarEnDiscoRegion(int pos){

    FILE *p;
    p = fopen("Regiones.dat","rb+");
    if ( p == NULL ){
        return false;
    }
    fseek(p , sizeof(Region)*pos , 0 );
    bool ok = fwrite(this, sizeof(Region), 1, p);
    fclose(p);
    return ok;
}

