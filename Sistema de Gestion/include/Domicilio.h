#ifndef DOMICILIO_H
#define DOMICILIO_H


class Domicilio{
    public:
        Domicilio();
        void setCalle(char* nuevaCalle);
        void setAltura(int nuevaAltura);
        void setLocalidad(char* nuevaLocalidad);
        char* getCalle();
        int getAltura();
        char* getLocalidad();
        void cargar();
        void mostrar();
        bool leerDeDisco(int pos);
        bool grabarEnDisco();
//TODO  bool grabarEnDisco(int);

    private:
    char _calle[100];
    int  _altura;
    char _localidad[100];
};


//-------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES

void ListadoDeDomicilios();

#endif // DOMICILIO_H



