
#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <string.h>
#include "Usuario.h"

Usuario::Usuario(){
    _usuario [30]  = {};
    _contrasenia [30] = {};

}

bool Usuario::grabarEnDisco(){
     FILE *p;
     p = fopen("Usuarios.dat","ab");
     if(p == NULL){
         cout<< "\t\t\t\t\tNO SE PUDO ABRIR EL ARCHIVO.";
         return false;
     }
     bool ok = fwrite(this,sizeof(Usuario),1,p);
     if (ok == true){
         cout << endl << "\t\t\t\t\tREGISTRO GUARDADO."<< endl << endl;
     }
     else{
         cout << endl << "\t\t\t\t\tNO SE PUDO GUARDAR EL REGISTRO."<< endl << endl;
     }
     fclose(p);
     return ok;
}

bool Usuario::leerDeDisco(int pos){
        FILE *p;
        p = fopen("Usuarios.dat","rb");
        if(p == NULL){
        cout << endl << endl << "\t\t\t\t\tNO HAY USUARIOS REGISTRADOS." << endl << endl;
        cout << "\t\t\t\t\t" << system("pause");
        system("cls");
        return false;
        }
        else{
            fseek(p,sizeof(Usuario)* pos,SEEK_SET);
            bool ok = fread(this, sizeof(Usuario), 1, p);
            fclose(p);
            return ok;
        }
}
