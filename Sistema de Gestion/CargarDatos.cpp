#include <iostream>
#include "CargarDatos.h"
#include "Buque.h"
#include "Agencia.h"
#include "Region.h"
#include "Terminal.h"
#include "BaseCalculo.h"
#include "FuncionesGlobales.h"

using namespace std;

void CargarDatos(int categoria){

    int opc;
    Buque buq;
    Agencia ag;
    Region reg;
    Terminal term;
    BaseCalculo bas;
    Cronograma cron;
    bool tipoCarga;

    while(true){
        cout << "\t\t\t\t\t\t***TITULO***" << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\t1 - CARGAR BUQUE. " << endl << endl;
        cout << "\t\t\t\t\t2 - CARGAR AGENCIA. " << endl << endl;
        cout << "\t\t\t\t\t3 - CARGAR REGION. " << endl << endl;
        cout << "\t\t\t\t\t4 - CARGAR TERMINAL. " << endl << endl;
        cout << "\t\t\t\t\t5 - CARGAR BASE DE CALCULO. " << endl << endl;
        cout << "\t\t\t\t\t6 - CARGAR CRONOGRAMA " << endl << endl;
        cout << "\t\t\t\t\t0 - VOLVER." << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\tSELECCIONE OPCION: ";
        cin  >> opc;

        system("cls");

        switch(opc){
            case 1 : buq.cargar();
                break;
            case 2 : ag.cargar();
               break;
            case 3 : reg.cargar();
               break;
            case 4 : term.cargar();
               break;
            case 5 :
                system("cls");
                cout << endl << "1- IMPORTAR 2- CARGA MANUAL ";
                cin >> tipoCarga;
                if (tipoCarga){
                    importarBaseCalculo();
                }
                else{
                    bas.cargar();
                }
               break;
            case 6:
                system("cls");
                cout << endl << "1- IMPORTAR 2- CARGA MANUAL ";
                cin >> tipoCarga;
                if (tipoCarga){
                    importarCronograma();
                }
                else{
                cron.cargar();
                }
                break;
            case 0 : DataEntry(categoria);
               break;
        }
    }
    cout << "\t\t\t\t\t" << system("pause");
    system("cls");
}
