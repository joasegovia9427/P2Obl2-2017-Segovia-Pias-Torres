#include "arbolSocios.h"

void arbolSociosFUNC_crearNull(arbolSocios &as)
{
    as = NULL;
}

/*1.0
Ingresar los datos de un nuevo socio. Se debe verificar previamente que no exista otro socio registrado con la
misma cédula mágica y que su fecha de nacimiento sea válida.
*/
boolean arbolSociosFUNC_isArbolVacio(arbolSocios as)
{
    return boolean(as==NULL);
}

//precondicion: que no este ya registrado
//orden ABB cedula
void arbolSociosPROC_agregarSocioAlArbol(arbolSocios &as, socio s)
{
    if (as == NULL)
    {
        as = new nodoSocio;
        as->info = s;
        as->Hizq = NULL;
        as->Hder = NULL;
    }
    else
    {
        if (socioFUNCselect_darCI(s) < socioFUNCselect_darCI(as->info))
        {
            arbolSociosPROC_agregarSocioAlArbol(as->Hizq,s);
        }
        else
        {
            arbolSociosPROC_agregarSocioAlArbol(as->Hder,s);
        }
    }
}

boolean arbolSociosFUNC_verificarExistenciaSocio(arbolSocios as, socio s)
{
    if (as == NULL)
        return FALSE;
    else if (socioFUNCselect_darCI(as->info) == socioFUNCselect_darCI(s))
        return TRUE;
    else if (socioFUNCselect_darCI(s) < socioFUNCselect_darCI(as->info))
        return arbolSociosFUNC_verificarExistenciaSocio(as->Hizq,s);
    else
        return arbolSociosFUNC_verificarExistenciaSocio(as->Hder,s);
}

/*3.1
Contar cuántos socios de cada categoría mágica (brujos, hadas y hechiceros) hay registrados en el sistema.
*/
void arbolSociosPROC_mostrarCategorias(arbolSocios as,int &b, int &a, int &o)
{
    if(as != NULL)
    {
        arbolSociosPROC_mostrarCategorias(as->Hizq, b, a, o);

        socio s = as->info;
        categorias c = socioFUNCselect_darCategoria(s);
        switch(c)
        {
        case BRUJO:
            b++;
            break;
        case HADA:
            a++;
            break;
        case HECHICERO:
            o++;
            break;
        }

        arbolSociosPROC_mostrarCategorias(as->Hder, b, a, o);
    }
}
/*3.3
//precondicion: fecha valida
Dada una fecha de nacimiento, contar cuántos de los socios registrados en el sistema nacieron antes de dicha fecha.
Se debe verificar previamente que la fecha ingresada sea válida.
*/
int arbolSociosPROC_mostraSociosAntesDeFecha(arbolSocios as, FechaCompleta f)
{
    if (as == NULL)
    {
        return 0;
    }
    else
    {
        if (FechaComparaFechas(socioFUNCselect_fecha_nac(as->info),f) == -1)
        {
            return 1 + arbolSociosPROC_mostraSociosAntesDeFecha(as->Hizq,f) + arbolSociosPROC_mostraSociosAntesDeFecha(as->Hder,f);
        }
        else
        {
            return arbolSociosPROC_mostraSociosAntesDeFecha(as->Hizq,f) + arbolSociosPROC_mostraSociosAntesDeFecha(as->Hder,f);
        }
    }
}

/*3.5
Listar todos los socios registrados en el sistema, ordenados por cédula de menor a mayor.
Los datos de un mismo socio (cédula mágica, nombre, fecha de nacimiento, dimensión de origen y categoría mágica)
deberán listarse todos en una misma línea.
*/
void arbolSociosPROC_mostrarSociosDetalle(arbolSocios as)
{
    // Recorrido del Árbol en Orden,ordenarlos por CI de menor a mayor CI
    if(as != NULL)
    {
        arbolSociosPROC_mostrarSociosDetalle(as->Hizq);
        socioPROC_desplegarSocioInfo(as->info);
        printf("\n");
        arbolSociosPROC_mostrarSociosDetalle(as->Hder);
    }
}

/*3.6
Listar todos aquellos socios registrados en el sistema que aún no han manifestado ninguna habilidad,
ordenados por cédula de menor a mayor. Los datos de un mismo socio (cédula mágica, nombre, fecha de nacimiento,
dimensión de origen y categoría mágica) deberán listarse todos en una misma línea.
*/
void arbolSociosPROC_mostrarSociosSinHabilidades(arbolSocios as)
{
    if(as != NULL)
    {
        arbolSociosPROC_mostrarSociosDetalle(as->Hizq);
        if(socioFUNCselect_tieneAlMenosUnaHab(as->info) == FALSE)
        {
            socioPROC_desplegarSocioInfo(as->info);
            printf("\n");
        }
        arbolSociosPROC_mostrarSociosDetalle(as->Hder);
    }
}
/*3.9
Listar los datos del socio más poderoso registrado en el sistema.
Es decir, del socio que ha manifestado la mayor cantidad de habilidades sobrenaturales de entre todos los socios registrados.
En caso de que haya varios, basta con devolver uno cualquiera de ellos.
En caso de que no haya ninguno, emitir un mensaje que así lo indique.
*/
void arbolSociosPROC_mostraSocioMasPoderoso(arbolSocios as)
{
    socio masPoderoso;
    int cantSOBRENATURALES = 0;
    arbolSociosPROC_buscarAlMasPoderoso(as, masPoderoso, cantSOBRENATURALES);
    if (cantSOBRENATURALES > 0)
    {
        printf("\nDatos Socio:\nCI Magica, Nombre, Fecha de Nacimiento, Dimension de origen, Categoria\n");
        socioPROC_desplegarSocioInfo(masPoderoso);
    }
    else
    {
        printf("No hay socio con poderes sobrenaturales");
    }
}

void arbolSociosPROC_buscarAlMasPoderoso(arbolSocios as, socio &masPoderoso, int &cantSOBRENATURALES)
{
    if(as != NULL)
    {
        arbolSociosPROC_buscarAlMasPoderoso(as->Hizq, masPoderoso, cantSOBRENATURALES);
        if(socioFUNCselect_cantPodsSobrenaturales(as->info) >= cantSOBRENATURALES )
        {
            cantSOBRENATURALES  = socioFUNCselect_cantPodsSobrenaturales(as->info);
            masPoderoso         = as->info;
        }
        arbolSociosPROC_buscarAlMasPoderoso(as->Hder, masPoderoso, cantSOBRENATURALES);
    }
}

//Logica pos carga de habilidad que afecta a un socio
void arbolSociosPROC_actualizarSocio(arbolSocios &as, long int CI, tipoHabilidad tH)
{
    boolean isEncontre = FALSE;
    arbolSocios aux = as;
    while ((aux != NULL) && (!isEncontre))
    {
        if (CI == socioFUNCselect_darCI(aux->info) )
        {
            isEncontre = TRUE;
            socioPROC_actualizarSocioTieneAlMenosUnaHab(aux->info);
            if (tH == SOBRENATURAL)
            {
                socioPROC_actualizarSocioCantPodsSobrenaturales(aux->info);
            }
        }
        else
        {
            if (CI < socioFUNCselect_darCI(aux->info) )
            {
                aux = aux->Hizq;
            }
            else
            {
                aux = aux->Hder;
            }
        }

    }
}
