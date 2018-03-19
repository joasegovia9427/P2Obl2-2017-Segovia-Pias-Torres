#include "archivos.h"

void archivoFUNC_inicializaciones(listaHabilidades &lhMEM, arbolSocios &asMEM)
{
    ////LISTA
    if (archivoFUNC_listaHabilidades_isExisteArchivo() == FALSE)
    {
        archivoPROC_listaHabilidades_crearArchivo();
    }
    else
    {
        if (archivoFUNC_listaHabilidades_isVacioArchivo() == FALSE)
        {
            //si el archivo esta creado y no vacio, cargo los datos a memoria
            archivoPROC_listaHabilidades_LevantarLista_a_Memoria(lhMEM);
        }
    }
    ////ARBOL
    if (archivoFUNC_arbolSocios_isExisteArchivo() == FALSE)
    {
        archivoPROC_arbolSocios_crearArchivo();
    }
    else
    {
        if (archivoFUNC_arbolSocios_isVacioArchivo() == TRUE)
        {
            //si el archivo esta creado y no vacio, cargo los datos a memoria
            archivoPROC_arbolSocios_LevantarArbol_a_Memoria(asMEM);
        }
    }
}

// ===============================================================================
// METODOS COMUNES
// ===============================================================================

void archivoPROC_bajarFecha(FechaCompleta fecha, FILE * archivo)
{
    fwrite(&fecha.dia, sizeof(int),1,archivo);
    fwrite(&fecha.mes, sizeof(int),1,archivo);
    fwrite(&fecha.anio, sizeof(int),1,archivo);
}

void archivoPROC_levantarFecha(FechaCompleta &fecha, FILE * archivo)
{
    fread(&fecha.dia, sizeof(int),1,archivo);
    fread(&fecha.mes, sizeof(int),1,archivo);
    fread(&fecha.anio, sizeof(int),1,archivo);
}

void archivoPROC_bajarString(StringDyn s, FILE * archivo)
{
    int i=0;
    while(s[i] != '\0')
    {
        fwrite(&s[i], sizeof(char),1,archivo);
        i++;
    }
    fwrite(&s[i], sizeof(char),1,archivo);
}

void archivoPROC_levantarString(StringDyn &s, FILE * archivo)
{
    int i = 0;
    StringDyn aux;
    aux = new char[MAX];
    fread(&aux[i], sizeof(char),1,archivo);
    while(!feof(archivo) && (aux[i] != '\0'))
    {
        i++;
        fread(&aux[i], sizeof(char),1,archivo);
    }
    StringDyn_copiar(s, aux);
    delete [] aux;
}

void archivoPROC_bajarCategoria(categorias c, FILE * archivo)
{
    int id_cat = 0;
    switch (c)
    {
    case BRUJO:
        id_cat = 0;
        break;
    case HADA:
        id_cat = 1;
        break;
    case HECHICERO:
        id_cat = 2;
        break;
    }
    fwrite(&id_cat, sizeof(int),1,archivo);
}

void archivoPROC_levantarCategoria(categorias &c, FILE * archivo)
{
    int id_cat = 0;
    fread(&id_cat, sizeof(int),1,archivo);
    switch (id_cat)
    {
    case 0:
        c = BRUJO;
        break;
    case 1:
        c = HADA;
        break;
    case 2:
        c = HECHICERO;
        break;
    }
}

void archivoPROC_bajarTipoHabilidad(tipoHabilidad th, FILE * archivo)
{
    int id_th = 0;
    switch (th)
    {
    case NATURAL:
        id_th = 0;
        break;
    case POCO_NATURAL:
        id_th = 1;
        break;
    case SOBRENATURAL:
        id_th = 2;
        break;
    }
    fwrite(&id_th, sizeof(int),1,archivo);
}

void archivoPROC_levantarTipoHabilidad(tipoHabilidad &th, FILE * archivo)
{
    int id_th = 0;
    fread(&id_th, sizeof(int),1,archivo);
    switch (id_th)
    {
    case 0:
        th = NATURAL;
        break;
    case 1:
        th = POCO_NATURAL;
        break;
    case 2:
        th = SOBRENATURAL;
        break;
    }
}

