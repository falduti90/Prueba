#ifndef FECHA_H
#define FECHA_H


class Fecha
{
    public:
        Fecha();
        void setDia(int NuevoDia);
        void setMes(int NuevoMes);
        void setAnio(int NuevoAnio);
        void setNumeroSemana(int NuevaSemana);
        void setActivo(bool NuevoEstado);
        int getDia();
        int getMes();
        int getAnio();
        int getNumeroSemana();
        bool getActivo();
        void Cargar();
        void Mostrar();
        bool leerDeDisco(int pos );
        bool grabarEnDisco();



    private:
        int  _Dia, _Mes, _Anio;
        int  _NumeroSemana;
        bool _Activo;
};

//---------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES

void ListadoDeFechas();

#endif // FECHA_H


