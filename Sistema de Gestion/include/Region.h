#ifndef REGION_H
#define REGION_H


class Region{
    public:
        Region();
        void    setIdRegion(int NuevoID);
        void    setNombreRegion(char *NuevoNombre);
        void    setActivo(bool NuevoEstado);
        int     getIdRegion();
        char   *getNombreRegion();
        bool    getActivo();
        void    Cargar();
        void    Mostrar();
        bool    leerDeDisco(int pos);
        bool    grabarEnDisco();



    private:
        int _IdRegion;
        char _NombreRegion[30];
        bool _Activo;

};


//---------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES

void ListadoDeRegiones();
#endif // REGION_H

