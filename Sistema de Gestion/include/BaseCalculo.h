#ifndef BASECALCULO_H_INCLUDED
#define BASECALCULO_H_INCLUDED
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

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
        void setActivo(bool activo){_activo = activo;}
        void setCalculoRecepcionCnt ( int restaDias );
        void setIdBaseCalculo( int idAgencia , int idRegion , int idGiro );
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
        int *getIdBaseCalculo();
        void mostrarIdBaseCalculo();
        void cargar();
        void mostrar();
        bool leerDeDisco(int pos);
        bool grabarEnDisco();
        bool grabarEnDisco(int);

    private:
        int _idBaseCalculo[2];
        int _idAgencia;
        int _idRegion;
        int _idTerminalDeGiro;
        int _diaETA;
        int _calculoETD;
        int _diaCTF;
        int _horaCTF;
        int _diaCTD;
        int _horaCTD;
        int _calculoRecepcionCnt;
        bool _activo;
};

#endif // BASECALCULO_H_INCLUDED


//FUNCIONES GLOBALES
void diaSemana(int);
string diaSemanaStr(int, bool);

