#ifndef TERMINAL_H
#define TERMINAL_H
#include "Domicilio.h"

class Terminal {
    public:
        Terminal();
        void setIdTerminal(int nuevoID) ;
        void setNombreTerminal(char* nuevoNombre);
        void setDireccion (Domicilio nuevaDir);
        void setEmail(char *nuevoEmail);
        void setGastosFijos(float nuevoGasto);
        void setActivo(bool nuevoEstado);
        int getIdTerminal();
        char *getNombreTerminal();
        Domicilio getDireccion ();
        char *getEmail();
        float getGastosFijos();
        bool getActivo();
        void cargar();
        void mostrar();
        bool leerDeDisco(int pos);
        bool grabarEnDisco();
//TODO  bool grabarEnDisco(int);

    private:
        int _idTerminal;
        char _nombreTerminal[100], _email[100];
        float _gastosFijos;
        Domicilio _direccion;
        bool _activo;
};
//------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES

void ListadoDeTerminales();
void BuscarTerminal(int);

#endif // TERMINAL_H
