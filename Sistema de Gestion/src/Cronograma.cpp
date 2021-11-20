#include <iostream>
using namespace std;
#include <ctime>
#include "Cronograma.h"
#include "BaseCalculo.h"
#include "Buque.h"
#include "Agencia.h"
#include "Fecha.h"
#include "Region.h"
#include "rlutil.h"
#include <cstdlib>
#include <cstring>
#include <cstdio>


Cronograma::Cronograma(){
    _idCronograma[0] = 0;
    _idCronograma[1] = 0;
    _idCronograma[2] = 0;
}

Cronograma::Cronograma( int idAgencia , int idRegion , int idGiro ){
    _idCronograma[0] = idAgencia;
    _idCronograma[1] = idRegion;
    _idCronograma[2] = idGiro;
}

void Cronograma::setIdCronograma( int idAgencia , int idRegion , int idGiro ){
    _idCronograma[0] = idAgencia;
    _idCronograma[1] = idRegion;
    _idCronograma[2] = idGiro;
}


void Cronograma::setNumSemana(int num){
    _numSemana = num;

}

void Cronograma::setFechaRecepcionCnt(Fecha f){
    _fechaRecepcionCnt = f;
}

void Cronograma::setFechaETA(Fecha f){
    _fechaETA = f;

}

void Cronograma::setFechaETD(Fecha f){
        _fechaETD = f;
}

void Cronograma::setFechaCutoffFisico(Fecha f){
        _fechacutoffFisico = f;
}

void Cronograma::setFechaCutoffDoc(Fecha f){
        _fechacutoffDoc = f;
}

void Cronograma::setActivo(bool nuevoEstado){
    _activo = nuevoEstado;

}

int *Cronograma::getIdCronograma(){
    return _idCronograma;
}

Fecha Cronograma::getFechaRecepcionCnt(){
    return _fechaRecepcionCnt;
}

Fecha Cronograma::getFechaETA(){
    return _fechaETA;
}

Fecha Cronograma::getFechaETD(){
    return _fechaETD;
}

Fecha Cronograma::getFechaCutoffFisico(){
    return _fechacutoffFisico;
}

Fecha Cronograma::getFechaCutoffDoc(){
    return _fechacutoffDoc;
}

int Cronograma::getNumSemana(){
    return _numSemana;
}

bool Cronograma::getActivo(){
    return _activo;
}

void Cronograma::cargar(){
    int giro, diaETA , calculoETD , diaCTF , diaCTD , calculoRecepcionCnt;
    diaETA = calculoETD = diaCTF = diaCTD = calculoRecepcionCnt = 0;

    cout << "INGRESE NUMERO DE SEMANA: ";
    cin >> _numSemana;

    cout << "INGRESE ID AGENCIA: ";
    cin >> _idAgencia;

    cout << "INGRESE ID REGION: ";
    cin >> _idRegion;

    cout << "INGRESE ID BUQUE: ";
    cin >> _idBuque;

    cout << "INGRESE NUMERO DE VIAJE: ";
    cin >> _numeroViaje;

    giro = BuscarIdTerminal(_idBuque);
    setIdCronograma(_idAgencia , _idRegion , giro);

    Cronograma c(_idAgencia , _idRegion , giro);
    BuscarFechas(c , &diaETA , &calculoETD , &diaCTF , &diaCTD , &calculoRecepcionCnt);

    _fechaETA            = Calendario(_numSemana , diaETA);
    _fechaETD            = _fechaETA+=calculoETD;
    _fechaRecepcionCnt   = _fechaETA-=calculoRecepcionCnt;
    _fechacutoffFisico   = Calendario(_numSemana , diaCTF);
    _fechacutoffDoc      = Calendario(_numSemana , diaCTD);
    if ( _fechacutoffFisico >= _fechaETA ){
        _fechacutoffFisico   = Calendario(_numSemana-1 , diaCTF);
        _fechacutoffDoc      = Calendario(_numSemana-1 , diaCTD);
    }

}

void BuscarFechas( Cronograma crono , int *diaETA , int *calculoETD , int *diaCTF , int *diaCTD , int *calculoRecepcionCnt){
    int pos = 0;
    BaseCalculo reg;

    while(reg.leerDeDisco(pos++)){
       if (crono == reg.getIdReferencia()){
        *diaETA =  reg.getDiaETA();
        *calculoETD =  reg.getCalculoETD();
        *diaCTF =  reg.getDiaCTF();
        *diaCTD =  reg.getDiaCTD();
        *calculoRecepcionCnt =  reg.getCalculoRecepcionCnt();
        return;
       }
    }

    cout << "NO SE ENCONTRO DATOS PARA CALCULAR ESA AGENCIA/REGION/TERMINAL" << endl << endl;
}


