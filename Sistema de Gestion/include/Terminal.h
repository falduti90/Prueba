#ifndef TERMINAL_H
#define TERMINAL_H


class Terminal
{
    public:
        Terminal();
        void setIdTerminal(int) ;
        void setNombreTerminal(char *);
        void setDireccion (Domicilio);
        void setEmail(char *)
        void setGastosFijos(float):
        void setActivo(bool)
        char * getNombreTerminal();
        int getDireccion ();
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
        bool activo;



};

#endif // TERMINAL_H
