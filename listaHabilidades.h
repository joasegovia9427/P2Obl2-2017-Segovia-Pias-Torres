#ifndef LISTAHABILIDAD_H_INCLUDED
#define LISTAHABILIDAD_H_INCLUDED

#include "habilidad.h"

typedef struct nodoHabilidadAlias{
    habilidad info;
    nodoHabilidadAlias * sig;
}nodoHabilidad;

typedef nodoHabilidad * listaHabilidades;

void listaHabilidadesPROC_crearLista(listaHabilidades &lh);

/*2.0
Ingresar una nueva habilidad. Se debe verificar previamente que la cédula mágica del socio que la manifiesta esté
registrada y que la fecha de manifestación sea válida y mayor o igual a la fecha de la habilidad más reciente registrada
hasta el momento.
*/
void listaHabilidadesPROC_insfront(listaHabilidades &lh, habilidad h);

void listaHabilidadesPROC_agregarFinal(listaHabilidades &lh, habilidad h);

boolean listaHabilidadesFUNC_isListaVacia(listaHabilidades lh);

habilidad listaHabilidadesFUNC_darPrimerElemento(listaHabilidades lh);

boolean listaHabilidadesFUNC_verificarExistenciaHabilidad(listaHabilidades lh, long int CIaCargar, StringDyn strACargar, FechaCompleta fACargar);

/*3.2
Contar cuántas habilidades de cada tipo (naturales, poco naturales y sobrenaturales) hay registradas en el sistema.
*/
void listaHabilidadesPROC_mostrarCantTipoHabilidades(listaHabilidades lh, int &n, int &p, int &s);

/*3.4
//precondicion f1<f2
Dadas dos fechas, contar cuántas habilidades fueron ingresadas dentro de dicho rango de fechas (incluidas ambas fechas).
Se debe verificar previamente que ambas fechas ingresadas sean válidas y que la primera fecha sea menor o igual que la segunda.
*/
int listaHabilidadesFUNC_largoListaPorRangoFechas(listaHabilidades lh, FechaCompleta f1, FechaCompleta f2);

/*3.7
//precondicion validar ci en la lista
Dada la cédula mágica de un socio, listar todas las habilidades correspondientes a dicho socio, ordenadas en forma
cronológica inversa (desde las más recientes hacia las más antiguas). Los datos de una misma habilidad (nombre, fecha
de manifestación, cédula mágica del socio y tipo de habilidad) deberán listarse todos en una misma línea.
Se debe verificar desde el main previamente que el socio correspondiente exista en el sistema de la lista.
*/
void listaHabilidadesPROC_mostrarHabilidadesDeUnaCI(listaHabilidades lh, long int CI);

boolean listaHabilidadesFUNC_existeCIenLH(listaHabilidades lh, long int CI);

/*3.8
Dada una fecha, listar todas las habilidades que hayan sido manifestadas en dicha fecha.
Los datos de una misma habilidad (nombre, fecha de manifestación, cédula mágica del socio y tipo de habilidad)
deberán listarse todos en una misma línea. Se debe verificar previamente que la fecha ingresada sea válida.
*/
void listaHabilidadesPROC_mostrarHabilidadesDeUnaFecha(listaHabilidades lh, FechaCompleta f);

#endif // LISTAHABILIDAD_H_INCLUDED
