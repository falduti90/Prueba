#ifndef FECHA_H
#define FECHA_H


class Fecha
{
    public:
        Fecha();
        Fecha(int, int, int, int, int);
        void setDia(int dia){_dia = dia;}
        void setMes (int mes){_mes = mes;}
        void setAnio (int anio){_anio = anio;}
        void setNumeroSemana (int numSemana) { _numeroSemana = numSemana;}
        void setNumDia (int numDia){_numDia = numDia;}
        int getDia (){return _dia;}
        int getMes (){return _mes;}
        int getAnio () {return _anio;}
        int getNumeroSemana () {return _numeroSemana;}
        int getNumDia(){return _numDia;}
        void mostrar();
        bool grabarEnDisco();
        bool leerDeDisco(int);

    private:
        int _dia;
        int _mes;
        int _anio;
        int _numeroSemana;
        int _numDia;

};

//---------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES

void ListadoDeFechas();


#endif // FECHA_H


