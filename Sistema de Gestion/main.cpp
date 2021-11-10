#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include "Fecha.h"
#include <cstring>
#include "Buque.h"
#include "Cronograma.h"
#include "Agencia.h"
#include "Region.h"
#include "Terminal.h"
#include "Agencia.h"
#include "Fecha.h"
#include "FuncionesGlobales.h"
#include "Usuario.h"
#include "rlutil.h"
#include <sstream> //Libredias para
#include <fstream> // el importador
#define NOMBRE_ARCHIVO "Prueba.csv" // Archivo para importador
using namespace std;

int main(){

    //Usuario reg;

    //reg.leerDeDisco(0);
    //cout << reg.getUsuario() << endl;
    //cout << reg.getContrasenia() << endl;
    //cout << reg.getCategoria() << endl;

    //Buque obj;

    /*Cronograma reg;

    reg.cargar();
    cout << endl;
    reg.mostrar();


    ListadoCronograma();

    cout << endl << endl;

    char prueba1[30] = "HOLA ";
    char prueba2[30] = "QUE ";
    char prueba3[30] = "TAL ";
    strcat(prueba1,(strcat(prueba2, prueba3)));
    //strcat_
    cout << prueba1;

    */

    Fecha f(28,12,2021);
    f.mostrar();
    cout << endl << "Numero de semana: " <<  f.getNumeroSemana();
    cout << endl << "Numero de dia   :" << f.getNumDia();
    cout << endl;

    //MenuPrincipal();
    return 0;
}












