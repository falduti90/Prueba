#ifndef CRONOGRAMA_H_INCLUDED
#define CRONOGRAMA_H_INCLUDED
#include <string.h>
#include "Fecha.h"
#include "BaseCalculo.h"

class Cronograma {
    private:
        int   _idCronograma[2];
        Fecha _fechaRecepcionCnt;
        Fecha _fechaETA;
        Fecha _fechaETD;
        Fecha _fechacutoffFisico;
        Fecha _fechacutoffDoc;
        int   _numSemana;
        int   _idAgencia;
        int   _idBuque;
        char   _viaje[11];
        bool  _activo;
        int   _idRegion;
        int   _idGiro;
    public:
        Cronograma();
        Cronograma(int,int,int);
        void setIdCronograma( int idAgencia , int idRegion , int idGiro );
        void setFechaRecepcionCnt(Fecha f);
        void setFechaETA(Fecha f);
        void setFechaETD(Fecha f);
        void setFechaCutoffFisico(Fecha f);
        void setFechaCutoffDoc(Fecha f);
        void setNumSemana(int num);
        void setIdBuque(int id){_idBuque = id;}
        void setActivo(bool);
        int* getIdCronograma();
        Fecha getFechaRecepcionCnt();
        Fecha getFechaETA();
        Fecha getFechaETD();
        Fecha getFechaCutoffFisico();
        Fecha getFechaCutoffDoc();
        bool operator ==(int *);
        int getIdBuque(){return _idBuque;}
        int getNumSemana();
        bool getActivo();
        int getIdAgencia(){return _idAgencia;}
        int getIdGiro(){return _idGiro;}
        void cargar();
        void mostrar();
        bool leerDeDisco(int);
        bool grabarEnDisco();
};

#endif // CRONOGRAMA_H

//FUNCIONES GLOBALES

void ListadoCronograma();
int  BuscarIdTerminal(int);
void BuscarFechas( Cronograma  , int * , int * , int * , int*  , int *);





//------------------------------------------------

void cargarCalendario();

Fecha Calendario(int ns, int ds);   // Hay que pasarle nro de semana y dia de semana


