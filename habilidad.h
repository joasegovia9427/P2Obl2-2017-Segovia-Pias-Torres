#ifndef HABILIDAD_H_INCLUDED
#define HABILIDAD_H_INCLUDED

#include "tipoHabilidad.h"
#include "String.h"
#include "fecha.h"

typedef struct{
	long int        cedula_magica;
	StringDyn       nombre_habilidad;
	FechaCompleta   fecha_manifestacion;
	tipoHabilidad   tipo_habilidad;
}habilidad;

/*2.0
Ingresar una nueva habilidad. Se debe verificar previamente que la cédula mágica del socio que la manifiesta esté
registrada y que la fecha de manifestación sea válida y mayor o igual a la fecha de la habilidad más reciente registrada
hasta el momento.
*/
void habilidadPROC_cargar(habilidad &h, long int CI, StringDyn nombre_habilidad, FechaCompleta f);

void habilidadPROC_cargarHardCodeAux(habilidad &h, long int CI, StringDyn &nombre_habilidad, FechaCompleta &f, FechaCompleta fUltimaHabilidad, boolean &isCargoBienLaFecha);

void habilidadPROC_cargarHardCodeAuxSinControlUF(habilidad &h, long int CI, StringDyn &nombre_habilidad, FechaCompleta &f, boolean &isCargoBienLaFecha);

void habilidadPROC_desplegar(habilidad h);

habilidad habilidadFUNC_PARAM_cargaHabilidad(long int cedula_magica, StringDyn nombre_habilidad, FechaCompleta fecha_manifestacion, tipoHabilidad tipo_habilidad);

//selectoras
long int habilidadFUNCselect_darcedula_magica(habilidad h);

void habilidadFUNCselect_nombre_habilidad(habilidad h, StringDyn &s);

FechaCompleta habilidadFUNCselect_fecha_manifestacion(habilidad h);

tipoHabilidad habilidadFUNCselect_tipo_habilidad(habilidad h);

#endif // HABILIDAD_H_INCLUDED
