#ifndef AGENCIA_H
#define AGENCIA_H


class Agencia
{
    public:
        Agencia();
        int  setIdAgencia(int nuevoID);
        char setNombreAgencia(char *nuevoNombre);
        int setDisponibilidadMensual(int nuevoCupo);
        float setGastosLocales(float nuevoGasto);
        bool setActivo(bool nuevoEstado);
        int getIdAgencia();
        char *getNombreAgencia();
        int  getDisponibilidadMensual();
        float getGastosLocales();
        bool getActivo();
        void cargar();
        void mostrar();
        bool leerDeDisco(int pos);
        bool grabarEnDisco();
//TODO  bool grabarEnDisco(int);


    private:
    int     _idAgencia;
    char    _nombreAgencia [100];
    int     _disponibilidadMensual;
    float   _gastosLocales;
    bool    _activo;

    };

//------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES

void ListadoDeAgencias();

#endif // AGENCIA_H
