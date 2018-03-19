#include "categoria.h"
#include <stdio.h>

void categoriaPROC_cargar(categorias &c)
{
    char opcion;
    do
    {
        fflush(stdin);
        printf("\nIngrese una categoria:BRUJO(B), HADA(A), HECHICERO(E): ");
        scanf("%c",&opcion);
        switch (opcion)
        {
        case 'b':
            c=BRUJO;
            break;
        case 'B':
            c=BRUJO;
            break;
        case 'a':
            c=HADA;
            break;
        case 'A':
            c=HADA;
            break;
        case 'e':
            c=HECHICERO;
            break;
        case 'E':
            c=HECHICERO;
            break;
        default:
            printf("\nError al leer dato, reintente...");
            break;
        }
    }
    while (opcion != 'b' && opcion != 'B' && opcion != 'a' && opcion != 'A' && opcion != 'e' && opcion != 'E');
}

void categoriaPROC_mostrar(categorias c)
{
    switch (c)
    {
    case BRUJO:
        printf("Brujo");
        break;
    case HADA:
        printf("Hada");
        break;
    case HECHICERO:
        printf("Hechicero");
        break;
    }
}
