#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

#include "categoria.h"
#include "fecha.h"
#include "String.h"

typedef struct
{
    long int            cedula_magica;
    StringDyn           nombre;
    StringDyn           dimension_origen;
    FechaCompleta       fecha_nac;
    categorias          categoria;
    boolean             tieneAlMenosUnaHab;
    int                 cantPodsSobrenaturales;
} socio;

/*1.0
Ingresar los datos de un nuevo socio. Se debe verificar previamente que no exista otro socio registrado con la
misma cédula mágica y que su fecha de nacimiento sea válida.
*/
void socioPROC_darAltaSocio(socio &s, long int ci, boolean &isFechaBienCargada);

void socioPROC_darAltaSocioHardCodeAux(socio &s,long int &ci);

void socioPROC_darAltaSocioHardCodeAuxPARALISTA(socio &s, long int &ci);

void socioPROC_desplegarSocioInfo(socio s);

//Logica pos carga de habilidad que afecta a un socio
void socioPROC_actualizarSocioTieneAlMenosUnaHab(socio &s);

void socioPROC_actualizarSocioCantPodsSobrenaturales(socio &s);

socio socioFUNC_PARAM_cargaSocio(long int cedula_magica, StringDyn nombre, StringDyn dimension_origen, FechaCompleta fecha_nac, categorias categoria, boolean tieneAlMenosUnaHab, int cantPodsSobrenaturales);

//selectoras

long int socioFUNCselect_darCI(socio s);

void socioPROCselect_nombre(socio s, StringDyn &str);

void socioPROCselect_dimension_origen(socio s, StringDyn &str);

FechaCompleta socioFUNCselect_fecha_nac(socio s);

categorias socioFUNCselect_darCategoria(socio s);

boolean socioFUNCselect_tieneAlMenosUnaHab(socio s);

int socioFUNCselect_cantPodsSobrenaturales(socio s);

#endif // SOCIO_H_INCLUDED







