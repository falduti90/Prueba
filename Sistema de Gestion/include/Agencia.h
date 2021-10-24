#ifndef AGENCIA_H
#define AGENCIA_H


class Agencia
{
    public:
        Agencia();
        int  setIdAgencia(int NuevoID);
        char setNombreAgencia(char * NuevoNombre);
        int setDisponibilidadMensual(int NuevoCupo);
        float setGastosLocales(float NuevoGasto);
        bool setActivo(bool NuevoEstado);
        int getIdAgencia();
        char * getNombreAgencia();
        int  getDisponibilidadMensual();
        float getGastosLocales();
        bool getActivo();
        void Cargar();
        void Mostrar();
        bool leerDeDisco(int pos);
        bool grabarEnDisco();



    private:
    int     _IdAgencia;
    int     _DisponibilidadMensual;
    char    _NombreAgencia [30];
    float   _GastosLocales;
    bool    _Activo;

    };

//------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES

void ListadoDeAgencias();

#endif // AGENCIA_H
