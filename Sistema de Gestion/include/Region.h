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



    private:
        int _IdRegion;
        char _NombreRegion;
        bool _Activo;

};

#endif // REGION_H
	>>>Region
-idRegion: int
-nombreRegion: char[30]
-activo: bool
________________


+cargar(): void
+mostrar(): void
+leerDeDisco(int): bool
+grabarEnDisco(): bool
+grabarEnDisco(int): bool
