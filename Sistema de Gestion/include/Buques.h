#ifndef BUQUES_H
#define BUQUES_H
#include "Terminal.h"


class Buques
{
    public:
        Buques();
        void setIdBuque(int NuevoId);
        void setnombreBuque(char* NuevoNombre);
        void setBanderaBuque(char *NuevaBandera);
        void setNumeroViaje(int NuevoNro);
        void setGiro(Terminal NuevoGiro);
        void setActivo(bool NuevoEstado);
        int getIdBuque();
        char* getnombreBuque();
        char* getBanderaBuque();
        int getNumeroViaje();
        Terminal getGiro();
        bool getActivo();
        void cargar();
        void mostrar();
        bool leerDeDisco(int pos);
        bool grabarEnDisco();



    private:

    int         _idBuque;
    char        _nombreBuque[30];
    char        _banderaBuque [30];
    int         _numeroViaje;
    Terminal    _giro;
    bool        _activo;
};

//FUNCIONES GLOBALES

void ListadoBuques();

#endif // BUQUES_H
