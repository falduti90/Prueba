#ifndef HORARIO_H
#define HORARIO_H


class Horario
{
public:
    Horario();
    void setHora(int NuevaHora);
    void setMinutos(int NuevosMin);
    int  getHora();
    int  getMinutos();
    void Cargar();
    void Mostrar();
    bool LeerDeDisco(int pos);
    bool GrabarEnDisco();


private:
    int _Hora,_Minutos;
};

#endif // HORARIO_H
