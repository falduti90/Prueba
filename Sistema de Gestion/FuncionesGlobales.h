#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

int  MenuPrincipal();
void InicioSesion();
void CrearUsuario();
bool pedirContrasenia();
void Consultas();
void DataEntry();
void Admin();
void importar();
void exportar();
int  buscarPosicionPorUsuario(char *usuario);
void cargarCadena(char *pal, int tam);

#endif // FUNCIONESGLOBALES_H_INCLUDED
