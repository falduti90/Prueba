#ifndef CRONOGRAMA_H
#define CRONOGRAMA_H
#include "Fecha.h"

class Cronograma {
    public:
        char _idCronograma[50];
        Fecha _FechaRecepcionCnt;
        Fecha _FechaETA;
        Fecha _FechaETD;
        Fecha _FechacutoffFisico;
        Fecha _FechacutoffDoc;
        bool _activo;

    private:
        void setIdCronograma(char *);
        void setFechaRecepcionCnt(Fecha);
        void setFechaETA(Fecha);
        void setFechaETD(Fecha);
        void setFechaCutoffFisico(Fecha);
        void setFechaCutoffDoc(Fecha);
        void setActivo(bool);
        char *getIdCronograma();
        Fecha getFechaRecepcionCnt();
        Fecha getFechaETA();
        Fecha getFechaETD();
        Fecha getFechaCutoffFisico();
        Fecha getFechaCutoffDoc();
        bool getActivo();
        void cargar();
        void mostrar();
        bool leerDeDisco(int);
        bool grabarEnDisco();
        bool grabarEnDisco(int);
};

#endif // CRONOGRAMA_H
