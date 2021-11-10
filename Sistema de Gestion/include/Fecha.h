#ifndef FECHA_H
#define FECHA_H


class Fecha
{
    public:
        Fecha();
        Fecha(int, int, int, int, int);
        Fecha(int, int, int);
        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);
        void setNumeroSemana(int numSemana);
        void setNumDia (int numDia);
        void setDiasDelmes ();
        int getDia();
        int getMes();
        int getAnio();
        int getNumeroSemana();
        int getNumDia();
        int *getDiasDelmes ();
        void mostrar();
        bool grabarEnDisco();
        bool leerDeDisco(int);
        //----
        bool operator ==(Fecha);
        bool operator!=(Fecha);
        bool operator >(Fecha);
        bool operator <(Fecha);
        bool operator + (int);
        bool operator - (int);
        bool operator =(Fecha);

    private:
        int _dia;
        int _mes;
        int _anio;
        int _numeroSemana;
        int _numDia;  // TODO: VER
        int _diasDelMes [12] = {31,28,31,30,31,30,31,31,30,31,30,31};

};

//---------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES

void ListadoDeFechas();

//--------Calendario---------------
int listarCalendario();
int CalcularDias (int, int);
bool Bisiesto (int);
int zeller (int, int, int);
//-----------------------------------






#endif // FECHA_H


