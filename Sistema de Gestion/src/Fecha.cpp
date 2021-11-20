#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <string.h>
#include "Fecha.h"

Fecha::Fecha(){
    setDia(1);
    setMes(1);
    setAnio(1111);
}

Fecha::Fecha(int dia, int mes, int anio){
    setDia(dia);
    setMes(mes);
    setAnio(anio);
    setDiasDelmes();
    int numDia = dia;
    //cout << endl << "Num dia antes: " << numDia;
    for (int i=0; i<mes-1;i++){
        numDia += _diasDelMes [i];
        //cout << endl << "Num dia adentro: " << numDia;
    }
    //cout << endl << "Num dia despues: " << numDia;
    setNumDia(numDia);
    int numSemana = (numDia / 7) + 1;
    setNumeroSemana(numSemana);
}

void Fecha::setCalendario(int dia, int mes, int anio){
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}

/*Fecha::Fecha(int dia, int mes, int anio, int numSemana, int numDia){
    setDia(dia);
    setMes(mes);
    setAnio(anio);
    setNumeroSemana(numSemana);
    setNumDia(numDia);

}*/

void Fecha::setDiasDelmes(){
    if (Bisiesto(_anio)){
        _diasDelMes[1] = 29;
    }

}

void Fecha::setDia(int dia){
    _dia = dia;
}

void Fecha::setMes (int mes){
    _mes = mes;
}

void Fecha::setAnio (int anio){
    _anio = anio;
}

void Fecha::setNumeroSemana (int numSemana) {
    _numeroSemana = numSemana;
}

void Fecha::setNumDia (int numDia){
    _numDia = numDia;
}

int *Fecha::getDiasDelmes(){
    return _diasDelMes;
}

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

int Fecha::getNumeroSemana() {
    return _numeroSemana;
}

int Fecha::getNumDia(){
    return _numDia;
}


void Fecha::mostrar(){

    if (getAnio() ==(1111)){
    cout << "   ---   ";
    return;
    }

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
    if ( p == NULL){
        cout << endl << " >>No se pudo abrir el archivo";
    }

    fseek ( p, sizeof(Fecha)* pos , SEEK_SET );
    leyo = fread( this , sizeof(Fecha) , 1 , p );
    fclose(p);
    return leyo;
}

//-------------Sobrecarga de operadores-------------------------

bool Fecha::operator ==(int anio){
 if(_anio!=anio)return false;
 return true;
}


bool Fecha::operator ==(Fecha aux){
 if(_dia!=aux._dia)return false;
 if(_mes!=aux._mes)return false;
 if(_anio!=aux._anio)return false;
 return true;
 }

bool Fecha::operator !=(Fecha aux){
 if(_dia==aux._dia && _mes==aux._mes && _anio== aux._anio) return false;
 return true;
 }

bool Fecha::operator >=(Fecha aux){
 if (_anio > aux._anio) return true;
 if (_anio < aux._anio) return false;
 if (_mes  > aux._mes) return true;
 if (_mes  < aux._mes) return false;
 if (_dia  > aux._dia) return true;
 if (_dia == aux._dia) return true;
 return false;
 }

 bool Fecha::operator >(Fecha aux){
 if (_anio > aux._anio) return true;
 if (_anio < aux._anio) return false;
 if (_mes  > aux._mes) return true;
 if (_mes  < aux._mes) return false;
 if (_dia  > aux._dia) return true;
 return false;
 }

 bool Fecha::operator <(Fecha aux){
 if (_anio < aux._anio) return true;
 if (_anio > aux._anio) return false;
 if (_mes < aux._mes) return true;
 if (_mes > aux._mes) return false;
 if (_dia < aux._dia) return true;
 return false;

 }

