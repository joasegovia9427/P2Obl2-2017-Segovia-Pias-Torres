#include "String.h"

void StringDyn_crear(StringDyn &s)
{
    s = new char[1];
    s[0] = '\0';
}

void StringDyn_destruir(StringDyn &s)
{
    delete [] s;
    s = NULL;
}

int StringDyn_largo(StringDyn s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

void StringDyn_copiar(StringDyn &s1,StringDyn s2)
{
    int i = 0;
    int largo = StringDyn_largo(s2) + 1;
    delete [] s1;
    s1 = new char[largo];
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void StringDyn_scan (StringDyn &s)
{
    StringDyn aux = new char[MAX];
    int i=0;
    char c;
    scanf("%c", &c);
    while((c!= '\n') && (i < MAX-1))
    {
        aux[i] = c;
        i++;
        scanf ("%c", &c);
    }
    aux[i] = '\0';
    StringDyn_copiar(s,aux);
    StringDyn_destruir(aux);

}

void StringDyn_concatenar(StringDyn &s1,StringDyn s2)
{
    StringDyn aux;
    StringDyn_crear(aux);
    StringDyn_copiar(aux, s1);
    int largo = StringDyn_largo(s1) + StringDyn_largo(s2) + 1;
    if (largo > MAX)
        largo = MAX;
    delete [] s1;
    s1 = new char[largo];
    int i = 0;
    while (aux[i] != '\0')
    {
        s1[i] = aux[i];
        i++;
    }
    int j = 0;
    while (s2[j] != '\0' && i < MAX-1)
    {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
    StringDyn_destruir(aux);
}

void StringDyn_swap(StringDyn &s1, StringDyn &s2)
{
    StringDyn aux;
    aux = s1;
    s1 = s2;
    s2 = aux;
}

void StringDyn_print(StringDyn s)
{
    fflush(stdin);
    int i = 0;
    while(s[i]!= '\0')
    {
        fflush(stdout);
        printf("%c", s[i]);
        i++;
    }
}

boolean StringDyn_menor (StringDyn s1, StringDyn s2)
{
    int i = 0;
    boolean encontre = FALSE;
    boolean menor = FALSE;
    while ((!encontre) && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
            encontre = TRUE;
        if (s1[i] < s2[i])
            menor = TRUE;
        i++;
    }
    if ((!encontre) && (s2[i]!='\0'))
        menor = TRUE;
    return menor;
}

boolean StringDyn_equal(StringDyn s1,StringDyn s2)
{
    int i = 0;
    boolean iguales = TRUE;
    while (iguales && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
            iguales = FALSE;
        i++;
    }
    if ((s1[i] != '\0') || (s2[i] != '\0'))
        iguales = FALSE;
    return iguales;
}
