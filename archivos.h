#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include "arbolSocios.h"
#include "listaHabilidades.h"

void archivoFUNC_inicializaciones(listaHabilidades &lhMEM, arbolSocios &asMEM);

// ===============================================================================
// METODOS COMUNES
// ===============================================================================

void archivoPROC_bajarFecha(FechaCompleta fecha, FILE * archivo);

void archivoPROC_levantarFecha(FechaCompleta &fecha, FILE * archivo);

void archivoPROC_bajarString(StringDyn s, FILE * archivo);

void archivoPROC_levantarString(StringDyn &s, FILE * archivo);

void archivoPROC_bajarCategoria(categorias c, FILE * archivo);

void archivoPROC_levantarCategoria(categorias &c, FILE * archivo);

void archivoPROC_bajarTipoHabilidad(tipoHabilidad th, FILE * archivo);

void archivoPROC_levantarTipoHabilidad(tipoHabilidad &th, FILE * archivo);

void archivoPROC_bajarBoolean(boolean b, FILE * archivo);

void archivoPROC_levantarBoolean(boolean &b, FILE * archivo);

// ===============================================================================
// METODOS ARBOL:
// ===============================================================================

boolean archivoFUNC_arbolSocios_isExisteArchivo();

void archivoPROC_arbolSocios_crearArchivo();

boolean archivoFUNC_arbolSocios_isVacioArchivo();

// ===============================================================================

void archivoPROC_bajarSocio(socio s, FILE * archivo);

void archivoPROC_levantarSocio(socio &s, FILE * archivo);

void archivoPROC_arbolSocios_BajarArbol_al_Archivo_Aux(arbolSocios as, FILE * f);

void archivoPROC_arbolSocios_BajarArbol_al_Archivo(arbolSocios as);

void archivoPROC_arbolSocios_LevantarArbol_a_Memoria(arbolSocios &as);

// ===============================================================================
// METODOS LISTA:
// ===============================================================================

boolean archivoFUNC_listaHabilidades_isExisteArchivo();

void archivoPROC_listaHabilidades_crearArchivo();

boolean archivoFUNC_listaHabilidades_isVacioArchivo();

void archivoPROC_listaHabilidades_bajarHabilidad(habilidad h, FILE * archivo);

void archivoPROC_listaHabilidades_levantarHabilidad(habilidad &h, FILE * archivo);

void archivoPROC_listaHabilidades_BajarLista_al_Archivo(listaHabilidades lh);

void archivoPROC_listaHabilidades_LevantarLista_a_Memoria(listaHabilidades &lh);

#endif // ARCHIVOS_H_INCLUDED
