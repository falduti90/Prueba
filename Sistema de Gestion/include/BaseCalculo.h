#ifndef BASECALCULO_H                   ////NOSE SI PARA EL CASO DE ALGUNO TIENE QUE SER TIPO FECHA...
#define BASECALCULO_H

//Dom 0,  Lun 1, Mart 2, Mier 3, Juev 4, Vier 5, Sab 6};

class BaseCalculo{
    public:
        BaseCalculo();
        //void setIdReferencia( );  ME PARECE QUE EN EL PROGRAMA NO ES NECESARIO
        void setidAgencia ( int idAgencia );
        void setidRegion ( int idRegion );
        void setidGiro ( int idGiro );
        void setCalculoETA ( int diaSem );
        void setCalculoETD ( int sumaDias );
        void setCalculoCTF ( int diaSem );
        void setHoraCTF ( int hora );
        void setCalculoCTD ( int diaSem );
        void setHoraCTD ( int hora );
        void setCalculoRecepcionCnt ( int restaDias );
        int getidAgencia ();
        int getidRegion ();
        int getidGiro ();
        int getCalculoETA ();
        int getCalculoETD ();
        int getCalculoCTF ();
        int getHoraCTF ();
        int getCalculoCTD ();
        int getHoraCTD ();
        int getCalculoRecepcionCnt ();
        void cargar();
        void mostrar();
        bool leerDeDisco(int pos);
        bool grabarEnDisco();
        bool grabarEnDisco(int);

    private:
        //char _idReferencia[100];   // TODO: se arma de la concat de  agencia region y giro. Hay q dejar el atributo?
        int _idAgencia;
        int _idRegion;
        int _idGiro;           // TODO : ¿Sale  DE agencia?
        int _calculoETA;  // Día de la semana que es la ETA. Ejemplo: miercoles (INT Xq usa número de día)
        int _calculoETD;       // Cantidad de días que se le suma a la ETA. Ejemplo: ETD = ETA + 2
        int _calculoCTF;       // Cut off físico. Suele ser un día de la semana anterior a la ETA/ETD. Ejemplo: miercoles
        int _horaCTF;
        int _calculoCTD;       // Cut off documental. Suele ser un día de la semana anterior a la ETA/ETD, previo CTF. Ejemplo: miercoles
        int _horaCTD;
        int _calculoRecepcionCnt;       // Suele ser 5 a 7 días antes de la ETA o del COF, según agencia

};

#endif // BASECALCULO_H
