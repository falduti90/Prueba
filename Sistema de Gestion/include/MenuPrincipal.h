#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H
#include <string.h>

class Usuario{
    private :
        int  _categoria;
        char _usuario[30], _contrasenia[30];
        char _usuarioAdmin[30], _contraseniaAdmin[30];
    public  :
        Usuario();
        void  setCategoria(int categoria){_categoria = categoria;}
        void  setUsuario(char *usuario){strcpy(_usuario, usuario);}
        void  setContrasenia(char *contrasenia){strcpy(_contrasenia, contrasenia);}
        void  setUsuarioAdmin(char *usuarioAdmin){strcpy(_usuarioAdmin, usuarioAdmin);}
        void  setContraseniaAdmin(char *contraseniaAdmin){strcpy(_contraseniaAdmin, contraseniaAdmin);}
        int   getCategoria(){return _categoria;}
        char *getUsuario(){return _usuario;}
        char *getContrasenia(){return _contrasenia;}
        char *getUsuarioAdmin(){return _usuarioAdmin;}
        char *getContraseniaAdmin(){return _contraseniaAdmin;}
        bool  grabarEnDisco();
        bool  leerDeDisco(int);
};
int  MenuPrincipal();
void InicioSesion();
void CrearUsuario();
bool pedirContrasenia();
int  main();
void Consultas();
void DataEntry();
void Admin();
void mostrar();


#endif // MENUPRINCIPAL_H
