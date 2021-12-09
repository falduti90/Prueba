#ifndef ESTADISTICA_H
#define ESTADISTICA_H

class Estadistica{
    public:
        Estadistica();
        int   getMesCarga();
        int   getAnioCarga();
        int   getIdAgencia();
        int   getIdBuque();
        int   getIdRegion();
        int   getIdTerminal();
        int   getCantContenedores();
        float getCostoAgencia();
        float getCostoTerminal();
        float getCostoTotalAgencia();
        float getCostoTotalTerminal();
        bool  getActivo();

        void  setMesCarga(int);
        void  setAnioCarga(int);
        void  setIdAgencia(int);
        void  setIdBuque(int);
        void  setIdRegion(int);
        void  setIdTerminal(int);
        void  setCantContenedores(int);
        void  setCostoAgencia(int);
        void  setCostoTerminal(int);
        void  setCostoTotalAgencia(int);
        void  setCostoTotalTerminal(int);
        void  setActivo(bool);

        void  cargar();
        void  mostrar();
        bool  leerDeDisco(int);
        bool  grabarEnDisco();

    private:
        int   _anioCarga;
        int   _mesCarga;
        int   _idAgencia;
        int   _idBuque;
        int   _idRegion;
        int   _idTerminal;
        int   _cantContenedores;
        float _costoAgencia;
        float _costoTerminal;
        float _costoTotalAgencia;
        float _costoTotalTerminal;
        bool  _activo;
};

#endif // ESTADISTICA_H

// GLOBALES:


bool primerRegistroMes(int , int , int);
int consultaEspacioInicial(int);
int calculaEspacioDisponible(int , int , int);
float consultaCostoAgencia(int);
float consultaCostoTerminal(int);
int cuentaContenedores(int , int , int);
void resumenMensual();  // ANIO ACTUAL
float sumaTotalAgencia(int , int , int);
float sumaTotalTerminal(int , int , int);
int cantidadAgencias();
int BuscarIdAgencia(int);
bool buscarEnArchivo(int);
bool buscarAnio( int);

void  ListadoEstadistica();
void  resumenAnual();
void  resumenMensual();
void  resumenxAgencia();

