#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED
#include "Cronograma.h"
#include <bits/stdc++.h>
using namespace std;

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
void Listado(int buque, int numsemana , int idagencia , int idterminal, bool orden, bool op);
string converToString(char *vec, int tam);
bool exportarBaseDeCalculo();
void ExportarCronograma (int buque, int numsemana , int idagencia , int idterminal, Cronograma *vecList, int tam);
bool importarBaseCalculo();

#endif // FUNCIONESGLOBALES_H_INCLUDED
