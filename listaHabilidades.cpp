#include "listaHabilidades.h"

void listaHabilidadesPROC_crearLista(listaHabilidades &lh)
{
    lh = NULL;
}

/*2.0 JOAQUIN
Ingresar una nueva habilidad. Se debe verificar previamente que la cédula mágica del socio que la manifiesta esté
registrada y que la fecha de manifestación sea válida y mayor o igual a la fecha de la habilidad más reciente registrada
hasta el momento.
*/
void listaHabilidadesPROC_insfront(listaHabilidades &lh, habilidad h)
{
    listaHabilidades aux;
    aux = new nodoHabilidad;
    aux->info = h;
    aux->sig = lh;
    lh = aux;
}

//h) InsBackIter: Dada una lista y una habilidad, agrega al final de la lista. PARA ARCHIVOS
void listaHabilidadesPROC_agregarFinal(listaHabilidades &lh, habilidad h)
{
    listaHabilidades nuevo = new nodoHabilidad;
    nuevo->info = h;
    nuevo->sig = NULL;
    if (lh == NULL){
        lh = nuevo;
    }
    else
    {
        listaHabilidades aux = lh;
        while (aux->sig != NULL)
            aux = aux->sig;
        aux->sig = nuevo;
    }
}

boolean listaHabilidadesFUNC_isListaVacia(listaHabilidades lh)
{
    return boolean(lh==NULL);
}

habilidad listaHabilidadesFUNC_darPrimerElemento(listaHabilidades lh)
{
    return lh->info;
}

boolean listaHabilidadesFUNC_verificarExistenciaHabilidad(listaHabilidades lh, long int CIaCargar, StringDyn strACargar, FechaCompleta fACargar)
{
    boolean isHpertenece = FALSE;
    boolean isMismoNombre = FALSE;
    StringDyn sNodo;
    FechaCompleta fNodo;
    long int ciNodo;
    int tieneQSer0o1 = 0;

    while ((lh != NULL) && (isHpertenece == FALSE))
    {
        ciNodo = habilidadFUNCselect_darcedula_magica(lh->info);
        habilidadFUNCselect_nombre_habilidad(lh->info, sNodo);
        fNodo = habilidadFUNCselect_fecha_manifestacion(lh->info);

        tieneQSer0o1 = FechaComparaFechas(fACargar,fNodo);
        isMismoNombre = StringDyn_equal(strACargar,sNodo);
        if ((tieneQSer0o1 == 0) && ( isMismoNombre == TRUE ) && (CIaCargar == ciNodo))
        {
            isHpertenece = TRUE;
        }
        lh = lh->sig;
    }
    return isHpertenece;
    // si es true significa que ya esta registrado una habilidad para
    // el mismo socio, con el mismo nombre,y el mismo dia, entonces muestro error
}


/*3.2
Contar cuántas habilidades de cada tipo (naturales, poco naturales y
sobrenaturales) hay registradas en el sistema.
*/
void listaHabilidadesPROC_mostrarCantTipoHabilidades(listaHabilidades lh, int &n, int &p, int &s)
{
    n = 0;
    p = 0;
    s = 0;
    while(lh != NULL)
    {
        switch(habilidadFUNCselect_tipo_habilidad(lh->info))
        {
        case NATURAL:
            n++;
            break;
        case POCO_NATURAL:
            p++;
            break;
        case SOBRENATURAL:
            s++;
            break;
        }
        lh = lh->sig;
    }
}

/*3.4
//PRECONDICION: Fecha válida, f1 < f2
Dadas dos fechas, contar cuántas habilidades fueron ingresadas dentro de dicho
rango de fechas (incluidas ambas fechas).
Se debe verificar previamente que ambas fechas ingresadas sean válidas y que la
primera fecha sea menor o igual que la segunda.
*/
int listaHabilidadesFUNC_largoListaPorRangoFechas(listaHabilidades lh, FechaCompleta f1, FechaCompleta f2)
{
    int cant = 0;
    while (lh != NULL)
    {
        /**
            Función comparaFecha, devuelve:
             -1 si fecha1 < fecha2
              0 si fecha1 = fecha2 //bien
              1 si fecha1 > fecha2 //bien
        **/
        if ((FechaComparaFechas(habilidadFUNCselect_fecha_manifestacion(lh->info),f1) == 1 || FechaComparaFechas(habilidadFUNCselect_fecha_manifestacion(lh->info),f1) == 0) &&
                (FechaComparaFechas(habilidadFUNCselect_fecha_manifestacion(lh->info),f2) == -1 || FechaComparaFechas(habilidadFUNCselect_fecha_manifestacion(lh->info),f2) == 0))
            cant++;
        lh = lh->sig;
    }
    return cant;
}

/*3.7
//PRECONDICION: validar ci en la lista
Dada la cédula mágica de un socio, listar todas las habilidades correspondientes a dicho socio, ordenadas en forma
cronológica inversa (desde las más recientes hacia las más antiguas). Los datos de una misma habilidad (nombre, fecha
de manifestación, cédula mágica del socio y tipo de habilidad) deberán listarse todos en una misma línea.
Se debe verificar desde el main previamente que el socio correspondiente exista en el sistema de la lista.
*/
void listaHabilidadesPROC_mostrarHabilidadesDeUnaCI(listaHabilidades lh, long int CI)
{
    while(lh != NULL)
    {
        if(CI == habilidadFUNCselect_darcedula_magica(lh->info))
        {
            habilidadPROC_desplegar(lh->info);
            printf("\n");
        }
        lh = lh->sig;
    }
}

boolean listaHabilidadesFUNC_existeCIenLH(listaHabilidades lh, long int CI)
{
    boolean existe = FALSE;
    do
    {
        if(CI == habilidadFUNCselect_darcedula_magica(lh->info))
        {
            existe = TRUE;
        }
        else
        {
            lh = lh->sig;
        }
    }
    while((lh != NULL) && (existe == FALSE));
    return existe;
}

/*3.8
Dada una fecha, listar todas las habilidades que hayan sido manifestadas en dicha fecha.
Los datos de una misma habilidad (nombre, fecha de manifestación, cédula mágica del socio y tipo de habilidad)
deberán listarse todos en una misma línea. Se debe verificar previamente que la fecha ingresada sea válida.
*/
void listaHabilidadesPROC_mostrarHabilidadesDeUnaFecha(listaHabilidades lh, FechaCompleta f)
{
    boolean encontre=FALSE;
    while (lh != NULL && encontre==FALSE)
    {
        if (FechaComparaFechas(habilidadFUNCselect_fecha_manifestacion(lh->info), f) == 0)
        {
            encontre = TRUE;
            printf("\nDatos Habilidades:\nCI Magica, Nombre, Fecha de Manifestacion, Tipo de habilidad\n");
        }
        else
        {
            lh = lh->sig;
        }
    }

    int cant = 0;
    while (lh != NULL)
    {
        if (FechaComparaFechas(habilidadFUNCselect_fecha_manifestacion(lh->info), f) == 0)
        {
            cant++;
            habilidadPROC_desplegar(lh->info);
            printf("\n");
        }
        lh = lh->sig;
    }
    if(cant == 0)
    {
        printf("\nNo se encontraron registro en esa fecha ");
    }
}
