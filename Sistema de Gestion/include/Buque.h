#ifndef BUQUES_H
#define BUQUES_H
#include "Terminal.h"


class Buque{
    public:
        Buque();
        void setIdBuque(int NuevoId);
        void setnombreBuque(char* NuevoNombre);
        void setBanderaBuque(char *NuevaBandera);
        //void setNumeroViaje(int NuevoNro);
        void setGiro(int NuevoGiro);
        void setActivo(bool NuevoEstado);
        int getIdBuque();
        char* getnombreBuque();
        char* getBanderaBuque();
        //int getNumeroViaje();
        int getGiro();
        bool getActivo();
        void cargar();
        void mostrar();
        bool leerDeDisco(int pos);
        bool grabarEnDisco();



    private:

    int         _idBuque;
    char        _nombreBuque[30];
    char        _banderaBuque [30];
   // int         _numeroViaje;
    int         _giro;
    bool        _activo;
};

//FUNCIONES GLOBALES

void ListadoBuques();
void buscarTerminal(int giro);

#endif // BUQUES_H
