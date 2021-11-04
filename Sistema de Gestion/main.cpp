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
#define NOMBRE_ARCHIVO "Prueba.csv" // Archivo para importador
using namespace std;

void importar();
void exportar();
void mostrar();
int  buscarPosicionPorUsuario(char *usuario);
void cargarCadena(char *pal, int tam);

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

    MenuPrincipal();

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
int buscarPosicionPorUsuario(char *usuario){

    Usuario u;
    int pos = 0;

    while(u.leerDeDisco(pos)){
        if(strcmp(usuario,u.getUsuario())== 0){
            return pos;
        }
        pos++;
    }
}
void InicioSesion(){

    int  intentos = 0, pos = 0;
    char usuario[30] = " ";
    char contrasenia [30] = " ";
    Usuario obj;

    do{
        cout << "\t\t\t\t\t\t***TITULO***" << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\t - USUARIO : ";
        cargarCadena(usuario,30);
        cout << endl;
        cout << "\t\t\t\t\t - PASSWORD: ";
        cargarCadena(contrasenia,30);

        pos = buscarPosicionPorUsuario(usuario);
        obj.leerDeDisco(pos);
            intentos++;
            if(strcmp(obj.getContrasenia(), contrasenia) == 0){
                cout << endl << "\t\t\t\t\t   BIENVENIDO!! " << endl << endl;
                system("pause > null");
                system("cls");
                switch(obj.getCategoria()){
                    case 1 : Consultas();
                        break;
                    case 2 : DataEntry();
                        break;
                    case 3 : Admin();
                        break;
                }
            }
            else{
                cout << endl << "\t\t\t\t\tUSUARIO NO ENCONTRADO." << endl << endl;
                system("pause > null");
                system("cls");
                cout << "\t\t\t\t\t\t***TITULO***" << endl << endl;
                cout << "\t\t\t\t*******************************************" << endl << endl;
                cout << "\t\t\t\t\t - USUARIO : ";
                cin.ignore();
                cin.getline(usuario,30);
                cout << "\t\t\t\t\t - PASSWORD: ";
                cin.getline(contrasenia,30);
                if(intentos == 2){
                    system("color 4F");
                    cout << endl << endl << "\t\t\t\t\tDEMASIADOS INTENTOS FALLIDOS." << endl << endl;
                    cout << "\t\t\t\t\t" << system("pause");
                    system("color 9F");
                    system("cls");
                    main();
                }
            }

        main();
    }while(intentos < 2);

}
void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}