void Cronograma::mostrar(){
    printf("%3d",_numSemana);
    cout << ", ";
    BuscarAgencia(_idAgencia);
    cout << ", ";
    BuscarRegion(_idRegion);
    cout << ", ";
    BuscarBuque(_idBuque);
    cout << ", ";
    cout << _numeroViaje << ", ";
    getFechaETA().mostrar();
    cout << ", ";
    getFechaETD().mostrar();
    cout << ", ";
    getFechaCutoffFisico().mostrar();
    cout << ", ";
    getFechaCutoffDoc().mostrar();
    cout << ", ";
    getFechaRecepcionCnt().mostrar();
}

bool Cronograma::leerDeDisco(int pos){
    FILE *p;
    p = fopen("Cronograma.dat","rb");
    if ( p == NULL ){
        cout << "No se pudo abrir el archivo";
    return false;
    }

    fseek ( p , sizeof(Cronograma)*pos , 0);
    bool leyo = fread( this , sizeof(Cronograma) , 1 , p );
    fclose(p);
    return leyo;

}

bool Cronograma::grabarEnDisco(){
    FILE *p;
    p = fopen("Cronograma.dat","ab");
    if ( p == NULL ) {
        cout << "No se pudo abrir el archivo";
        return false;
    }

    bool ok =  fwrite( this , sizeof(Cronograma) , 1 , p );
    if ( ok == true ) {
        cout << "Registro guardado"<<endl;
    }
    else{
        cout << "No se guardo el registro"<<endl;
    }
    fclose(p);
    return ok;
}

//---------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES
void ListadoCronograma() {

FILE *p;
   Cronograma reg;
   p=fopen("Cronograma.dat","rb");
    if(p==NULL){
        cout<< "No se pudo abrir el archivo";
    return ;
    }
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << " WEEK   AGENCIA   REGION   BUQUE    GIRO   VIAJE     ETA     ETD     CUT OFF DOC   CUT OFF FISICO   INICIO DE RECEPCION" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

    while(fread(&reg,sizeof(Cronograma),1,p)==1){
        reg.mostrar();
        cout << endl;
    }

    fclose(p);
}


bool Cronograma::operator ==(int *aux){

 if( _idCronograma[0] != aux[0] ) return false;
 if( _idCronograma[1] != aux[1] ) return false;
 if( _idCronograma[2] != aux[2] ) return false;

 return true;
}


//**--------------------------------


Fecha Calendario(int ns, int ds){

    Fecha c[54][8];

    time_t tSac = time(NULL);  // instante actual
    struct tm* pt1 = localtime(&tSac);
    tm tm2 = *gmtime(&tSac);   // deferencia y asignación
    int anio = tm2.tm_year+1900;

    int nroSemana = 0;
    int mes = 1;


    while ( mes <= 12){
        int dia=1;
        int z = diaSemana(anio, mes);
        int diasMes = CalcularDiasMes (mes, anio);
        while (dia <= diasMes){
            for (int j = 0 ; j < 7 ; j++){
                if (dia == 1 && j == 0) j = z;
                    if ( dia <= diasMes && mes <= 12){
                    c[nroSemana][j].setCalendario(dia,mes,anio);
                    dia++;
                    if ( j == ds && nroSemana == ns) {
                            return c[nroSemana][j];
                        }
                } else{

                dia++; }
            }
            c[nroSemana][7].setNumeroSemana(nroSemana);
            nroSemana++;
        }
        if (dia-1 != diasMes) nroSemana--;
        mes++;
       if (mes > 12){
            anio++ , mes = 1 , ns= 0 , nroSemana = 0;
        }
    }
   if (nroSemana < 53) c[nroSemana+1][7].setNumeroSemana(nroSemana+1);

}







void calendarioVacio(int m[][8], int tam){
    for (int i = 0 ; i < tam ; i++){
        for (int j = 0 ; j < 8 ; j++){
            m[i][j] = -1;
        }
    }
}




void mostrarCalendario(Fecha m[][8], int tam){

    //for (int mes=1; mes<=12; mes++){
        //cout << "  Mes : " <<  m[mes-1] << endl;
        cout << "|   Domingo\t|   Lunes\t|   Martes\t|   Miercoles\t|   Jueves\t|   Viernes\t|   Sabado\t| SEMANA\t" << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;

        for (int i = 0 ; i < tam ; i++){
            for (int j = 0 ; j < 7 ; j++){
                cout << "|  ";
                m[i][j].mostrar();
                cout << "\t";
            }
            cout << "|   ";
            cout << m[i][7].getNumeroSemana() << endl;
            cout << "--------------------------------------------------------------------------------------------------------------------------" << endl;
        }
    //}
}



