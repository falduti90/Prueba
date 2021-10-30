#include <iostream>
#include <cstring>
#include "Menu.h"

using namespace std;

char user [30]= "Juan Cruz";
char passw [30]= "1234";

void InicioSesion(){

        char nombreUsuario[30] = {};
        char contrasenia[30]   = {};
        int  intentos = 0;

        do{
            cout << "\t\t\t**TITULO**" << endl << endl;
            cout << "\t\t**********" << endl << endl;
            cout << "\t\t - USUARIO : ";
            cin.ignore();
            cin.getline(nombreUsuario,30);
            cout << "\t\t - PASSWORD: ";
            cin.getline(contrasenia,30);

            if(strcmp(nombreUsuario,user) == 0 ){
                cout << endl;
                cout << "\t\t   BIENVENIDO!! " << endl << endl;
                system("pause");
                system("cls");
                MenuPrincipal();

            }
            else{
                cout << endl << "\t\tUSUARIO NO ENCONTRADO." << endl << endl;
                intentos++;
                system("pause > null");
                    if(intentos == 3){
                        system("cls");
                        cout << "\t\tDEMASIADOS INTENTOS FALLIDOS." << endl << endl;
                        system("pause");
                    }
            }
        system("cls");
        }while(intentos < 3);


        //HABRIA QUE LEER REGISTRO DE USUARIO Y SI EL USUARIO EXISTE QUE SIGA


}
void RegistrarUsuario(){

        char nombreUsuario[30], contrasenia[30];

        cout << "\t\t\t**TITULO**" << endl << endl;
        cout << "\t\t**********" << endl << endl;
        cout << "\t\t1 - USUARIO : ";
        cin.ignore();
        cin.getline(nombreUsuario,30);
        cout << "\t\t1 - PASSWORD: ";
        cin.getline(contrasenia,30);
        cin.ignore();

        system("pause");
        system("cls");
}
