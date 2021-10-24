#ifndef DOMICILIO_H
#define DOMICILIO_H


class Domicilio
{
    public:
        Domicilio();
        void setCalle(char * NuevaCalle);
        void setAltura(int NuevaAltura);
        void setLocalidad(char *NuevaLocalidad);
        char* getCalle();
        int getAltura();
        char* getLocalidad();
        void Cargar();
        void Mostrar();
        bool leerDeDisco(int pos);
        bool grabarEnDisco();

    private:
    char _Calle[30];
    int  _Altura;
    char _Localidad[30];
};


//-------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES

void ListadoDeDomicilios();

#endif // DOMICILIO_H



