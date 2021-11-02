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
#include "MenuPrincipal.h"
#include "rlutil.h"
#include <sstream> //Libredias para
#include <fstream> // el importador
#define NOMBRE_ARCHIVO "Prueba Importador.csv" // Archivo para importador
using namespace std;

void importar();
void exportar();



int main(){
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

    //importar();
    //exportar();
    //MenuPrincipal();
    Fecha f1(1,1,2022), f2(1,1,2021);
    if (f1 < f2){
        cout << endl << "F1 es menor a F2" << endl;
    }
    else {
        cout << endl << "F1 no es menor a F2" << endl;
    }
    return 0;
}


void importar(){
    ifstream archivo(NOMBRE_ARCHIVO);
	string linea;
	char delimitador = ',';
	getline(archivo, linea);

	while(getline(archivo, linea)){
        stringstream stream (linea);
        string dia, mes, anio;
        getline(stream, dia, delimitador);
        getline(stream, mes, delimitador);
        getline(stream, anio, delimitador);
        int d, m, a;
        istringstream(dia) >> d;
        istringstream(mes) >> m;
        istringstream(anio) >> a;
        Fecha f(d,m,a);
        f.mostrar();
        cout << endl;
        //cout << endl << dia << "/" << mes << "/" << anio;

	}

}

void exportar(){
    ofstream myFile;
	myFile.open("test.csv");
	Fecha f;
	int i = 0;
	while (f.leerDeDisco(i)){
        myFile << f.getDia() << ',' << f.getMes() << ',' << f.getAnio() << endl;
        i++;

	}

}