void archivoPROC_bajarBoolean(boolean b, FILE * archivo)
{
    int id_b = 0;
    switch (b)
    {
    case FALSE:
        id_b = 0;
        break;
    case TRUE:
        id_b = 1;
        break;
    }
    fwrite(&id_b, sizeof(int),1,archivo);
}

void archivoPROC_levantarBoolean(boolean &b, FILE * archivo)
{
    int id_b = 0;
    fread(&id_b, sizeof(int),1,archivo);
    switch (id_b)
    {
    case 0:
        b = FALSE;
        break;
    case 1:
        b = TRUE;
        break;
    }
}

// ===============================================================================
// METODOS ARBOL:
// ===============================================================================

boolean archivoFUNC_arbolSocios_isExisteArchivo()
{
    boolean isExiste = FALSE;
    FILE* aux;
    aux = fopen("Socios.txt","rb");
    if (aux != NULL)
    {
        isExiste = TRUE;
    }
    fclose(aux);
    return isExiste;
}

void archivoPROC_arbolSocios_crearArchivo()
{
    FILE* aux;
    aux = fopen("Socios.txt","wb");
    fclose(aux);
}

//Precond.: debe exisir
boolean archivoFUNC_arbolSocios_isVacioArchivo()
{
    boolean isVacio = FALSE;
    FILE* aux;
    aux = fopen("Socios.txt","rb");
    if (ftell(aux) == 0)
    {
        isVacio = TRUE;
    }
    fclose(aux);
    return isVacio;
}

// ===============================================================================

void archivoPROC_bajarSocio(socio s, FILE * archivo)
{
    // Bajo la cedula
    int cedula = socioFUNCselect_darCI(s);
    fwrite(&cedula,sizeof(long int),1,archivo);

    // Bajo el nombre
    StringDyn nombre;
    StringDyn_crear(nombre);
    socioPROCselect_nombre(s, nombre);
    archivoPROC_bajarString(nombre, archivo);

    // Bajo la dimension
    StringDyn dimension;
    StringDyn_crear(dimension);
    socioPROCselect_dimension_origen(s, dimension);
    archivoPROC_bajarString(dimension, archivo);

    // Bajo fecha nacimiento
    archivoPROC_bajarFecha(socioFUNCselect_fecha_nac(s), archivo);

    // Bajo Categoria
    archivoPROC_bajarCategoria(socioFUNCselect_darCategoria(s), archivo);

    // Bajo tieneAlMenosUnaHab
    archivoPROC_bajarBoolean(socioFUNCselect_tieneAlMenosUnaHab(s), archivo);

    // Bajo cantidad poderes Sobrenaturales
    int cant_habilidades = 0;
    cant_habilidades = socioFUNCselect_cantPodsSobrenaturales(s);
    fwrite(&cant_habilidades,sizeof(int),1,archivo);
}

void archivoPROC_levantarSocio(socio &s, FILE * archivo)
{
    // Levantar la cedula
    int cedula = 0;
    fread(&cedula, sizeof(long int), 1, archivo);

    // Levantar el nombre
    StringDyn nombre;
    StringDyn_crear(nombre);
    archivoPROC_levantarString(nombre, archivo);

    // Levantar la dimension
    StringDyn dimension;
    StringDyn_crear(dimension);
    archivoPROC_levantarString(dimension, archivo);

    // Levantar fecha nacimiento
    FechaCompleta fecha_nac;
    archivoPROC_levantarFecha(fecha_nac, archivo);

    // Levantar Categoria
    categorias c;
    archivoPROC_levantarCategoria(c, archivo);

    // Levantar tieneAlMenosUnaHab
    boolean b;
    archivoPROC_levantarBoolean(b,archivo);

    // Levantar cantidad poderes Sobrenaturales
    int cat_habilidades = 0;
    fread(&cat_habilidades, sizeof(int), 1, archivo);

    //  CREAR UN SOCIO CON LAS VARIABLES CREADAS Y PASARLAS POR PARAMETRO
    s = socioFUNC_PARAM_cargaSocio(cedula,nombre,dimension,fecha_nac,c,b,cat_habilidades);
}

void archivoPROC_arbolSocios_BajarArbol_al_Archivo_Aux(arbolSocios as, FILE * f)
{
    if (as != NULL)
    {
        archivoPROC_bajarSocio(as->info, f);
        archivoPROC_arbolSocios_BajarArbol_al_Archivo_Aux(as->Hizq,f);
        archivoPROC_arbolSocios_BajarArbol_al_Archivo_Aux(as->Hder,f);
    }
}

