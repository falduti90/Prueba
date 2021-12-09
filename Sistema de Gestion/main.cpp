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
#include "EliminarRegistro.h"
#include "Cronograma.h"
#include "Listados.h"
#include "Estadistica.h"
#include <sstream> //LibreRias para
#include <fstream> // el importador
#define NOMBRE_ARCHIVO "Prueba.csv" // Archivo para importador
#include "Validaciones.h"
using namespace std;


//void Listado(int buque, int numsemana , int idagencia , int idterminal);
//void pedirOpcionesDeFiltrado();

int main(){

//importarCronograma(); //
//ListadoBaseCalculo();
//ListadoBuques();



//pedirOpcionesDeFiltrado();
MenuPrincipal();
//ListadoCronograma();

    //importar();

//ListadoEstadistica();
    //MenuPrincipal();

    //ListarPorBuque();
    //EliminarRegistro();


//PARA CARGAR CRONOGRAMA:
/*
bool ok;
for (int i = 0; i<27;i++){
Cronograma r;
r.cargar();
cout << endl;
r.mostrar();
cout << endl;
cout << endl <<"CALCULADO OK ? SI = 1, NO = 0";
cout << endl;
cin >> ok;
cout << endl;
if (ok) r.grabarEnDisco();
cout << endl;
cout << endl;
}
*/

    return 0;
}









