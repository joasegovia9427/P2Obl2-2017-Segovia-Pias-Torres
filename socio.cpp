#include "socio.h"

/*1.0
Ingresar los datos de un nuevo socio. Se debe verificar previamente que no exista otro socio registrado con la
misma cédula mágica y que su fecha de nacimiento sea válida.
*/
void socioPROC_darAltaSocio(socio &s, long int ci, boolean &isFechaBienCargada)
{
    int intentos = 0;
    boolean isValid;
    isFechaBienCargada = FALSE;
    s.cedula_magica = ci;
    StringDyn_crear(s.nombre);
    fflush(stdin);
    printf("\nIngrese nombre del socio: ");
    StringDyn_scan(s.nombre);
    StringDyn_crear(s.dimension_origen);
    fflush(stdin);
    printf("\nIngrese nombre de dimension de origen del socio: ");
    StringDyn_scan(s.dimension_origen);
    fflush(stdin);
    do
    {
        intentos++;
        isValid=FALSE;
        fflush(stdin);
        printf("\nIngrese fecha de naciemiento del socio: ");
        FechaCompletaPROC_Carga(s.fecha_nac);
        isValid = FechaCompletaFUNC_IsValid(s.fecha_nac);
        if (isValid == FALSE)
        {
            printf("\nError, fecha no valida.");
        }
        else
        {
            printf("\nIngrese categoria del socio: ");
            categoriaPROC_cargar(s.categoria);
            s.tieneAlMenosUnaHab = FALSE;
            s.cantPodsSobrenaturales = 0;
            isFechaBienCargada = TRUE;
        }
        fflush(stdin);
    }
    while (isValid == FALSE && intentos <= INTENTOS);
}

void socioPROC_darAltaSocioHardCodeAux(socio &s, long int &ci)
{
    printf("\nIngrese numero que identificara al socio (CI Magica): ");
    scanf("%ld",&ci);
    s.cedula_magica = ci;
}
void socioPROC_darAltaSocioHardCodeAuxPARALISTA(socio &s, long int &ci)
{
    printf("\nIngrese numero (CI Magica) al cual pertenecera esta habilidad: ");
    scanf("%ld",&ci);
    s.cedula_magica = ci;
}

void socioPROC_desplegarSocioInfo(socio s)
{
    printf("%ld",s.cedula_magica);
    printf(", ");
    StringDyn_print(s.nombre);
    printf(", ");
    StringDyn_print(s.dimension_origen);
    printf(", ");
    FechaCompletaPROC_Desplegado(s.fecha_nac);
    printf(", ");
    categoriaPROC_mostrar(s.categoria);
}

//Logica pos carga de habilidad que afecta a un socio
void socioPROC_actualizarSocioTieneAlMenosUnaHab(socio &s)
{
    s.tieneAlMenosUnaHab = TRUE;
}

void socioPROC_actualizarSocioCantPodsSobrenaturales(socio &s)
{
    s.cantPodsSobrenaturales ++;
}

socio socioFUNC_PARAM_cargaSocio(long int cedula_magica, StringDyn nombre, StringDyn dimension_origen, FechaCompleta fecha_nac, categorias categoria, boolean tieneAlMenosUnaHab, int cantPodsSobrenaturales)
{
    socio s;
    s.nombre                     = nombre;
    s.dimension_origen           = dimension_origen;
    s.cedula_magica              = cedula_magica;
    s.fecha_nac                  = fecha_nac;
    s.categoria                  = categoria;
    s.tieneAlMenosUnaHab         = tieneAlMenosUnaHab;
    s.cantPodsSobrenaturales     = cantPodsSobrenaturales;
    return s;
}

//selectoras

long int socioFUNCselect_darCI(socio s)
{
    return s.cedula_magica;
}

void socioPROCselect_nombre(socio s, StringDyn &str)
{
    StringDyn_copiar(str, s.nombre);
}

void socioPROCselect_dimension_origen(socio s, StringDyn &str)
{
    StringDyn_copiar(str, s.dimension_origen);
}

FechaCompleta socioFUNCselect_fecha_nac(socio s)
{
    return s.fecha_nac;
}

categorias socioFUNCselect_darCategoria(socio s)
{
    return s.categoria;
}

boolean socioFUNCselect_tieneAlMenosUnaHab(socio s)
{
    return s.tieneAlMenosUnaHab;
}

int socioFUNCselect_cantPodsSobrenaturales(socio s)
{
    return s.cantPodsSobrenaturales;
}
