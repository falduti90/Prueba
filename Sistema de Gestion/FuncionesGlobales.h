#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

int  MenuPrincipal();
void InicioSesion();
void CrearUsuario();
bool pedirContrasenia();
void Consultas();
void DataEntry();
void Admin();
bool importarCronograma();
void exportar();
int  buscarPosicionPorUsuario(char *usuario);
void cargarCadena(char *pal, int tam);
void ListarPorSemana();
void pedirOpcionesDeFiltrado();
void Listado(int buque, int numsemana , int idagencia , int idterminal);

#endif // FUNCIONESGLOBALES_H_INCLUDED
