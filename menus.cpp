#include "menus.h"

void menusPROC_menuPrincipal(int &opcion)
{
    fflush(stdin);
    printf("\n**********Men%s de Opciones Principales**********\n\n", LETRA_u);
    printf("Seleccione un numero como opci%sn del men%s:", LETRA_o, LETRA_u);
    printf("\n1- Registrar un nuevo socio.");
    printf("\n2- Registrar una nueva habilidad.");
    printf("\n3- Men%s de consultas y listados.", LETRA_u);
    printf("\n4- Salir del programa y guardar datos en computador\nOpci%sn: ", LETRA_o);
    scanf("%d",&opcion);
}

void menusPROC_menuOpcion3(int &opcion3)
{
    fflush(stdin);
    printf("\n\n**********Men%s de Opciones para consultas y listados**********\n\n", LETRA_u);
    printf("Seleccione un n%smero como opci%sn del men%s:", LETRA_u, LETRA_o, LETRA_u);
    printf("\n1. Cantidad de socios por cada categor%sa.", LETRA_i);
    printf("\n2. Cantidad de habilidades por cada tipo.");
    printf("\n3. Cantidad de socios registrados, nacidos antes de una fecha elegida.");
    printf("\n4. Cantidad de habilidades registradas, dentro del rango de dos fechas elegidas (incluidas ambas fechas).");
    printf("\n5. Datos de socios registrados, ordenados por c%sdula.", LETRA_e);
    printf("\n6. Datos de socios registrados, sin habilidades manifestadas, ordenados por c%sdula.", LETRA_e);
    printf("\n7. Datos de habilidades correspondiente a un socio, ordenados cronol%sgicamente, seg%sn una c%sdula elegida.", LETRA_o, LETRA_u, LETRA_e);
    printf("\n8. Datos de habilidades registradas, manifestadas, seg%sn una fecha elegida.", LETRA_u);
    printf("\n9. Datos del socio registrado con mas poderoso (con mayor cantidad de habilidades SOBRENATURALES manifestadas).");
    printf("\n0. Salir del men%s, volver al men%s principal.\nOpci%sn: ", LETRA_u, LETRA_u, LETRA_o);
    scanf("%d",&opcion3);
}

void PROC_mensajeErrorCargaVacia()
{
    fflush(stdin);
    printf("\n***Error, para esta opci%sn debe tener cargado algun elemento previamente con el men%s principal.***", LETRA_o, LETRA_u);
    PROC_LimpiarYPausa();
}

void PROC_LimpiarYPausa()
{
    char limpiar;
    fflush(stdin);
    printf("\n\nPresione enter para continuar ");
    scanf("%c",&limpiar);
    system(LIMPIAR);
}
