#include <iostream>
#include "EliminarRegistro.h"
#include "Buque.h"
#include "Agencia.h"
#include "Region.h"
#include "Terminal.h"
#include "BaseCalculo.h"
#include "FuncionesGlobales.h"

using namespace std;

void EliminarRegistro(){

    int opc;

    while(true){
        cout << "\t\t\t\t\t\t***TITULO***" << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\t1 - ELIMINAR POR ID BUQUE. " << endl << endl;
        cout << "\t\t\t\t\t2 - ELIMINAR POR ID AGENCIA. " << endl << endl;
        cout << "\t\t\t\t\t3 - ELIMINAR POR ID REGION. " << endl << endl;
        cout << "\t\t\t\t\t4 - ELIMINAR POR ID TERMINAL. " << endl << endl;
        cout << "\t\t\t\t\t5 - ELIMINAR POR ID BASE DE CALCULO. " << endl << endl;
        cout << "\t\t\t\t\t0 - VOLVER." << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\tSELECCIONE OPCION: ";
        cin  >> opc;

        system("cls");

        switch(opc){
            case 1 : BorrarRegistroBuque();
                break;
            case 2 : BorrarRegistroAgencia();
               break;
            case 3 : BorrarRegistroRegion();
               break;
            case 4 : BorrarRegistroTerminal();
               break;
//            case 5 : BORRAR REGISTRO DE BASE DE CALCULO
//               break;
            case 0 : Admin();
               break;
        }
    }
    cout << "\t\t\t\t\t" << system("pause");
    system("cls");
}
