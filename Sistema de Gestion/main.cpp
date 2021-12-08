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
#include <sstream> //LibreRias para
#include <fstream> // el importador
#define NOMBRE_ARCHIVO "Prueba.csv" // Archivo para importador
#include "Validaciones.h"
using namespace std;


//void Listado(int buque, int numsemana , int idagencia , int idterminal);
//void pedirOpcionesDeFiltrado();

int main(){

//importarCronograma(); // Revisar combinaciones de base de calculo -> Consultar
//ListadoBaseCalculo();
//ListadoBuques();


    //exportarBaseDeCalculo();
    pedirOpcionesDeFiltrado();



    //importar();



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
/*char prueba1[30] = "HOLA ";
    char prueba2[30] = "QUE ";
    char prueba3[30] = "TAL ";
    strcat(prueba1,(strcat(prueba2, prueba3)));
    //strcat_
    cout << prueba1;

    */



//-------------Prueba-----------------
/*
void pedirOpcionesDeFiltrado(){
    int buque, semana, agencia, terminal;
    buque = semana = agencia = terminal = -1;
    bool op;
    cout << endl << "Seleccione opciones de filtrado: ";
    cout << endl << "-Buque";
    cout << endl << "1- Filtrar 0-No filtrar: ";
    cin >> op;
    if (op){

        Buque reg;
        Cronograma obj;
        int pos = 0, opc;
        char *posicion;
        cout << "\t\t\t\t\tSELECCIONE BUQUE: " << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        while(reg.leerDeDisco(pos++)){
            if(pos < 10){
             cout << "\t\t\t\t\t" << pos << ".  " << reg.getnombreBuque() << endl;
            }
            else{
             cout << "\t\t\t\t\t" << pos << ". " << reg.getnombreBuque() << endl;
            }
        }
        rlutil::locate(60,1);
        cout << endl << "Ingrese el buque: ";
        cin >> buque;
        system("cls");
    }
    cout << endl << "-Numero de semana";
    cout << endl << "1- Filtrar 0-No filtrar";
    cin >> op;
    if (op){
        cout << "Ingrese el numero de semana: ";
        cin >> semana;
    }
    cout << endl << "-Agencia";
    cout << endl << "1- Filtrar 0-No filtrar";
    cin >> op;
    if (op){


        FILE *p;
        Agencia reg;
        p = fopen("Agencias.dat","rb");
        if( p == NULL ){
            cout << "No se pudo abrir el archivo";
        return ;
        }
        cout << "\t\t\t\t\t\t\tLISTADO DE AGENCIAS: " << endl << endl;
        cout << "\t\t\t\t\t*******************************************" << endl << endl;
        while ( fread( &reg , sizeof(Agencia) , 1 , p ) == 1 ){
            reg.mostrar();
            cout << "\t\t\t\t\t*******************************************" << endl;
        }
        cout << endl << endl;
        cout << "\t\t\t\t\t" << system("pause");
        system("cls");
        fclose(p);

        cout << endl << "Ingrese la agencia: ";
        cin >> agencia;

    }
    cout << endl << "-Terminal";
    cout << endl << "1- Filtrar 0-No filtrar";
    cin >> op;
    if (op){

        FILE *p;
        Terminal reg;
        p = fopen("Terminales.dat","rb");
        if ( p == NULL ){
            cout << "No se pudo abrir el archivo";
        return ;
        }

        while( fread ( &reg , sizeof(Terminal) , 1 ,  p) == 1){
            reg.mostrar();
            cout << endl;
        }

        fclose(p);
        cout << endl << "Ingrese la terminal: ";
        cin >> terminal;



    }

    Listado(buque, semana, agencia, terminal);
}

void Listado(int buque, int numsemana , int idagencia , int idterminal){
        bool rta;
        cout << endl << "Desea exportar el listado?: (1- Si 0-No)";
        cin >> rta;

            ofstream myFile;
            myFile.open("listadoCronograma.csv");



        FILE *p;
        Cronograma reg;
        p=fopen("Cronograma.dat","rb");
        if(p==NULL){
            cout<< "No se pudo abrir el archivo";
        return ;
        }
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << " WEEK   AGENCIA   REGION   BUQUE    GIRO   VIAJE     ETA     ETD     CUT OFF DOC   CUT OFF FISICO   INICIO DE RECEPCION" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

        while(fread(&reg,sizeof(Cronograma),1,p)==1){

            bool v1 = (buque == -1) || (buque == reg.getIdBuque());
            cout << endl << "Esto devuelve buque: " << v1;
            bool v2 = (numsemana == -1) || (numsemana == reg.getNumSemana());
            cout << endl << "Esto devuelve semana: " << v2;
            bool v3 = (idagencia == -1 )|| (idagencia == reg.getIdAgencia());
            cout << endl << "Esto devuelve agencia: " << v3;
            bool v4 = (idterminal == -1) || (idterminal == reg.getIdGiro());
            cout << endl << "Esto devuelve terminal: " << v4;

            if (v1 && v2 && v3 && v4 ){
                char s[20] = "hola";
                //strcpy(s,BuscarAgencia(reg.getIdAgencia()));
                reg.mostrar();
                if (rta){
                    myFile << reg.getNumSemana() << ',' << reg.getIdAgencia()<< ',' << reg.getIdGiro() << ',' << reg.getIdBuque() << ',' << s << endl; //Hat que ver la forma de concatenar las fechas y en vez de mostrar el ID crear funciones para que te devuelvar el nombre como vector de char. (el exportador acepta vectores de char)

                }
                cout << endl;
            }
        }

        fclose(p);



}
*/






