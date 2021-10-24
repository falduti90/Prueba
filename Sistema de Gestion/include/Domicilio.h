#ifndef DOMICILIO_H
#define DOMICILIO_H


class Domicilio
{
    public:
        Domicilio();
        void setCalle(char * NuevaCalle);
        void setAltura(int NuevaAltura);
        char* getCalle();
        int getAltura();
        void Cargar();
        void Mostrar();
        bool leerDeDisco(int pos);
        bool grabarEnDisco();

    private:
    char _Calle[30];
    int  _Altura;
};

#endif // DOMICILIO_H



