#ifndef HORARIO_H
#define HORARIO_H


class Horario{
public:
    Horario();
    void setHora(int nuevaHora);
    void setMinutos(int nuevosMin);
    int  getHora();
    int  getMinutos();
    void cargar();
    void mostrar();
    bool leerDeDisco(int pos);
    bool grabarEnDisco();

private:
    int _hora,_minutos;
};

#endif // HORARIO_H
