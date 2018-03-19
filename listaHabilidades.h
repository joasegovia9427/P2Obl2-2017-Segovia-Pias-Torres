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
Ingresar una nueva habilidad. Se debe verificar previamente que la c�dula m�gica del socio que la manifiesta est�
registrada y que la fecha de manifestaci�n sea v�lida y mayor o igual a la fecha de la habilidad m�s reciente registrada
hasta el momento.
*/
void listaHabilidadesPROC_insfront(listaHabilidades &lh, habilidad h);

void listaHabilidadesPROC_agregarFinal(listaHabilidades &lh, habilidad h);

boolean listaHabilidadesFUNC_isListaVacia(listaHabilidades lh);

habilidad listaHabilidadesFUNC_darPrimerElemento(listaHabilidades lh);

boolean listaHabilidadesFUNC_verificarExistenciaHabilidad(listaHabilidades lh, long int CIaCargar, StringDyn strACargar, FechaCompleta fACargar);

/*3.2
Contar cu�ntas habilidades de cada tipo (naturales, poco naturales y sobrenaturales) hay registradas en el sistema.
*/
void listaHabilidadesPROC_mostrarCantTipoHabilidades(listaHabilidades lh, int &n, int &p, int &s);

/*3.4
//precondicion f1<f2
Dadas dos fechas, contar cu�ntas habilidades fueron ingresadas dentro de dicho rango de fechas (incluidas ambas fechas).
Se debe verificar previamente que ambas fechas ingresadas sean v�lidas y que la primera fecha sea menor o igual que la segunda.
*/
int listaHabilidadesFUNC_largoListaPorRangoFechas(listaHabilidades lh, FechaCompleta f1, FechaCompleta f2);

/*3.7
//precondicion validar ci en la lista
Dada la c�dula m�gica de un socio, listar todas las habilidades correspondientes a dicho socio, ordenadas en forma
cronol�gica inversa (desde las m�s recientes hacia las m�s antiguas). Los datos de una misma habilidad (nombre, fecha
de manifestaci�n, c�dula m�gica del socio y tipo de habilidad) deber�n listarse todos en una misma l�nea.
Se debe verificar desde el main previamente que el socio correspondiente exista en el sistema de la lista.
*/
void listaHabilidadesPROC_mostrarHabilidadesDeUnaCI(listaHabilidades lh, long int CI);

boolean listaHabilidadesFUNC_existeCIenLH(listaHabilidades lh, long int CI);

/*3.8
Dada una fecha, listar todas las habilidades que hayan sido manifestadas en dicha fecha.
Los datos de una misma habilidad (nombre, fecha de manifestaci�n, c�dula m�gica del socio y tipo de habilidad)
deber�n listarse todos en una misma l�nea. Se debe verificar previamente que la fecha ingresada sea v�lida.
*/
void listaHabilidadesPROC_mostrarHabilidadesDeUnaFecha(listaHabilidades lh, FechaCompleta f);

#endif // LISTAHABILIDAD_H_INCLUDED
