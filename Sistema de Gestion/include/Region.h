#ifndef REGION_H
#define REGION_H


class Region{
    public:
        Region();
        void    setIdRegion(int nuevoID);
        void    setNombreRegion(char *nuevoNombre);
        void    setCodRegion(char *codRegion);
        void    setActivo(bool nuevoEstado);
        int     getIdRegion();
        char   *getNombreRegion();
        char   *getCodRegion();
        bool    getActivo();
        void    cargar();
        void    mostrar();
        bool    leerDeDisco(int pos);
        bool    grabarEnDisco();
//TODO  bool grabarEnDisco(int);


    private:
        int  _idRegion;
        char _codRegion[10];
        char _nombreRegion[100];
        bool _activo;

};


//---------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES

void ListadoDeRegiones();
void BuscarRegion(int);

#endif // REGION_H


