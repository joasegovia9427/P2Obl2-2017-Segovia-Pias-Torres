#include "habilidad.h"

/*2.0
Ingresar una nueva habilidad. Se debe verificar previamente que la cédula mágica del socio que la manifiesta esté
registrada y que la fecha de manifestación sea válida y mayor o igual a la fecha de la habilidad más reciente registrada
hasta el momento.
*/
void habilidadPROC_cargar(habilidad &h, long int CI, StringDyn nombre_habilidad, FechaCompleta f)
{
    h.cedula_magica = CI;
    StringDyn_crear(h.nombre_habilidad);
    StringDyn_copiar(h.nombre_habilidad, nombre_habilidad);
    h.fecha_manifestacion = f;
    fflush(stdin);
    printf("\nIngrese tipo de habilidad: ");
    tipoHabilidadPROC_carga(h.tipo_habilidad);
}

void habilidadPROC_cargarHardCodeAux(habilidad &h, long int CI, StringDyn &nombre_habilidad, FechaCompleta &f, FechaCompleta fUltimaHabilidad, boolean &isCargoBienLaFecha)
{
    boolean isValid;
    isCargoBienLaFecha = FALSE;
    int tieneQSer0o1 = -1;
    h.cedula_magica = CI;
    int intentos=0;
    StringDyn_crear(nombre_habilidad);
    fflush(stdin);
    printf("\nIngrese nombre de la habilidad: ");
    StringDyn_scan(nombre_habilidad);
    fflush(stdin);
    do
    {
        isValid=FALSE;
        intentos++;
        fflush(stdin);
        printf("\nIngrese fecha de manifestacion de la habilidad: ");
        FechaCompletaPROC_Carga(f);
        isValid = FechaCompletaFUNC_IsValid(f);
        if (isValid == FALSE)
        {
            printf("\nError, fecha no valida.");
        }
        else
        {
            tieneQSer0o1 = FechaComparaFechas(f,fUltimaHabilidad);
            if (tieneQSer0o1 == -1)
            {
                isValid = FALSE;
                printf("\nError, fecha no valida, reingrese fecha mayor o igual a la fecha de la habilidad m%ss reciente registrada hasta el momento.", LETRA_a);
                printf("\nUltima fecha ingresada: ");
                FechaCompletaPROC_Desplegado(fUltimaHabilidad);
            }
            else
            {
                h.fecha_manifestacion = f;
                isCargoBienLaFecha = TRUE;
            }
        }
        fflush(stdin);
    }
    while (isValid == FALSE && intentos <= INTENTOS);
}

void habilidadPROC_cargarHardCodeAuxSinControlUF(habilidad &h, long int CI, StringDyn &nombre_habilidad, FechaCompleta &f, boolean &isCargoBienLaFecha)
{

    isCargoBienLaFecha = FALSE;
    boolean isValid;
    h.cedula_magica = CI;
    int intentos=0;
    StringDyn_crear(nombre_habilidad);
    fflush(stdin);
    printf("\nIngrese nombre de la habilidad: ");
    StringDyn_scan(nombre_habilidad);
    fflush(stdin);

    do
    {
        isValid=FALSE;
        fflush(stdin);
        printf("\nIngrese fecha de manifestacion de la habilidad: ");
        FechaCompletaPROC_Carga(f);
        isValid = FechaCompletaFUNC_IsValid(f);
        if (isValid == FALSE)
        {
            printf("\nError, fecha no valida.");
        }
        else
        {
            h.fecha_manifestacion = f;
            isCargoBienLaFecha = TRUE;
        }
        fflush(stdin);
        intentos++;
    }
    while (isValid == FALSE && intentos <= INTENTOS);
}

void habilidadPROC_desplegar(habilidad h)
{
    printf("%ld",h.cedula_magica);
    printf(", ");
    StringDyn_print(h.nombre_habilidad);
    printf(", ");
    FechaCompletaPROC_Desplegado(h.fecha_manifestacion);
    printf(", ");
    tipoHabilidadPROC_mostrar(h.tipo_habilidad);
}

habilidad habilidadFUNC_PARAM_cargaHabilidad(long int cedula_magica, StringDyn nombre_habilidad, FechaCompleta fecha_manifestacion, tipoHabilidad tipo_habilidad)
{
    habilidad h;
    h.cedula_magica         = cedula_magica;
    h.nombre_habilidad      = nombre_habilidad;
    h.fecha_manifestacion   = fecha_manifestacion;
    h.tipo_habilidad        = tipo_habilidad;
    return h;
}

//selectoras
long int habilidadFUNCselect_darcedula_magica(habilidad h)
{
    return h.cedula_magica;
}

void habilidadFUNCselect_nombre_habilidad(habilidad h, StringDyn &str)
{
    str = h.nombre_habilidad;
}

FechaCompleta habilidadFUNCselect_fecha_manifestacion(habilidad h)
{
    return h.fecha_manifestacion;
}

tipoHabilidad habilidadFUNCselect_tipo_habilidad(habilidad h)
{
    return h.tipo_habilidad;
}
