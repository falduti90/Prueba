#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <string.h>
#include "Fecha.h"

Fecha::Fecha(){

}

Fecha::Fecha(int dia, int mes, int anio, int numSemana, int numDia){
    setDia(dia);
    setMes(mes);
    setAnio(anio);
    setNumeroSemana(numSemana);
    setNumDia(numDia);


}

void Fecha::mostrar(){

    if (getDia()< 10){
        if (getMes() < 10){
            cout << "0" << getDia() << "/0" << getMes() << "/" << getAnio();
        }
        else {
            cout << "0" << getDia() << "/" << getMes() << "/" << getAnio();
        }
    }

    else {
        if (getMes() < 10){
            cout << getDia() << "/0" << getMes() << "/" << getAnio();
        }
        else{
            cout << getDia() << "/" << getMes() << "/" << getAnio();
        }
    }

}

bool Fecha::grabarEnDisco(){
    bool escribio;
    FILE *p = fopen("calendario2021.dat", "ab");
    if (p == NULL){
        cout << endl << " >>No se pudo abrir el archivo";
    }
    escribio = fwrite(this, sizeof(Fecha), 1, p);
    fclose(p);
    return escribio;
}
bool Fecha::leerDeDisco(int pos){
    bool leyo;
    FILE *p = fopen("calendario2021.dat", "rb");
    if (p == NULL){
        cout << endl << " >>No se pudo abrir el archivo";
    }
    fseek(p, sizeof(Fecha)* pos, SEEK_SET);
    leyo = fread(this, sizeof(Fecha), 1, p);
    fclose(p);
    return leyo;
}








//---------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES

/*void ListadoDeFechas(){

    FILE *p;
    Fecha reg;
    p=fopen("Fechas.dat","rb");
    if(p==NULL){
        cout<< "No se pudo abrir el archivo docentes";
    return ;
    }

    while(fread(&reg,sizeof(Fecha),1,p)==1){
        reg.Mostrar();

    }

    fclose(p);
}*/
