#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include "Buques.h"
#include "Terminal.h"

        //Buques::Buques(){}
        void Buques::setIdBuque(int NuevoId){
            _idBuque=NuevoId;
        }
        void Buques::setnombreBuque(char* NuevoNombre){
           strcpy(_nombreBuque,NuevoNombre);
        }
        void Buques::setBanderaBuque(char *NuevaBandera){
            strcpy(_banderaBuque,NuevaBandera);
        }

        void Buques::setNumeroViaje(int NuevoNro){
            _numeroViaje=NuevoNro;
        }
        void Buques::setGiro(Terminal NuevoGiro){
            _giro=NuevoGiro;
        }
        void Buques::setActivo(bool NuevoEstado){
            _activo=NuevoEstado;
        }
        int  Buques::getIdBuque(){
            return _idBuque;
        }
        char *Buques::getnombreBuque(){
            return _nombreBuque;
        }
        char *Buques::getBanderaBuque(){
            return _banderaBuque;
        }
        int  Buques::getNumeroViaje(){
            return _numeroViaje;
        }
        Terminal  Buques::getGiro(){

        }
        bool Buques::getActivo(){
            return _activo;
        }
        void Buques::cargar(){
            cout<< "INGRESE EL ID DEL BUQUE : "<<endl;
            cin >> _idBuque;
            cout<< "INGRESE EL NOMBRE DEL BUQUE :"<<endl;
            cin >> _nombreBuque;
            cout<< "INGRESE LA BANDERA DEL BUQUE :"<<endl;
            cin >> _banderaBuque;
            cout<< "INGRESE EL NUMERO DE VIAJE :"<<endl;
            cin >> _numeroViaje;
            cout<< "INGRESE EL GIRO : "<<endl;
            cin>>  _giro;

            _activo=true;


        }
        void Buques::mostrar(){
            cout<< "NUMERO DE ID BUQUE-:"<< "/"<< _idBuque<<endl;
            cout<< "NOMBRE DEL BUQUE---:"<< "/"<< _nombreBuque<<endl;
            cout<< "BANDERA------------:"<< "/"<< _banderaBuque<<endl;
            cout<< "NUMERO DE VIAJE----:"<< "/"<< _numeroViaje<<endl;
            cout<< "GIRO---------------:"<< "/"<<_giro<<endl;

        }
        bool Buques::leerDeDisco(int){}
        bool Buques::grabarEnDisco(){}
        bool Buques::grabarEnDisco(int){}
