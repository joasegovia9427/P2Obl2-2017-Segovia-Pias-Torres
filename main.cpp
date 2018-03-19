////UDE - LicEnInformatica, Curso 2017 - Nocturno - Programacion 2 - Segundo Obligatorio - Docente: Tavidian, Sirely
////Integrantes: Pías, Richard - 1.924.591-2 ; Segovia, Joaquín - 4.739.544-4 ; Torres, Mathias - 4.223.291-4

#include "archivos.h"
#include "menus.h"

void PROC_logicaMenuOp3(arbolSocios &as, listaHabilidades &lh)
{
    int opcionMenuOp3,contadorFechasAnteriores = 0, contadorIntentos = 0, cant_habilidades = 0, b=0, a=0, o=0, cantNATURAL= 0, cantPOCO_NATURAL= 0, cantSOBRENATURAL= 0;
    long int CI=0;
    boolean isSVolver,isValid, isValidF1,isValidF2,isCIenlh;
    FechaCompleta fechaABuscarAnteriores, f1, f2;
    do
    {
        fflush(stdin);
        menusPROC_menuOpcion3(opcionMenuOp3);
        switch (opcionMenuOp3)
        {

        case 1:/*3.1 Contar cuántos socios de cada categoría mágica (brujos, hadas y hechiceros) hay registrados en el sistema.*/
            printf("\nIngreso a la opci%sn %d del men%s de listados y consultas\n", LETRA_o,opcionMenuOp3, LETRA_u);
            if (arbolSociosFUNC_isArbolVacio(as) == TRUE)
            {
                PROC_mensajeErrorCargaVacia();
            }
            else
            {
                b=0;
                a=0;
                o=0;
                arbolSociosPROC_mostrarCategorias(as,b,a,o);
                printf("La cantidad de cada categoria es:\nBrujos: %d | Hadas: %d | Hechiceros: %d",b,a,o);
            }
            PROC_LimpiarYPausa();
            break;
        case 2:/*3.2 Contar cuántas habilidades de cada tipo (naturales, poco naturales y sobrenaturales) hay registradas en el sistema.*/
            printf("\nIngreso a la opci%sn %d del men%s de listados y consultas\n", LETRA_o,opcionMenuOp3, LETRA_u);
            if (listaHabilidadesFUNC_isListaVacia(lh) == TRUE)
            {
                PROC_mensajeErrorCargaVacia();
            }
            else
            {
                cantNATURAL = 0;
                cantPOCO_NATURAL = 0;
                cantSOBRENATURAL = 0;
                listaHabilidadesPROC_mostrarCantTipoHabilidades(lh, cantNATURAL, cantPOCO_NATURAL, cantSOBRENATURAL);
                printf("La cantidad de cada tipo de habilidad es:\nNatural: %d | Poco Natural: %d | Sobrenatural %d",cantNATURAL,cantPOCO_NATURAL,cantSOBRENATURAL);
                PROC_LimpiarYPausa();
            }
            break;
        case 3:/*3.3 Dada una fecha de nacimiento, contar cuántos de los socios registrados en el sistema nacieron antes de dicha fecha. Se debe verificar previamente que la fecha ingresada sea válida.*/
            printf("\nIngreso a la opci%sn %d del men%s de listados y consultas\n", LETRA_o,opcionMenuOp3, LETRA_u);
            if (arbolSociosFUNC_isArbolVacio(as) == TRUE)
            {
                PROC_mensajeErrorCargaVacia();
            }
            else
            {
                contadorFechasAnteriores = 0;
                //precondicion: fecha valida
                fflush(stdin);
                do
                {
                    isValid=FALSE;
                    fflush(stdin);
                    printf("\nIngrese fecha de naciemiento del socio para contar cuantos socios registrados en el sistema nacieron antes de la fecha elegida: ");
                    FechaCompletaPROC_Carga(fechaABuscarAnteriores);
                    isValid = FechaCompletaFUNC_IsValid(fechaABuscarAnteriores);
                    if (!isValid)
                    {
                        printf("\nError, fecha no valida, reingrese fecha.");
                    }

                    fflush(stdin);

                }
                while (isValid == FALSE && contadorIntentos <= INTENTOS);
                if (isValid)
                {
                    contadorFechasAnteriores = arbolSociosPROC_mostraSociosAntesDeFecha(as,fechaABuscarAnteriores);
                    printf("\nLa cantidad de socios con la fecha de nacimiento menor a la fecha ingresada es: %d",contadorFechasAnteriores);
                }
                PROC_LimpiarYPausa();
            }
            break;
        case 4:/*3.4 Dadas dos fechas, contar cuántas habilidades fueron ingresadas dentro de dicho rango de fechas (incluidas ambas fechas).Se debe verificar previamente que ambas fechas ingresadas sean válidas y que la primera fecha sea menor o igual que la segunda.*/
            printf("\nIngreso a la opci%sn %d del men%s de listados y consultas\n", LETRA_o,opcionMenuOp3, LETRA_u);
            if (listaHabilidadesFUNC_isListaVacia(lh) == TRUE)
            {
                PROC_mensajeErrorCargaVacia();
            }
            else
            {
                //PRECONDICIONES: Fecha válida, f1 < f2
                do
                {
                    isValidF1=FALSE;

                    fflush(stdin);

                    printf("\nIngrese primera fecha para buscar habilidades en un rango: ");

                    FechaCompletaPROC_Carga(f1);

                    isValidF1 = FechaCompletaFUNC_IsValid(f1);

                    if (!isValidF1)
                    {
                        printf("\nError, fecha no valida, reingrese fecha.");
                    }

                    contadorIntentos++;

                }
                while (isValidF1 == FALSE && contadorIntentos <= INTENTOS);


                // Solo si es válida la primer fecha, pido la segunda

                if(isValidF1 == TRUE)
                {
                    int fechaddd =0;
                    contadorIntentos = 0;

                    do
                    {

                        isValidF2=FALSE;

                        fflush(stdin);

                        printf("\nIngrese segunda fecha para buscar habilidades en un rango: ");

                        FechaCompletaPROC_Carga(f2);

                        isValidF2 = FechaCompletaFUNC_IsValid(f2);

                        if (isValidF2 == FALSE)
                        {

                            printf("\nError, fecha no valida, reingrese fecha.");

                        }
                        else
                        {

                            if (FechaComparaFechas(f1,f2) == 1)
                            {

                                isValidF2 = FALSE;
                                printf("\nError, la segunda fecha debe ser mayor que la primera.");

                            }

                        }

                        fechaddd = FechaComparaFechas(f1,f2);
                        contadorIntentos++;

                    }
                    while (isValidF2 == FALSE && contadorIntentos <= INTENTOS && fechaddd == 1);

                    if(isValidF2 == TRUE)
                    {

                        cant_habilidades = listaHabilidadesFUNC_largoListaPorRangoFechas(lh,f1,f2);
                        printf("\nCantidad de Habilidades encontradas para este rango: %d", cant_habilidades);

                    }
                }
                PROC_LimpiarYPausa();
            }
            break;
        case 5:/*3.5 Listar todos los socios registrados en el sistema, ordenados por cédula de menor a mayor.Los datos de un mismo socio (cédula mágica, nombre, fecha de nacimiento, dimensión de origen y categoría mágica)deberán listarse todos en una misma línea.*/
            printf("\nIngreso a la opci%sn %d del men%s de listados y consultas\n", LETRA_o,opcionMenuOp3, LETRA_u);
            if (arbolSociosFUNC_isArbolVacio(as) == TRUE)
            {
                PROC_mensajeErrorCargaVacia();
            }
            else
            {
                printf("\nDatos Socios:\nCI Magica, Nombre, Fecha de Nacimiento, Dimension de origen, Categoria\n");
                arbolSociosPROC_mostrarSociosDetalle(as);
                PROC_LimpiarYPausa();
            }
            break;
        case 6:/*3.6 Listar todos aquellos socios registrados en el sistema que aún no han manifestado ninguna habilidad,ordenados por cédula de menor a mayor. Los datos de un mismo socio (cédula mágica, nombre, fecha de nacimiento,dimensión de origen y categoría mágica) deberán listarse todos en una misma línea.*/
            printf("\nIngreso a la opci%sn %d del men%s de listados y consultas\n", LETRA_o,opcionMenuOp3, LETRA_u);
            if (arbolSociosFUNC_isArbolVacio(as) == TRUE)
            {
                PROC_mensajeErrorCargaVacia();
            }
            else
            {
                printf("\nDatos Socios:\nCI Magica, Nombre, Fecha de Nacimiento, Dimension de origen, Categoria\n");
                arbolSociosPROC_mostrarSociosSinHabilidades(as);
                PROC_LimpiarYPausa();
            }
            break;
        case 7:/*3.7 Dada la cédula mágica de un socio, listar todas las habilidades correspondientes a dicho socio, ordenadas en forma cronológica inversa (desde las más recientes hacia las más antiguas). Los datos de una misma habilidad (nombre, fecha de manifestación, cédula mágica del socio y tipo de habilidad) deberán listarse todos en una misma línea. Se debe verificar desde el main previamente que el socio correspondiente exista en el sistema de la lista. */
            printf("\nIngreso a la opci%sn %d del men%s de listados y consultas\n", LETRA_o,opcionMenuOp3, LETRA_u);
            if (listaHabilidadesFUNC_isListaVacia(lh) == TRUE)
            {
                PROC_mensajeErrorCargaVacia();
            }
            else
            {
                //precondicion validar ci en la lista
                CI = 0;
                isCIenlh = FALSE;
                do
                {
                    printf("Ingrese CI para buscar sus habilidades asociadas: ");
                    scanf("%ld",&CI);
                    contadorIntentos++;
                    isCIenlh = listaHabilidadesFUNC_existeCIenLH(lh,CI);
                    if (isCIenlh)
                    {
                        printf("\nDatos Habilidades:\nCI Magica, Nombre, Fecha de Manifestaci%sn, Tipo de habilidad\n",LETRA_o);
                        listaHabilidadesPROC_mostrarHabilidadesDeUnaCI(lh,CI);
                    }
                    else
                    {
                        printf("\nError, la CI ingresada no tiene habilidades asociadas.\n\n");
                    }
                }
                while (isCIenlh == FALSE && contadorIntentos <= INTENTOS);
                PROC_LimpiarYPausa();
            }
            break;
        case 8:/*3.8 Dada una fecha, listar todas las habilidades que hayan sido manifestadas en dicha fecha.Los datos de una misma habilidad (nombre, fecha de manifestación, cédula mágica del socio y tipo de habilidad)deberán listarse todos en una misma línea. Se debe verificar previamente que la fecha ingresada sea válida.*/
            printf("\nIngreso a la opci%sn %d del men%s de listados y consultas\n", LETRA_o,opcionMenuOp3, LETRA_u);
            if (listaHabilidadesFUNC_isListaVacia(lh) == TRUE)
            {
                PROC_mensajeErrorCargaVacia();
            }
            else
            {
                do
                {
                    isValid=FALSE;

                    fflush(stdin);

                    printf("\nIngrese primera fecha para buscar habilidades en un rango: ");

                    FechaCompletaPROC_Carga(f1);

                    isValid = FechaCompletaFUNC_IsValid(f1);

                    if (!isValid)
                    {
                        printf("\nError, fecha no valida.");
                    }

                    fflush(stdin);

                }
                while (isValid == FALSE && contadorIntentos <= INTENTOS);

                if(isValid == TRUE)
                {

                    listaHabilidadesPROC_mostrarHabilidadesDeUnaFecha(lh,f1);

                }
                PROC_LimpiarYPausa();
            }
            break;
        case 9:/*3.9 Listar los datos del socio más poderoso registrado en el sistema.Es decir, del socio que ha manifestado la mayor cantidad de habilidades sobrenaturales de entre todos los socios registrados.En caso de que haya varios, basta con devolver uno cualquiera de ellos. En caso de que no haya ninguno, emitir un mensaje que así lo indique.*/
            printf("\nIngreso a la opci%sn %d del men%s de listados y consultas\n", LETRA_o,opcionMenuOp3, LETRA_u);
            if (arbolSociosFUNC_isArbolVacio(as) == TRUE)
            {
                PROC_mensajeErrorCargaVacia();
            }
            else
            {
                arbolSociosPROC_mostraSocioMasPoderoso(as);
                PROC_LimpiarYPausa();
            }
            break;
        case 0://3.0

            printf("\n***Opci%sn %d - Esta seguro que desea volver al men%s principal?***", LETRA_o,opcionMenuOp3, LETRA_u);
            booleanPROC_carga(isSVolver);

            if (!isSVolver)
            {
                opcionMenuOp3=10;
            }
            else
            {
                printf("\n   volver%s al men%s principal   ", LETRA_a, LETRA_u);
            }
            system(LIMPIAR);
            break;
        default:
            system(LIMPIAR);
            printf("\n***Error, reintente con una opci%sn valida.***\n",LETRA_o);
            PROC_LimpiarYPausa();
            break;
        }
    }
    while (opcionMenuOp3 != 0);
}

