#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include "Fecha.h"
using namespace std;
#include <cstring>
#include "Buque.h"
#include "Cronograma.h"
#include "Agencia.h"
#include "Region.h"
#include "Terminal.h"
#include "Agencia.h"
#include "Fecha.h"



int main(){
    Cronograma reg;

    /*reg.cargar();
    cout << endl;
    reg.mostrar();*/

    ListadoCronograma();

    cout << endl << endl;

    char prueba1[30] = "HOLA ";
    char prueba2[30] = "QUE ";
    char prueba3[30] = "TAL ";
    strcat(prueba1,(strcat(prueba2, prueba3)));
    //strcat_
    cout << prueba1;

      return 0;
}














