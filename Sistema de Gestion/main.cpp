#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include "Fecha.h"
using namespace std;
#include "Buque.h"
#include "Cronograma.h"
#include "Agencia.h"
#include "Region.h"
#include "Terminal.h"
#include "Agencia.h"
#include "Fecha.h"

//--------Calendario---------------
int listarCalendario();
int CalcularDias (int, int);
bool Bisiesto (int);
int zeller (int, int, int);
//-----------------------------------



int main(){
    Cronograma reg;

    reg.cargar();
    cout << endl;
    reg.mostrar();

    //listarCalendario();
    /*Fecha f;
    f = buscarEnCalendario(27,10,2021);
    f.mostrar();
    cout << endl <<  "Numero de semana: " << f.getNumeroSemana();*/


    /*Buque reg;

    for (int i = 0; i<=20 ; i++){
    reg.cargar();
    cout << endl << endl;
    reg.grabarEnDisco();

    reg.mostrar();
    cout << endl << endl;
    }


   // ListadoBuques();


  Agencia obj;

   /* for (int i = 0; i<10 ; i++){
    obj.Cargar();
    cout << endl << endl;
    obj.grabarEnDisco();

    obj.Mostrar();
    cout << endl << endl;
    }

    ListadoDeTerminales();

    */
      return 0;
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
            /*if (dia < 10){
                f.mostrar();
                cout << "   ";
                //cout << dia << "   ";
            }
            else {
                f.mostrar();
                cout << "  ";
                //cout << dia << "  ";
            }*/
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

bool Bisiesto(int a){
    if(a%4 != 0) return false;
    else if(a%100 != 0) return true;
    else if(a%400 != 0) return false;
    return true;


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