int main()
{
    system("mode con: cols=120 lines=30");
    arbolSocios as;
    listaHabilidades lh;
    arbolSociosFUNC_crearNull(as);
    listaHabilidadesPROC_crearLista(lh);

    // LEVANTA DEL ARCHIVO EL ARBOL Y LA LISTA EN MEMORIA
    archivoFUNC_inicializaciones(lh, as);

    int opcion,i,j;
    long int CI=0;
    boolean isSalir               = FALSE;
    boolean isYaExisteCIcargada   = FALSE;
    boolean isYaExisteHabiCargada = FALSE;
    boolean isConfirmarEjecucion, isCargoBienLaFecha = FALSE;
    FechaCompleta f,fUltimaHabilidad;
    StringDyn nombreH;
    habilidad h;
    socio s;

    printf("\n\n**********BIENVENIDO A PROGRAMA DE S.M.U.R.F.***********");
    printf("\n****(Sociedad de Magos Unidos Recontra F%sntasticos)****\n", LETRA_a);
    do
    {
        fflush(stdin);
        menusPROC_menuPrincipal(opcion);
        switch (opcion)
        {
        case 1:/*1.0 Ingresar los datos de un nuevo socio. Se debe verificar previamente que no exista otro socio registrado con la misma cédula mágica y que su fecha de nacimiento sea válida.*/
            isCargoBienLaFecha = FALSE;
            printf("\nIngreso a la opci%sn %d\n", LETRA_o,opcion);
            socioPROC_darAltaSocioHardCodeAux(s,CI);
            if (arbolSociosFUNC_isArbolVacio(as))
            {
                isYaExisteCIcargada = FALSE;
            }
            else
            {
                isYaExisteCIcargada = arbolSociosFUNC_verificarExistenciaSocio(as, s);
            }
            if (isYaExisteCIcargada)   //si es true significa que ya esta registrado entonces muestro error
            {
                printf("\n***Error, ya hay un socio registrado con la misma C%sdula Magica.\nReintente.",LETRA_e);
                printf("\n***No se ingreso el socio, usted volvera al menu principal");
            }
            else
            {
                socioPROC_darAltaSocio(s,CI,isCargoBienLaFecha);
                if (isCargoBienLaFecha)
                {
                    printf("\nUsted ingresara el sigueinte socio: \n");
                    socioPROC_desplegarSocioInfo(s);
                    printf("\nEsta seguro que desea confirmar el registro de este socio? ");
                    booleanPROC_carga(isConfirmarEjecucion);
                    if (isConfirmarEjecucion)
                    {
                        arbolSociosPROC_agregarSocioAlArbol(as, s);
                        printf("\n***Se ingreso correctamente el socio");
                    }
                    else
                    {
                        printf("\n***No se ingreso el socio, usted volvera al menu principal");
                    }
                }
                else
                {
                    printf("\n***No se ingreso el socio, usted volvera al menu principal");
                }
            }
            PROC_LimpiarYPausa();
            break;
        case 2:/*2.0 Ingresar una nueva habilidad. Se debe verificar previamente que la cédula mágica del socio que la manifiesta esté registrada y que la fecha de manifestación sea válida y mayor o igual a la fecha de la habilidad más reciente registrada hasta el momento.*/
            isCargoBienLaFecha = FALSE;
            if (arbolSociosFUNC_isArbolVacio(as) == TRUE)
            {
                PROC_mensajeErrorCargaVacia();
            }
            else     //si al menos tiene un socio al cual asociarle la habilidad, recien ahi le dejo cargar con habilidades
            {
                printf("\nIngreso a la opci%sn %d\n", LETRA_o,opcion);
                CI=0;
                socioPROC_darAltaSocioHardCodeAuxPARALISTA(s,CI);
                isYaExisteCIcargada = arbolSociosFUNC_verificarExistenciaSocio(as, s);
                if (isYaExisteCIcargada)   //si es true significa que la ci para agregarle a la habilidad esta en el arbol para poder asociarla a algun socio
                {
                    if (listaHabilidadesFUNC_isListaVacia(lh) == TRUE)
                    {
                        habilidadPROC_cargarHardCodeAuxSinControlUF(h,CI,nombreH,f,isCargoBienLaFecha);
                    }
                    else
                    {
                        fUltimaHabilidad = habilidadFUNCselect_fecha_manifestacion( listaHabilidadesFUNC_darPrimerElemento(lh) );
                        habilidadPROC_cargarHardCodeAux(h,CI,nombreH,f,fUltimaHabilidad,isCargoBienLaFecha);
                    }
                    if (isCargoBienLaFecha == TRUE)
                    {
                        // aca se supone que ya paso la validacion de la cedula, la fecha valida, y fecha >= a la ultima habilidad
                        isYaExisteHabiCargada = listaHabilidadesFUNC_verificarExistenciaHabilidad(lh, CI, nombreH, f);
                        if (isYaExisteHabiCargada == TRUE)   //si es true significa que ya esta registrado una habilidad para el mismo socio, con el mismo nombre,y el mismo dia, entonces muestro error
                        {
                            printf("\n***Error, ya hay una habilidad registrada, del mismo socio, con el mismo nombre de habilidad y la misma fecha de manifestacion.\nReintente.");
                            printf("\n***No se ingreso la habilidad, usted volvera al menu principal");
                        }
                        else
                        {
                            habilidadPROC_cargar(h,CI,nombreH,f);
                            printf("\nUsted ingresara la sigueinte habilidad:\n");
                            habilidadPROC_desplegar(h);
                            printf("\nEsta seguro que desea confirmar el registro de esta habilidad? ");
                            booleanPROC_carga(isConfirmarEjecucion);
                            if (isConfirmarEjecucion)
                            {
                                listaHabilidadesPROC_insfront(lh, h);
                                arbolSociosPROC_actualizarSocio(as, CI, habilidadFUNCselect_tipo_habilidad(h));
                                printf("\n***Se ingreso correctamente la habilidad");
                            }
                            else
                            {
                                printf("\n***No se ingreso la habilidad, usted volvera al menu principal");
                            }
                        }
                    }
                    else
                    {
                        printf("\n***No se ingreso la habilidad, usted volvera al menu principal");
                    }
                }
                else
                {
                    printf("\n***Error, no hay ningun socio registrado al cual asociarle la C%sdula Magica ingresada.\nReintente.",LETRA_e);
                    printf("\n***No se ingreso la habilidad, usted volvera al menu principal");
                }
                PROC_LimpiarYPausa();
            }
            break;
        case 3://3
            if (arbolSociosFUNC_isArbolVacio(as) == TRUE && listaHabilidadesFUNC_isListaVacia(lh) == TRUE)
            {
                PROC_mensajeErrorCargaVacia();
            }
            else
            {
                printf("\nIngreso a la opci%sn %d\n", LETRA_o,opcion);
                PROC_logicaMenuOp3(as, lh);
            }
            break;
        case 4://4
            printf("\n***Opci%sn %d - Est%s seguro que desea salir?***", LETRA_o,opcion, LETRA_a);
            booleanPROC_carga(isSalir);

            if (!isSalir)
            {
                opcion=1;
                system(LIMPIAR);
            }
            else
            {
                // GUARDO EN EL ARCHIVO EL ARBOL Y LA LISTA ANTES DE SALIR DEL RPOGRAMA
                archivoPROC_arbolSocios_BajarArbol_al_Archivo(as);
                archivoPROC_listaHabilidades_BajarLista_al_Archivo(lh);

                system(LIMPIAR);

                printf("\n\n*******<<<________FIN DEL PROGRAMA S.M.U.R.F.________>>>*******\n\n");
                printf("\n*******<<<*******************************************>>>*******\n");
                for (j=176; j<179; j++)
                {
                    printf("\n");
                    for (i=0; i<80 ; i++ )
                    {
                        printf("%c",j);
                    }
                }
                printf("\n%c",201);
                for (i=0; i<78 ; i++ )
                {
                    printf("%c",205);
                }
            }
            break;
        default:
            system(LIMPIAR);
            printf("\n***Error, reintente con un car%scter valido.***", LETRA_a);
            PROC_LimpiarYPausa();
            break;
        }
    }
    while (opcion != 4);
    printf("\n%c*****************<<<______About this software______>>>***********************%c",186,186);
    printf("\n%cUDE-TRABAJO OBLIGATORIO PROG2 LIC.INFO.Nocturno2017-Docente: Tavidian, Sirely%c",186,186);
    printf("\n%c# proudlyDevelopedBy:                                                        %c",186,186);
    printf("\n%c# Segovia, Joaquin - 4.739.544-4                                             %c",186,186);
    printf("\n%c# Pias, Richard    - 1.924.591-2                                             %c",186,186);
    printf("\n%c# Torres, Mathias  - 4.223.291-4                                             %c",186,186);
    printf("\n%c*****************************************************************************%c",186,186);
    printf("\n%c",200);
    for (i=0; i<78 ; i++ )
    {
        printf("%c",205);
    }
    for (j=176; j<179; j++)
    {
        printf("\n");
        for (i=0; i<80 ; i++ )
        {
            printf("%c",j);
        }
    }
    PROC_LimpiarYPausa();
}
//UDE - LicEnInformatica, Curso 2017 - Nocturno - Programacion 2 - Segundo Obligatorio - Docente: Tavidian, Sirely
//Integrantes: Pias, Richard - 1.924.591-2; Segovia, Joaquin - 47395444; Torres, Mathias - 4.223.291-4
