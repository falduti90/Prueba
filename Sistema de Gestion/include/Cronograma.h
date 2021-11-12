#ifndef CRONOGRAMA_H_INCLUDED
#define CRONOGRAMA_H_INCLUDED
#include <string.h>
#include "Fecha.h"
#include "BaseCalculo.h"

class Cronograma {
    private:
        int _idCronograma[2];
        Fecha _fechaRecepcionCnt;
        Fecha _fechaETA;
        Fecha _fechaETD;
        Fecha _fechacutoffFisico;
        Fecha _fechacutoffDoc;
        int _numSemana;
        int _idAgencia;
        int _idBuque;
        int _numeroViaje;
        bool _activo;
        int _idRegion;
        int _idGiro;


    public:
        void setIdCronograma( int idAgencia , int idRegion , int idGiro );
        void setFechaRecepcionCnt(Fecha f);
        void setFechaETA(Fecha f);
        void setFechaETD(Fecha f);
        void setFechaCutoffFisico(Fecha f);
        void setFechaCutoffDoc(Fecha f);
        void setNumSemana(int num);
        void setActivo(bool);
        int* getIdCronograma();
        Fecha getFechaRecepcionCnt();
        Fecha getFechaETA();
        Fecha getFechaETD();
        Fecha getFechaCutoffFisico();
        Fecha getFechaCutoffDoc();
        bool operator ==(int *);
        int getNumSemana();
        bool getActivo();
        void cargar();
        void mostrar();
        bool leerDeDisco(int);
        bool grabarEnDisco();
//TODO  bool grabarEnDisco(int);
};

#endif // CRONOGRAMA_H

//FUNCIONES GLOBALES

void ListadoCronograma();
Fecha BuscarEnCalendario(int, int, int);
int BuscarDiaSemana(Cronograma);
int BuscarIdTerminal(int);


