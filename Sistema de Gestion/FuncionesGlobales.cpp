#include <iostream>
#include <cstdlib>
#include "rlutil.h"
#include "FuncionesGlobales.h"
#include "Usuario.h"
#include "Fecha.h"
#include "Buque.h"
#include <sstream> //Libredias para
#include <fstream> // el importador
#define NOMBRE_ARCHIVO "Prueba.csv" // Archivo para importador

using namespace std;

int MenuPrincipal(){

    int opc, pos = 0;

    Usuario obj;

    do{
        system("color 9F");
        cout << "\t\t\t\t\t\t***TITULO***" << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\t1 - INICIAR SESION. " << endl << endl;
        cout << "\t\t\t\t\t2 - CREAR USUARIO. " << endl << endl;
        cout << "\t\t\t\t\t0 - SALIR. " << endl << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\tSELECCIONE OPCION: ";
        rlutil::locate(60,11);
        cin  >> opc;

        if(opc >= 0 && opc < 3){
            system("cls");
        }

        switch(opc){
            case 1 : InicioSesion();
                break;
            case 2 : CrearUsuario();
                break;
            case 0 : exit (-1);
                break;

            default : rlutil::locate(41,13);
                    cout << "OPCION INVALIDA!!!" << endl << endl;
                    system("pause > nul");
                    system("cls");
                break;
        }
    }
    while(opc >= 0 || opc < 3);
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
        rlutil::setColor(rlutil::LIGHTBLUE);
        cargarCadena(contrasenia,30);
        rlutil::setColor(rlutil::WHITE);

        pos = buscarPosicionPorUsuario(usuario);

        obj.leerDeDisco(pos);

        if(strcmp(obj.getContrasenia(), contrasenia) == 0){
            cout << endl << "\t\t\t\t\t   BIENVENIDO!!! " << endl << endl;
            system("pause > nul");
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
            intentos++;
            cout << endl << "\t\t\t\t\tUSUARIO NO ENCONTRADO!!!" << endl << endl;
            system("pause > nul");
            system("cls");

            if(intentos == 3){
                cout << endl << endl << "\t\t\t\t\tDEMASIADOS INTENTOS FALLIDOS!!!" << endl << endl;
                cout << "\t\t\t\t\t" << system("pause > nul");
                system("cls");
                MenuPrincipal();
            }
        }
    }while(intentos < 3);
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
            cout << endl << endl;
            cout << "\t\t\t\t\t - PASSWORD : ";
            cin.getline(contrasenia,30);
            obj.setContrasenia(contrasenia);
            cout << endl << endl;
            cout << "\t\t\t\t\t - CATEGORIA: " << endl << endl;
            cout << "\t\t\t\t\t 1. Consultas." << endl;
            cout << "\t\t\t\t\t 2. Data Entry." << endl;
            cout << "\t\t\t\t\t 3. Admin." << endl << endl;
            cout << "\t\t\t\t*******************************************" << endl << endl;
            cout << "\t\t\t\t\t Seleccione opcion: ";
            cin  >> categoria;
            obj.setCategoria(categoria);
            obj.grabarEnDisco();
            if(categoria < 0 || categoria > 3){
                cout << "\t\tCATEGORIA INVALIDA!!!" << endl;
                cout << "\t\t Seleccione opcion: ";
                cin  >> categoria;
            }
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
    rlutil::setColor(rlutil::LIGHTBLUE);
    cin.getline(usuario, 30);
    cout << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "\t\t\t\t\tCONTRASENIA: ";
    rlutil::setColor(rlutil::LIGHTBLUE);
    cin.getline(contrasenia, 30);
    rlutil::setColor(rlutil::WHITE);

    if(strcmp(usuarioAdmin, usuario) == 0 && strcmp(contraseniaAdmin, contrasenia) == 0){
        cout << endl;
        cout << "\t\t\t\t\tBIENVENIDO!!! " << endl << endl;
        system("pause > nul");
        system("cls");
        return true;
    }
    else{
        cout << endl << "\t\t\t\t\tUSUARIO INVALIDO!!!" << endl << endl;
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
        cout << "\t\t\t\t\t1. LISTAR POR BUQUE. " << endl << endl;
        cout << "\t\t\t\t\t2. LISTAR POR SEMANA. " << endl << endl;
        cout << "\t\t\t\t\t0. MENU PRINCIPAL. " << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\tSELECCIONE OPCION: ";
        rlutil::locate(60,11);
        cin  >> opc;

        if(opc >= 0 && opc < 3){
            system("cls");
        }

        switch(opc){
            case 1 : //LISTAR POR BUQUE
                break;
            case 2 : //LISTAR POR SEMANA
                break;
            case 0 : MenuPrincipal();
                break;
            default : rlutil::locate(41,13);
                      cout << "OPCION INVALIDA!!!" << endl;
                      system("pause > nul");
                      rlutil::locate(1,1);
                break;
        }
    }
}
void DataEntry(){
    int opc;

    while(true){
        cout << "\t\t\t\t\t\t***TITULO***" << endl << endl;
        cout << "\t\t\t\t*******************************************" << endl << endl;
        cout << "\t\t\t\t\t1 - LISTAR POR BUQUE. " << endl << endl;
        cout << "\t\t\t\t\t2 - LISTAR POR AGENCIAS. " << endl << endl;
        cout << "\t\t\t\t\t3 - CARGAR DATOS. " << endl << endl;
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
        cout << "\t\t\t\t\t1 - LISTAR POR BUQUE. " << endl << endl;
        cout << "\t\t\t\t\t2 - LISTAR POR AGENCIAS. " << endl << endl;
        cout << "\t\t\t\t\t3 - AGREGAR / EDITAR / ELIMINAR REGISTRO. " << endl << endl;
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
void ListarPorBuque(){
    system("color 9F");
    Buque reg;
    int pos = 0, opc;
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
    cin >> opc;
}
