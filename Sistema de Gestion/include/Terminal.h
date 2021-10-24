#ifndef TERMINAL_H
#define TERMINAL_H
#include "Domicilio.h"

class Terminal
{
    public:
        Terminal();
        void setIdTerminal(int NuevoID) ;
        void setNombreTerminal(char * NuevoNombre);
        void setDireccion (Domicilio NuevaDir);
        void setEmail(char * NuevoEmail);
        void setGastosFijos(float NuevoGasto);
        void setActivo(bool NuevoEstado);
        char * getNombreTerminal();
        Domicilio    getDireccion ();
        char * getEmail();
        float getGastosFijos();
        void cargar();
        void mostrar();
        bool leerDeDisco(int pos);
        bool grabarEnDisco();


    private:
        int _IdTerminal;
        char _NombreTerminal [30], _Email[30];
        float _GastosFijos;
        Domicilio _Direccion;
        bool _Activo;



};
//------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES

void ListadoDeTerminales();
#endif // TERMINAL_H
