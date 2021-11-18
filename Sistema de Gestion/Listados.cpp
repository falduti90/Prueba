#include <iostream>
#include "Listados.h"
#include "Buque.h"
#include "Agencia.h"
#include "Region.h"
#include "Terminal.h"
#include "BaseCalculo.h"
#include "FuncionesGlobales.h"

using namespace std;

void Listados(){

    int opc;


    while(true){
        cout << "\t\t\t\t\t\t***TITULO***" << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\t1 - LISTADO DE BUQUES. " << endl << endl;
        cout << "\t\t\t\t\t2 - LISTADO DE AGENCIAS. " << endl << endl;
        cout << "\t\t\t\t\t3 - LISTADO DE REGIONES. " << endl << endl;
        cout << "\t\t\t\t\t4 - LISTADO DE TERMINALES. " << endl << endl;
        cout << "\t\t\t\t\t5 - LISTADO BASE DE CALCULO. " << endl << endl;
        cout << "\t\t\t\t\t0 - VOLVER." << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\tSELECCIONE OPCION: ";
        cin  >> opc;

        system("cls");

        switch(opc){
            case 1 : ListadoBuques();
                break;
            case 2 : ListadoDeAgencias();
               break;
            case 3 : ListadoDeRegiones();
               break;
            case 4 : ListadoDeTerminales();
               break;
            case 5 : ListadoBaseCalculo();
               break;
            case 0 : DataEntry();
               break;
        }
    }
    cout << "\t\t\t\t\t" << system("pause");
    system("cls");
}

void ListadoBuques() {

    FILE *p;
    Buque reg;
    p = fopen("Buques.dat","rb");
    if ( p == NULL ){
        cout << "No se pudo abrir el archivo";
    return ;
    }

    cout << "\t\t\t\t\t\t\tLISTADO DE BUQUES: " << endl << endl;
    cout << "\t\t\t\t*******************************************" << endl << endl;
    while ( fread ( &reg , sizeof(Buque) , 1 , p ) == 1 ){
        reg.mostrar();
        cout << "\t\t\t\t\t*******************************************" << endl;
    }
    cout << endl << endl;
    cout << "\t\t\t\t\t" << system("pause");
    system("cls");
    fclose(p);
}

void ListadoDeAgencias(){

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
}

void ListadoDeRegiones(){

    FILE *p;
    Region reg;
    p = fopen("Regiones.dat","rb");
    if ( p == NULL ){
        cout << "No se pudo abrir el archivo";
    return ;
    }
    cout << "\t\t\t\t\t\t\tLISTADO DE REGIONES: " << endl << endl;
    cout << "\t\t\t\t\t*******************************************" << endl << endl;
    while ( fread ( &reg , sizeof(Region) , 1 , p ) == 1 ){
        reg.mostrar();
        cout << "\t\t\t\t\t*******************************************" << endl;
    }
    cout << endl << endl;
    cout << "\t\t\t\t\t" << system("pause");
    system("cls");
    fclose(p);
}

void ListadoDeTerminales(){

    FILE *p;
    Terminal reg;
    p = fopen("Terminales.dat","rb");
    if ( p == NULL ){
        cout << "No se pudo abrir el archivo";
    return ;
    }
    cout << "\t\t\t\t\t\t\tLISTADO DE TERMINALES: " << endl << endl;
    cout << "\t\t\t\t\t*******************************************" << endl << endl;
    while( fread ( &reg , sizeof(Terminal) , 1 ,  p) == 1){
        reg.mostrar();
        cout << "\t\t\t\t\t*******************************************" << endl;
    }
    cout << endl << endl;
    cout << "\t\t\t\t\t" << system("pause");
    system("cls");
    fclose(p);
}

void ListadoBaseCalculo() {

    FILE *p;
    BaseCalculo reg;
    p=fopen("BasesCalculos.dat","rb");
    if(p==NULL){
        cout<< "No se pudo abrir el archivo";
    return ;
    }
    cout << "\t\t\t\t\t\t\tLISTADO DE BASE DE CALCULO: " << endl << endl;
    cout << "\t\t\t\t\t*******************************************" << endl << endl;
    while( fread ( &reg , sizeof(BaseCalculo) , 1 , p ) ){
        reg.mostrar();
        cout << "\t\t\t\t\t*******************************************" << endl;
    }
    cout << endl << endl;
    cout << "\t\t\t\t\t" << system("pause");
    system("cls");
    fclose(p);
}


