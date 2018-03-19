//Como menú no hereda de boolean, este código de definición para los acentos, debe repetirse

#ifdef __MINGW32__ //tildes
#define LIMPIAR "cls"
#define LETRA_A "\267"
#define LETRA_a "\240"
#define LETRA_E "\220"
#define LETRA_e "\202"
#define LETRA_I "\326"
#define LETRA_i "\241"
#define LETRA_O "\340"
#define LETRA_o "\242"
#define LETRA_U "\351"
#define LETRA_u "\243"
#define LETRA_N "\245"
#define LETRA_n "\244"
//    #define NULL

#endif // __MINGW32__

#ifdef __linux__
#define LIMPIAR "clear"
#define LETRA_A "\u00C1"
#define LETRA_a "\u00E1"
#define LETRA_E "\u00C9"
#define LETRA_e "\u00E9"
#define LETRA_I "\u00CD"
#define LETRA_i "\u00ED"
#define LETRA_O "\u00D3"
#define LETRA_o "\u00F3"
#define LETRA_U "\u00DA"
#define LETRA_u "\u00FA"
#define LETRA_N "\u00D1"
#define LETRA_n "\u00F1"
#endif // __linux__

#ifdef __APPLE__
#define LIMPIAR "clear"
#define LETRA_A "\u00C1"
#define LETRA_a "\u00E1"
#define LETRA_E "\u00C9"
#define LETRA_e "\u00E9"
#define LETRA_I "\u00CD"
#define LETRA_i "\u00ED"
#define LETRA_O "\u00D3"
#define LETRA_o "\u00F3"
#define LETRA_U "\u00DA"
#define LETRA_u "\u00FA"
#define LETRA_N "\u00D1"
#define LETRA_n "\u00F1"
#endif // __APPLE__

#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
using namespace std;


//Despliega y lee la opcion para el menu principal de XX opciones
void menusPROC_menuPrincipal(int &opcion);

//Despliega y lee la opcion para el menu secundaro (de la opcion 5 del menu principal), de XX opciones
void menusPROC_menuOpcion3(int &opcion3);

//Seccion mensajes respecto a menu

//Mensaje para indicar segun la flag, para la opcion XX - XX del menu principal
void PROC_mensajeErrorCargaVacia();

//Emite mensaje, espera anyKey y limpia la pantalla dependiendo del SO
void PROC_LimpiarYPausa();

#endif // MENUS_H_INCLUDED
