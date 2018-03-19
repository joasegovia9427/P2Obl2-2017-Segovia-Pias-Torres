#ifndef ARBOLSOCIOS_H_INCLUDED
#define ARBOLSOCIOS_H_INCLUDED

#include "socio.h"
#include "listaHabilidades.h"

typedef struct nodoSocioAlias{
    socio info;
    nodoSocioAlias * Hizq;
    nodoSocioAlias * Hder;
}nodoSocio;

typedef nodoSocio *arbolSocios;

void arbolSociosFUNC_crearNull(arbolSocios &as);

/*1.0
Ingresar los datos de un nuevo socio. Se debe verificar previamente que no exista otro socio registrado con la
misma cédula mágica y que su fecha de nacimiento sea válida.
*/
boolean arbolSociosFUNC_isArbolVacio(arbolSocios as);

void arbolSociosPROC_agregarSocioAlArbol(arbolSocios &as, socio s);

boolean arbolSociosFUNC_verificarExistenciaSocio(arbolSocios as, socio s);

/*3.1
Contar cuántos socios de cada categoría mágica (brujos, hadas y hechiceros) hay registrados en el sistema.
*/
void arbolSociosPROC_mostrarCategorias(arbolSocios as,int &b, int &a, int &o);

/*3.3
Dada una fecha de nacimiento, contar cuántos de los socios registrados en el sistema nacieron antes de dicha fecha.
Se debe verificar previamente que la fecha ingresada sea válida.
*/
int arbolSociosPROC_mostraSociosAntesDeFecha(arbolSocios as, FechaCompleta f);

/*3.5
Listar todos los socios registrados en el sistema, ordenados por cédula de menor a mayor.
Los datos de un mismo socio (cédula mágica, nombre, fecha de nacimiento, dimensión de origen y categoría mágica)
deberán listarse todos en una misma línea.
*/
void arbolSociosPROC_mostrarSociosDetalle(arbolSocios as);

/*3.6
Listar todos aquellos socios registrados en el sistema que aún no han manifestado ninguna habilidad,
ordenados por cédula de menor a mayor. Los datos de un mismo socio (cédula mágica, nombre, fecha de nacimiento,
dimensión de origen y categoría mágica) deberán listarse todos en una misma línea.
*/
void arbolSociosPROC_mostrarSociosSinHabilidades(arbolSocios as);

/*3.9
Listar los datos del socio más poderoso registrado en el sistema.
Es decir, del socio que ha manifestado la mayor cantidad de habilidades sobrenaturales de entre todos los socios registrados.
En caso de que haya varios, basta con devolver uno cualquiera de ellos.
En caso de que no haya ninguno, emitir un mensaje que así lo indique.
*/
void arbolSociosPROC_mostraSocioMasPoderoso(arbolSocios as);

void arbolSociosPROC_buscarAlMasPoderoso(arbolSocios as, socio &masPoderoso, int &cantSOBRENATURALES);

void arbolSociosPROC_actualizarSocio(arbolSocios &as, long int CI, tipoHabilidad tH);


socio arbolSociosFUNC_darRaiz(arbolSocios as);

arbolSocios arbolSociosFUNC_subArbolHijoIzq(arbolSocios as);

arbolSocios arbolSociosFUNC_subArbolHijoDer(arbolSocios as);

//cons
arbolSocios arbolSociosFUNC_consDosArbolesDiferentes(arbolSocios as1, arbolSocios as2, socio s);

//socio arbolSociosFUNC_verificarExistenciaSocio(arbolSocios as, long int CI);

#endif // ARBOLSOCIOS_H_INCLUDED

