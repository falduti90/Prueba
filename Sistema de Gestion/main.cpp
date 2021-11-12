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


   //ListadoBuques();
     cout << endl;
    // ListadoCronograma();      -> rEVISAR
      cout << endl;
     //ListadoDeAgencias();
     cout << endl;
    // ListadoDeRegiones();
      cout << endl;
    // ListadoDeTerminales();
    ListadoBaseCalculo();

      cout << endl;
      cout << endl;

    Cronograma c;

    c.setIdCronograma ( 6 ,3 ,2 );

    cout << BuscarDiaSemana(c);





    cout << endl << endl;

    /*char prueba1[30] = "HOLA ";
    char prueba2[30] = "QUE ";
    char prueba3[30] = "TAL ";
    strcat(prueba1,(strcat(prueba2, prueba3)));
    //strcat_
    cout << prueba1;

    */


    cout << endl;

    //MenuPrincipal();
    return 0;
}












