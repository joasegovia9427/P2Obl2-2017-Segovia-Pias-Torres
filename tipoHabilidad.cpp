#include "tipoHabilidad.h"

// Carga de un tipoHabilidad por teclado
void tipoHabilidadPROC_carga(tipoHabilidad &th)
{
    char opcion;
    do
    {
        fflush(stdin);
        printf("\nIngrese un tipo de habilidad:NATURAL(N), POCO_NATURAL(P), SOBRENATURAL(S)): ");
        scanf("%c",&opcion);
        switch (opcion)
        {
        case 's':
            th=SOBRENATURAL;
            break;
        case 'S':
            th=SOBRENATURAL;
            break;
        case 'p':
            th=POCO_NATURAL;
            break;
        case 'P':
            th=POCO_NATURAL;
            break;
        case 'n':
            th=NATURAL;
            break;
        case 'N':
            th=NATURAL;
            break;
        default:
            printf("\nError al leer dato, reintente...");
            break;
        }
    }
    while (opcion != 'S' && opcion != 's' && opcion != 'N' && opcion != 'n' && opcion != 'P' && opcion != 'p');
}

// Despliegue de un tipoHabilidad por pantalla
void tipoHabilidadPROC_mostrar(tipoHabilidad th)
{
    switch (th)
    {
    case NATURAL:
        printf(" NATURAL");
        break;
    case POCO_NATURAL:
        printf(" POCO_NATURAL");
        break;
    case SOBRENATURAL:
        printf(" SOBRENATURAL");
        break;
    }
}
