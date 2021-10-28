#include <iostream>
using namespace std;
#include "Cronograma.h"
#include "Fecha.h"
#include "Buque.h"
#include "Agencia.h"
#include <cstdlib>
#include <cstring>
#include <cstdio>



/*Cronograma::Cronograma(){
        strcpy(_idCronograma,"IDCRONOGRAMA");
        _activo = true;
}*/


void Cronograma::setIdCronograma(char *){

}

void Cronograma::setNumSemana(int n){
    _numSemana = n;

}

void Cronograma::setFechaRecepcionCnt(Fecha f){
    _FechaRecepcionCnt = f;
}

void Cronograma::setFechaETA(Fecha f){
    _FechaETA = f;

}

void Cronograma::setFechaETD(Fecha f){
        _FechaETD = f;
}

void Cronograma::setFechaCutoffFisico(Fecha f){
        _FechacutoffFisico = f;
}

void Cronograma::setFechaCutoffDoc(Fecha f){
        _FechacutoffDoc = f;
}

void Cronograma::setActivo(bool){

}

char *Cronograma::getIdCronograma(){
    return _idCronograma;
}

Fecha Cronograma::getFechaRecepcionCnt(){
    return _FechaRecepcionCnt;
}

Fecha Cronograma::getFechaETA(){
    return _FechaETA;
}

Fecha Cronograma::getFechaETD(){
    return _FechaETD;
}

Fecha Cronograma::getFechaCutoffFisico(){
    return _FechacutoffFisico;
}

Fecha Cronograma::getFechaCutoffDoc(){
    return _FechacutoffDoc;
}

bool Cronograma::getActivo(){
    return _activo;
}

void Cronograma::cargar(){

    int dia, mes, anio;
    Fecha obj;

    cout<< "INGRESE ID CRONOGRAMA: ";  //armar que se concatene agencia + terminal
    cin.ignore();
    cin.getline(_idCronograma,49);

    cout << "INGRESE ID AGENCIA: ";
    cin >> _idAgencia;

    cout << "INGRESE ID BUQUE: ";
    cin >> _idBuque;

    cout << "INGRESE NUMERO DE VIAJE: ";
    cin >> _numeroViaje;

    cout << "INGRESE FECHAS: " << endl;
    cout << "ETA: ";
    cin >> dia >> mes >> anio;
    obj = buscarEnCalendario(dia, mes, anio);
    setFechaETA(obj);
    setNumSemana(obj.getNumeroSemana());
    cout << "ETD: ";
    cin >> dia >> mes >> anio;
    obj = buscarEnCalendario(dia, mes, anio);
    setFechaETD(obj);
    cout << "CUT OFF FISICO: ";
    cin >> dia >> mes >> anio;
    obj = buscarEnCalendario(dia, mes, anio);
    setFechaCutoffFisico(obj);
    cout << "CUT OFF DOCUMENTAL: ";
    cin >> dia >> mes >> anio;
    obj = buscarEnCalendario(dia, mes, anio);
    setFechaCutoffDoc(obj);
    cout << "INICIO DE RECEPCION: ";
    cin >> dia >> mes >> anio;
    obj = buscarEnCalendario(dia, mes, anio);
    setFechaRecepcionCnt(obj);

}

void Cronograma::mostrar(){

    cout << _idCronograma << ", ";
    buscarAgencia(_idAgencia);
    cout << ", ";
    buscarBuque(_idBuque);
    cout << ", ";
    cout << _numeroViaje << ", ";
    getFechaETD().mostrar();
    cout << ", ";
    getFechaETA().mostrar();
    cout << ", ";
    getFechaCutoffDoc().mostrar();
    cout << ", ";
    getFechaCutoffFisico().mostrar();
    cout << ", ";
    getFechaRecepcionCnt().mostrar();
}

bool Cronograma::leerDeDisco(int pos){
    FILE *p;
    p=fopen("Cronograma.dat","rb");
    if(p==NULL){
        cout<< "No se pudo abrir el archivo";
    return false;
    }

        fseek(p,sizeof(Cronograma)*pos,0);
        bool leyo=fread(this, sizeof(Cronograma), 1, p);
        fclose(p);
        return leyo;

}

bool Cronograma::grabarEnDisco(){
    FILE *p;
    p=fopen("Cronograma.dat","ab");
    if(p==NULL)
    {
        cout<< "No se pudo abrir el archivo";
        return false;
    }
    bool ok =  fwrite(this,sizeof(Cronograma),1,p);
    if (ok==true)  {
        cout<< "Registro guardado"<<endl;
    }
    else{
        cout<< "No se guardo el registro"<<endl;
    }
    fclose(p);
}

//---------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES
void ListadoCronograma() {

    FILE *p;
    Cronograma reg;
   p=fopen("Cronograma.dat","rb");
    if(p==NULL){
        cout<< "No se pudo abrir el archivo";
    return ;
    }

    while(fread(&reg,sizeof(Cronograma),1,p)==1){
        reg.mostrar();
        cout << endl;
    }

    fclose(p);
}


Fecha buscarEnCalendario(int dia, int mes, int anio){
    Fecha f;
    int i = 0;
    while (f.leerDeDisco(i)){
        if (f.getDia() == dia && f.getMes() == mes && f.getAnio() == anio){
            return f;
        }
        i++;
    }

}

void buscarBuque(int idBuque){
    int pos = 0;
    Buque reg;

    while(reg.leerDeDisco(pos++)){
        if (idBuque == reg.getIdBuque()){
        cout << reg.getnombreBuque();
        }
    }
}

void buscarAgencia(int idAgencia){
    int pos = 0;
    Agencia reg;

    while(reg.leerDeDisco(pos++)){
        if (idAgencia == reg.getIdAgencia()){
        cout << reg.getNombreAgencia();
        }
    }
}

