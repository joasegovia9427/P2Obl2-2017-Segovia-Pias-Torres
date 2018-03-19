#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "boolean.h"

const int MAX = 80;
typedef char * StringDyn;

void StringDyn_crear(StringDyn &s);
/* crea un string vacío */

void StringDyn_destruir(StringDyn &s);
/* libera la memoria usada por el string */

int StringDyn_largo(StringDyn s);
/* devuelve el largo del string s */

void StringDyn_copiar(StringDyn &s1, StringDyn s2);
/* copia el contenido del string s2 en s1 */

void StringDyn_scan(StringDyn &s);
/* lee el string s desde teclado */

void StringDyn_concatenar(StringDyn &s1, StringDyn s2);
/* concatena el contenido de s2 al final de s1 */

void StringDyn_swap(StringDyn &s1, StringDyn &s2);
/* intercambia los contenidos de s1 y s2 */

void StringDyn_print(StringDyn s);
/* imprime el string s por pantalla */

boolean StringDyn_menor(StringDyn s1, StringDyn s2);
/* determina si s1 es alfabéticamente menor que s2 */

boolean StringDyn_equal(StringDyn s1, StringDyn s2);
/* determina si los strings s1 y s2 son iguales */

#endif // STRING_H_INCLUDED
