#ifndef AGENCIA_H
#define AGENCIA_H


class Agencia
{
    public:
        Agencia();
        void   setIdAgencia(int nuevoID);
        void  setNombreAgencia(char *nuevoNombre);
        void   setDisponibilidadMensual(int nuevoCupo);
        void   setGastosLocales(float nuevoGasto);
        void  setActivo(bool nuevoEstado);
        int   getIdAgencia();
        char *getNombreAgencia();
        int   getDisponibilidadMensual();
        float getGastosLocales();
        bool  getActivo();
        void  cargar();
        void  mostrar();
        bool  leerDeDisco(int pos);
        bool  grabarEnDisco();
        bool  ModificarEnDiscoAgencia(int pos);
//TODO  bool  grabarEnDisco(int);

    private:
        int   _idAgencia;
        char  _nombreAgencia [100];
        int   _disponibilidadMensual;
        float _gastosLocales;
        bool  _activo;

    };

//------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES

void BuscarAgencia(int);
char *BuscarAgencia(int, bool);
bool BorrarRegistroAgencia();
int  AgenciaAborrar(int idAgencia);


#endif // AGENCIA_H
