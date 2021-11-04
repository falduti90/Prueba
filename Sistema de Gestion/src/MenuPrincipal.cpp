#include <iostream>
#include <cstdlib>
//#include "rlutil.h"
#include "MenuPrincipal.h"
#include "Usuario.h"

using namespace std;

int MenuPrincipal(){

    int opc, pos = 0;

    Usuario obj;

    do{
        system("color 9F");
        cout << "\t\t\t\t\t\t***TITULO***" << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\t1 - INICIAR SESION. " << endl;
        cout << "\t\t\t\t\t2 - CREAR USUARIO. " << endl;
        cout << "\t\t\t\t\t0 - SALIR. " << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\tSELECCIONE OPCION: ";
        //rlutil::locate(60,11);
        cin  >> opc;

        system("cls");

        switch(opc){
            case 1 : InicioSesion();
                break;
            case 2 : CrearUsuario();
                break;
            case 0 : exit (-1);
                break;

            default : //rlutil::locate(38,9);
                    cout << "OPCION INVALIDA." << endl;
                    //rlutil::locate(1,1);
                break;
        }
    }
    while(opc >= 0 || opc < 3);
}



void CrearUsuario(){

        char usuario[30] = {};
        char contrasenia [30] = {};
        int  categoria;
        Usuario obj;

        if(pedirContrasenia() == true){
            cout << "\t\t\t\t\t\t***TITULO***" << endl << endl;
            cout << "\t\t\t\t*******************************************" << endl << endl;
            cout << "\t\t\t\t\t - USUARIO  : ";
            cin.getline(usuario,30);
            obj.setUsuario(usuario);
            cout << "\t\t\t\t\t - PASSWORD : ";
            cin.getline(contrasenia,30);
            obj.setContrasenia(contrasenia);
            cout << "\t\t\t\t\t - CATEGORIA: " << endl << endl;
            cout << "\t\t\t\t\t 1. Consultas." << endl;
            cout << "\t\t\t\t\t 2. Data Entry." << endl;
            cout << "\t\t\t\t\t 3. Admin." << endl << endl;
            cout << "\t\t\t\t*******************************************" << endl << endl;
            cout << "\t\t\t\t\t Seleccione opcion: ";
            cin  >> categoria;
            obj.setCategoria(categoria);
            obj.grabarEnDisco();
            //while(categoria < 4 && categoria > 0){
            //}
            //while(categoria < 0 || categoria > 3){
            //    cout << "\t\tCATEGORIA INVALIDA" << endl;
            //    cout << "\t\t Seleccione opcion: ";
            //    cin  >> categoria;
            //}
            cout << "\t\t\t\t\t" << system("pause");
            system("cls");
            MenuPrincipal();
        }
        else{
            MenuPrincipal();
        }
    }



bool pedirContrasenia(){
    char usuario [30]     =  {};
    char contrasenia [30] =  {};
    char usuarioAdmin [30]     =  "admin";
    char contraseniaAdmin [30] =  "admin";
    Usuario obj;

    cout << "\t\t\t\t\tINGRESE USUARIO DE ADMINISTRADOR" << endl << endl;
    cin.ignore();
    cout << "\t\t\t\t\tUSUARIO    : ";
    cin.getline(usuario, 30);
    cout << "\t\t\t\t\tCONTRASENIA: ";
    cin.getline(contrasenia, 30);

    if(strcmp(usuarioAdmin, usuario) == 0 && strcmp(contraseniaAdmin, contrasenia) == 0){
        cout << endl;
        cout << "\t\t\t\t\tBIENVENIDO!! " << endl << endl;
        cout << "\t\t\t\t\t" << system("pause");
        system("cls");
        return true;
    }
    else{
        cout << endl << "\t\t\t\t\tUSUARIO INVALIDO!!!." << endl << endl;
        system("pause > nul");
        system("cls");
        return false;
    }
}

void Consultas(){

    int opc;

    while(true){
        system("color 9F");
        cout << "\t\t\t\t\t\t***TITULO***" << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\t1. LISTAR POR BUQUE. " << endl;
        cout << "\t\t\t\t\t2. LISTAR POR SEMANA. " << endl;
        cout << "\t\t\t\t\t0. MENU PRINCIPAL. " << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\tSELECCIONE OPCION: ";
        //rlutil::locate(36,9);
        cin  >> opc;

        system("cls");

        switch(opc){
            case 1 : //LISTAR POR BUQUE
                break;
            case 2 : //LISTAR POR SEMANA
                break;
            case 0 : MenuPrincipal();
                break;
            default : //rlutil::locate(38,9);
                    cout << "OPCION INVALIDA." << endl;
                    //rlutil::locate(1,1);
                break;
        }
    }
}

void DataEntry(){
    int opc;

    while(true){
        cout << "\t\t\t\t\t\t***TITULO***" << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\t1 - LISTAR POR BUQUE. " << endl;
        cout << "\t\t\t\t\t2 - LISTAR POR AGENCIAS. " << endl;
        cout << "\t\t\t\t\t3 - CARGAR DATOS. " << endl;
        cout << "\t\t\t\t\t0 - MENU PRINCIPAL." << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\tSELECCIONE OPCION: ";
        cin  >> opc;

        system("cls");

        switch(opc){
        //case 1 : LISTAR POR BUQUE;
        //    break;
        //case 2 : LISTAR POR SEMANA;
        //    break;
        //case 3 : CARGAR DATOS;
        //    break;
        case 0 : MenuPrincipal();
              break;
        }
    }
    cout << "\t\t\t\t\t" << system("pause");
    system("cls");
}

void Admin(){

    int opc;

    while(true){
        cout << "\t\t\t\t\t\t***TITULO***" << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\t1 - LISTAR POR BUQUE. " << endl;
        cout << "\t\t\t\t\t2 - LISTAR POR AGENCIAS. " << endl;
        cout << "\t\t\t\t\t3 - AGREGAR / EDITAR / ELIMINAR REGISTRO. " << endl;
        cout << "\t\t\t\t\t0 - MENU PRINCIPAL." << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\tSELECCIONE OPCION: ";
        cin  >> opc;

        system("cls");

        switch(opc){
        //case 1 : LISTAR POR BUQUE;
        //    break;
        //case 2 : LISTAR POR SEMANA;
        //    break;
        //case 3 : AGREGAR / EDITAR / ELIMINAR REGISTRO ;
        //    break;
        case 0 : MenuPrincipal(); ;
              break;
        }
    }
    cout << "\t\t\t\t\t" << system("pause");
    system("cls");
}

