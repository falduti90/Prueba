#ifndef BUQUES_H
#define BUQUES_H
#include "Terminal.h"


class Buque{
    public:
        Buque();
        void setIdBuque(int nuevoId);
        void setnombreBuque(char* nuevoNombre);
        void setBanderaBuque(char* nuevaBandera);
        void setGiro(int nuevoGiro);
        void setActivo(bool nuevoEstado);
        int getIdBuque();
        char* getnombreBuque();
        char* getBanderaBuque();
        int getGiro();
        bool getActivo();
        void cargar();
        void mostrar();
        bool leerDeDisco(int pos);
        bool grabarEnDisco();
//TODO  bool grabarEnDisco(int);



    private:

    int         _idBuque;
    char        _nombreBuque[100];
    char        _banderaBuque [100];
    int         _giro;
    bool        _activo;
};

//FUNCIONES GLOBALES

void ListadoBuques();
void BuscarBuque(int);
void buscarTerminal(int );
int  BuscarIdTerminal(int );
void ListarPorBuque();

#endif // BUQUES_H
