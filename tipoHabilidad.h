#ifndef TIPOHABILIDAD_H_INCLUDED
#define TIPOHABILIDAD_H_INCLUDED
#include <stdio.h>

typedef enum {NATURAL, POCO_NATURAL, SOBRENATURAL}tipoHabilidad;

// Carga de un tipoHabilidad por teclado
void tipoHabilidadPROC_carga(tipoHabilidad &th);

// Despliegue de un tipoHabilidad por pantalla
void tipoHabilidadPROC_mostrar(tipoHabilidad th);

#endif // TIPOHABILIDAD_H_INCLUDED
