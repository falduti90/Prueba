#ifndef BUQUES_H
#define BUQUES_H
#include "Terminal.h"


class Buque{
    public:
        Buque();
        void  setIdBuque(int nuevoId);
        void  setnombreBuque(char* nuevoNombre);
        void  setBanderaBuque(char* nuevaBandera);
        void  setTerminalDeGiro(int nuevoGiro);
        void  setActivo(bool nuevoEstado);
        int   getIdBuque();
        char* getnombreBuque();
        char* getBanderaBuque();
        int   getTerminalDeGiro();
        bool  getActivo();
        void  cargar();
        void  mostrar();
        bool  leerDeDisco(int pos);
        bool  grabarEnDisco();
        bool  ModificarEnDiscoBuques(int pos);
    private:
        int   _idBuque;
        char  _nombreBuque[100];
        char  _banderaBuque [100];
        int   _terminalDeGiro;
        bool  _activo;
};

//FUNCIONES GLOBALES

void BuscarBuque(int);
char *BuscarBuque(int, bool);
void buscarTerminal(int );
void ListarPorBuque();
void BuqueSeleccionado(int opc);
bool BorrarRegistroBuque();
int  BuqueAborrar(int idBuque);



#endif // BUQUES_H
