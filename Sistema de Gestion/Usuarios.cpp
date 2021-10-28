#include <iostream>
#include "Menu.h"

using namespace std;

void MenuPrincipal(){

    int opc;

    while(true){
        cout << "\t\t\t**TITULO**" << endl << endl;
        cout << "\t\t**********" << endl << endl;
        cout << "\t\t1 - CONSULTA. " << endl;
        cout << "\t\t2 - REGISTRA CRONOGRAMA. " << endl;
        cout << "\t\t3 - REGISTRA BASES. " << endl;
        cout << "\t\t0 - CERRAR SESION. " << endl << endl;
        cout << "\t\t**********" << endl << endl;
        cout << "\t\tSELECCIONE TIPO DE USUARIO: ";
        cin  >> opc;

        system("cls");

        switch(opc){
            case 1 : Consulta();
                break;
            case 2 : RegistraCronograma();
                break;
            case 3 : RegistraBases();
                break;
            case 0 : exit(-1);;
        }
    }
}

void Consulta(){

    int opc;

    while(true){
        cout << "\t\t\t**TITULO**" << endl << endl;
        cout << "\t\t**********" << endl << endl;
        cout << "\t\t1 - LISTAR POR BUQUE. " << endl;
        cout << "\t\t2 - LISTAR POR SEMANA. " << endl;
        cout << "\t\t0 - VOLVER." << endl << endl;
        cout << "\t\t**********" << endl << endl;
        cout << "\t\tSELECCIONE OPCION: ";
        cin  >> opc;

        system("cls");

        switch(opc){
        //case 1 : LISTAR POR BUQUE;
        //    break;
        //case 2 : LISTAR POR SEMANA;
        //    break;
        case 0 : return ;
        }
    }
    system("pause");
    system("cls");
}
void RegistraCronograma(){

    int opc;

    while(true){
        cout << "\t\t\t**TITULO**" << endl << endl;
        cout << "\t\t**********" << endl << endl;
        cout << "\t\t1 - LISTAR POR BUQUE. " << endl;
        cout << "\t\t2 - LISTAR POR AGENCIAS. " << endl;
        cout << "\t\t3 - CARGAR DATOS. " << endl;
        cout << "\t\t0 - VOLVER." << endl << endl;
        cout << "\t\t**********" << endl << endl;
        cout << "\t\tSELECCIONE OPCION: ";
        cin  >> opc;

        system("cls");

        switch(opc){
        //case 1 : LISTAR POR BUQUE;
        //    break;
        //case 2 : LISTAR POR SEMANA;
        //    break;
        //case 3 : CARGAR DATOS;
        //    break;
        case 0 : return ;
        }
    }
    system("pause");
    system("cls");
}
void RegistraBases(){

    int opc;

    while(true){
        cout << "\t\t\t**TITULO**" << endl << endl;
        cout << "\t\t**********" << endl << endl;
        cout << "\t\t1 - LISTAR POR BUQUE. " << endl;
        cout << "\t\t2 - LISTAR POR AGENCIAS. " << endl;
        cout << "\t\t3 - AGREGAR / EDITAR / ELIMINAR REGISTRO. " << endl;
        cout << "\t\t0 - VOLVER." << endl << endl;
        cout << "\t\t**********" << endl << endl;
        cout << "\t\tSELECCIONE OPCION: ";
        cin  >> opc;

        system("cls");

        switch(opc){
        //case 1 : LISTAR POR BUQUE;
        //    break;
        //case 2 : LISTAR POR SEMANA;
        //    break;
        //case 3 : AGREGAR / EDITAR / ELIMINAR REGISTRO ;
        //    break;
        case 0 : return ;
        }
    }
    system("pause");
    system("cls");
}