// precondicion : debe existir el archivo
void archivoPROC_arbolSocios_BajarArbol_al_Archivo(arbolSocios as)
{
    FILE * f;
    f = fopen("Socios.txt","wb");
    archivoPROC_arbolSocios_BajarArbol_al_Archivo_Aux(as,f);
    fclose(f);
}

// precondicion : debe existir el archivo
void archivoPROC_arbolSocios_LevantarArbol_a_Memoria(arbolSocios &as)
{
    FILE * archivo;
    archivo = fopen("Socios.txt","rb");
    socio Buffer;
    archivoPROC_levantarSocio(Buffer, archivo);
    while(!feof(archivo))
    {
        arbolSociosPROC_agregarSocioAlArbol(as,Buffer);
        archivoPROC_levantarSocio(Buffer, archivo);
    }
    fclose(archivo);
}

// ===============================================================================
// METODOS LISTA:
// ===============================================================================

boolean archivoFUNC_listaHabilidades_isExisteArchivo()
{
    boolean isExiste = FALSE;
    FILE* aux;
    aux = fopen("Habilidades.txt","rb");
    if (aux != NULL)
    {
        isExiste = TRUE;
    }
    fclose(aux);
    return isExiste;
}

void archivoPROC_listaHabilidades_crearArchivo()
{
    FILE* aux;
    aux = fopen("Habilidades.txt","wb");
    fclose(aux);
}

//Precond.: debe exisir
boolean archivoFUNC_listaHabilidades_isVacioArchivo()
{

    boolean isVAcio = FALSE;
    FILE * f = fopen("Habilidades.txt", "rb");
    fseek(f,0,SEEK_END);
    if(ftell(f) == 0)
        isVAcio = TRUE;
    return isVAcio;
}

void archivoPROC_listaHabilidades_bajarHabilidad(habilidad h, FILE * archivo)
{
    // Bajo la cedula
    int cedula = habilidadFUNCselect_darcedula_magica(h);
    fwrite(&cedula,sizeof(long int),1,archivo);

    // Bajo el nombre
    StringDyn nombre;
    habilidadFUNCselect_nombre_habilidad(h, nombre);
    archivoPROC_bajarString(nombre, archivo);

    // Bajo fecha nacimiento
    archivoPROC_bajarFecha(habilidadFUNCselect_fecha_manifestacion(h), archivo);

    // Bajo Tipo Habilidad
    archivoPROC_bajarTipoHabilidad(habilidadFUNCselect_tipo_habilidad(h), archivo);
}

void archivoPROC_listaHabilidades_levantarHabilidad(habilidad &h, FILE * archivo)
{
    // Levantar la cedula
    int cedula = 0;
    fread(&cedula, sizeof(long int), 1, archivo);

    // Levantar el nombre
    StringDyn nombre;
    StringDyn_crear(nombre);
    archivoPROC_levantarString(nombre, archivo);

    // Levantar fecha nacimiento
    FechaCompleta fecha_man;
    archivoPROC_levantarFecha(fecha_man, archivo);

    // Levantar Tipo Habilidad
    tipoHabilidad th;
    archivoPROC_levantarTipoHabilidad(th, archivo);

    h = habilidadFUNC_PARAM_cargaHabilidad(cedula, nombre, fecha_man, th );
}

void archivoPROC_listaHabilidades_BajarLista_al_Archivo(listaHabilidades lh)
{
    FILE * archivo;
    archivo = fopen("Habilidades.txt","wb");
    while(lh != NULL)
    {
        archivoPROC_listaHabilidades_bajarHabilidad(lh->info, archivo);
        lh = lh->sig;
    }
    fclose(archivo);
}

void archivoPROC_listaHabilidades_LevantarLista_a_Memoria(listaHabilidades &lh)
{
    FILE * archivo;
    archivo = fopen("Habilidades.txt","rb");
    habilidad buffer;
    archivoPROC_listaHabilidades_levantarHabilidad(buffer, archivo);

    while(!feof(archivo))
    {
        listaHabilidadesPROC_agregarFinal(lh,buffer);
        archivoPROC_listaHabilidades_levantarHabilidad(buffer, archivo);

    }
    fclose(archivo);

}

// ===============================================================================
// ===============================================================================
