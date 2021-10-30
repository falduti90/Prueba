#ifndef REGION_H
#define REGION_H


class Region{
    public:
        Region();
        void    setIdRegion(int nuevoID);
        void    setNombreRegion(char *nuevoNombre);
        void    setActivo(bool nuevoEstado);
        int     getIdRegion();
        char   *getNombreRegion();
        bool    getActivo();
        void    cargar();
        void    mostrar();
        bool    leerDeDisco(int pos);
        bool    grabarEnDisco();
//TODO  bool grabarEnDisco(int);


    private:
        int  _idRegion;
        char _nombreRegion[100];
        bool _activo;

};


//---------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES

void ListadoDeRegiones();

#endif // REGION_H