/*
bool Fecha::operator + (int aux){
    Fecha f(_dia+aux,_mes , _anio);
    return f;

 }*/

 Fecha Fecha::operator += (int aux){
     int diasMes = CalcularDiasMes (_mes, _anio);

        if (_dia + aux > diasMes && _mes < 12) {
            Fecha f(_dia+aux-diasMes , _mes+1 , _anio);
            return f;
        }
        if (_dia + aux > diasMes && _mes == 12) {
                Fecha f(_dia+aux-diasMes , 1 , _anio+1);
                return f;
        }

        Fecha f(_dia+aux,_mes ,_anio);
        return f;
 }

 Fecha Fecha::operator -= (int aux){
     int diasMes = CalcularDiasMes (_mes-1, _anio);

        if (_dia - aux < 1 && _mes > 1) {
            Fecha f(diasMes+_dia - aux , _mes-1 , _anio);
            return f;
        }
        if (_dia - aux < 1 && _mes == 1) {
                Fecha f(diasMes +_dia - aux , 1 , _anio-1);
                return f;
        }

    Fecha f(_dia-aux,_mes , _anio);
    return f;

 }


 /*
 bool Fecha::operator -= (int aux){
    if (_dia > 1){
    _dia = _dia - aux;
    }
    return true;

 }*/

 bool Fecha::operator = (Fecha aux){
    setDia(aux.getDia());
    setMes(aux.getMes());
    setAnio(aux.getAnio());
    return true;

 }


bool Bisiesto(int a){
    if(a%4 != 0) return false;
    else if(a%100 != 0) return true;
    else if(a%400 != 0) return false;
    return true;


}


int CalcularDiasMes (int mes, int a){
    int meses31[7]{1,3,5,7,8,10,12};

    for (int i = 0 ; i <= 7 ; i++){
        if (mes == meses31[i]){
        return 31;
        }
    }
    if (mes == 2){
        if (Bisiesto(a))return 29;
        return 28;
    }
    return 30;
}

int DiasAnio (int a){

    if (Bisiesto( a)) return 366;
    return 365;
}





int diaSemana(int ano,int mes){   //zeller
    //Dom 0,  Lun 1, Mart 2, Mier 3, Juev 4, Vier 5, Sab 6

    int a = (14-mes)/12;
    int y = ano - a;
    int m = mes + 12*a - 2;
    int dia = 1;
    int d = (dia + y+ y/4 - y/100 + y/400 + (31*m)/12)%7;
    return d;

}















//TODO: VER
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
}

//---------Calendario----------------

int listarCalendario(){

    int contDias = 0;
    int a = 2021;
    int diasDelAnio = 0;

    string m[] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

    for (int mes=1; mes<=12; mes++){
        cout << endl;
        //cout << "Mes : " << m[mes-1] << endl;
        cout << "  Domingo     Lunes       Martes      Miercoles   Jueves      Viernes     Sabado" << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
        int z = zeller(a, mes, 1);
        for (int i = 0; i<z; i++){
            cout << "            ";
        }

        int dias_mes_actual = CalcularDias (mes, a);
        int numero_de_semana = 1;
        for (int dia = 1; dia <= dias_mes_actual; dia ++){
            diasDelAnio ++;
            numero_de_semana = (diasDelAnio/7) + 1;
            Fecha f;//(dia, mes, a, numero_de_semana, z);
            f.leerDeDisco(contDias);
            //f.grabarEnDisco();
            f.mostrar();
            cout << "  ";
//            if (dia < 10){
//                f.mostrar();
//                cout << "   ";
//                //cout << dia << "   ";
//            }
//            else {
//                f.mostrar();
//                cout << "  ";
//                //cout << dia << "  ";
//            }
            z++;
            if (z % 7 == 0) {
                cout << endl;
            }

            //Fecha f(dia, mes, a);
            contDias ++;
        }

        cout << endl;
    }

    return 0;
}

int CalcularDias (int mes, int a){
    //int diasDelMes [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        return 31;
    }
    if (mes == 2){
        if (Bisiesto(a)){
            return 29;
        }
        else{
            return 28;
        }
    }
    return 30;


}



int zeller(int ano,int mes, int dia){
    //Dom 0,  Lun 1, Mart 2, Mier 3, Juev 4, Vier 5, Sab 6

    int a = (14-mes)/12;
    int y = ano - a;
    int m = mes + 12*a - 2;

    int d = (dia + y+ y/4 - y/100 + y/400 + (31*m)/12)%7;
    return d;


}

//-----------------------------------------

*/









