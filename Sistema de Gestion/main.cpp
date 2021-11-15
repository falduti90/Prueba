#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include "Fecha.h"
#include <cstring>
#include "Buque.h"
#include "Agencia.h"
#include "Region.h"
#include "Terminal.h"
#include "Agencia.h"
#include "Fecha.h"
#include "FuncionesGlobales.h"
#include "Usuario.h"
#include "rlutil.h"
#include "BaseCalculo.h"
#include "Cronograma.h"
#include <sstream> //LibreRias para
#include <fstream> // el importador
#define NOMBRE_ARCHIVO "Prueba.csv" // Archivo para importador
using namespace std;



int main(){

/*
for (int i = 0; i<2;i++){
Cronograma r;
r.cargar();
r.grabarEnDisco();
cout << endl;
*/

//ListadoDeRegiones();
    //ListadoCronograma();
    //ListadoBaseCalculo();

    /*
    Cronograma c;
    c.cargar();
    cout << endl;
    c.mostrar();*/

   // c.setIdCronograma ( 6 ,3 ,2 );
    //cout << BuscarDiaSemana(c);


   /* Fecha ETD, ETA, AUX;
    int v = 0;

    ETA = Calendario( 2 , 2);
    //ETA.mostrar();

    ETD = ETA-=2;

    ETA.mostrar();
    cout << endl;
    ETD.mostrar();*/

    //MenuPrincipal();
    Buque reg;
    //reg.cargar();
    ListarPorBuque();
    return 0;
}
/*char prueba1[30] = "HOLA ";
    char prueba2[30] = "QUE ";
    char prueba3[30] = "TAL ";
    strcat(prueba1,(strcat(prueba2, prueba3)));
    //strcat_
    cout << prueba1;

    */








