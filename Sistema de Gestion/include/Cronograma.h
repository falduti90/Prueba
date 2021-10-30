#ifndef CRONOGRAMA_H
#define CRONOGRAMA_H
#include "Fecha.h"
#include <string.h>

class Cronograma {
    private:
        char _idCronograma[100];
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


    public:
        void setIdCronograma(char *idCronograma);
        void setFechaRecepcionCnt(Fecha f);
        void setFechaETA(Fecha f);
        void setFechaETD(Fecha f);
        void setFechaCutoffFisico(Fecha f);
        void setFechaCutoffDoc(Fecha f);
        void setNumSemana(int num);
        void setActivo(bool);
        char *getIdCronograma();
        Fecha getFechaRecepcionCnt();
        Fecha getFechaETA();
        Fecha getFechaETD();
        Fecha getFechaCutoffFisico();
        Fecha getFechaCutoffDoc();
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
void BuscarBuque(int);
void BuscarAgencia(int);

