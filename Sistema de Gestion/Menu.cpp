#include <iostream>
#include "cstdlib".h"
#include "Menu.h"

using namespace std;


//FUNCION MENU PRINCIPAL

void Menu(){

    int opc;
    system("color 9F");
    cout << "\t\t\t**TITULO**" << endl << endl;
    cout << "\t\t**********" << endl << endl;
    cout << "\t\t1 - INICIAR SESION. " << endl;
    cout << "\t\t2 - REGISTRARSE. " << endl;
    cout << "\t\t0 - SALIR. " << endl << endl;

    cout << "\t\tSELECCIONE OPCION: ";
    cin  >> opc;

    system("cls");

    switch(opc){
        case 1 : InicioSesion();
            break;
        case 2 : RegistrarUsuario();
            break;
        case 0 : return ;
    }
}
