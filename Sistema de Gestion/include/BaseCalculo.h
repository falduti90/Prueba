#ifndef BASECALCULO_H_INCLUDED
#define BASECALCULO_H_INCLUDED

class BaseCalculo{
    public:
        void setidAgencia ( int idAgencia );
        void setidRegion ( int idRegion );
        void setidGiro ( int idGiro );
        void setDiaETA ( int diaSem );
        void setCalculoETD ( int sumaDias );
        void setDiaCTF ( int diaSem );
        void setHoraCTF ( int hora );
        void setDiaCTD ( int diaSem );
        void setHoraCTD ( int hora );
        void setCalculoRecepcionCnt ( int restaDias );
        void setMismaSemana ( bool misma );
        void setIdReferencia( int idAgencia , int idRegion , int idGiro );
        int getidAgencia ();
        int getidRegion ();
        int getidGiro ();
        int getDiaETA ();
        int getCalculoETD ();
        int getDiaCTF ();
        int getHoraCTF ();
        int getDiaCTD ();
        int getHoraCTD ();
        int getCalculoRecepcionCnt ();
        bool getMismaSemana();
        int *getIdReferencia();
        void mostrarIdReferencia();
        void cargar();
        void mostrar();
        bool leerDeDisco(int pos);
        bool grabarEnDisco();
        bool grabarEnDisco(int);

    private:
        int _idReferencia[2];
        int _idAgencia;
        int _idRegion;
        int _idGiro;
        int _diaETA;                         // D�a de la semana que es la ETA. Ejemplo: miercoles = d�a n�mero 3
        int _calculoETD;                    // Cantidad de d�as que se le suma a la ETA. Ejemplo: ETD = ETA + 2
        int _diaCTF;                       // Cut off f�sico. Es un d�a de la misma semana o semana anterior a la ETA/ETD. Ejemplo: miercoles (3)
        int _horaCTF;                     // Valor fijo! (varia seg�n d�a _idReferencia)
        int _diaCTD;                     // Cut off documental. Es un d�a de la misma semana o semana anterior a la ETA/ETD, previo CTF o igual a CTF. Ejemplo: martes (2)
        int _horaCTD;                   // Valor fijo! (varia seg�n d�a _idReferencia)
        int _calculoRecepcionCnt;      // Suelen ser 5/7 d�as antes de la ETA o del COF, seg�n agencia.
        bool _mismaSemana;            // Para verificar si cuenta los CTF/CTD en la misma semana o la semana anterior
        bool _activo;
};

#endif // BASECALCULO_H_INCLUDED


//FUNCIONES GLOBALES
void ListadoBaseCalculo() ;
void diaSemana(int);
