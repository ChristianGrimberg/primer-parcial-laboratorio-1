#include "menu.h"

int menu_main(int* option)
{
    int returnValue = ERROR;

    inputs_clearScreen();

    printf(" +=======================================================+\n");
    printf(" |           ALQUILER DE JUEGOS INFANTILES               |\n");
    printf(" +=======================================================+\n");
    printf(" | [1] ABM DE CATEGORIAS DE JUEGOS                       |\n");
    printf(" | [2] ABM DE JUEGOS INFANTILES                          |\n");
    printf(" | [3] ABM DE CLIENTES                                   |\n");
    printf(" | [4] ABM DE ALQUILERES                                 |\n");
    printf(" | [5] INFORMES                                          |\n");
    printf(" | [6] SALIR DEL PROGRAMA                                |\n");
    printf(" +-------------------------------------------------------+\n\n");

    if(!inputs_getInt(option, "Elija una opcion del menu: ", ERROR_MESSAGE, 1, MENU_MAIN_MAX))
    {
        returnValue = OK;
    }

    return returnValue;
}

int menu_category(int* option)
{
    int returnValue = ERROR;

    inputs_clearScreen();

    printf(" +=======================================================+\n");
    printf(" |                 ABM DE CATEGORIAS                     |\n");
    printf(" +=======================================================+\n");
    printf(" | [1] ALTA DE CATEGORIA                                 |\n");
    printf(" | [2] BAJA DE CATEGORIA                                 |\n");
    printf(" | [3] MODIFICACION DE CATEGORIA                         |\n");
    printf(" | [4] LISTADO DE CATEGORIAS                             |\n");
    printf(" | [5] VOLVER AL MENU PRINCIPAL                          |\n");
    printf(" +-------------------------------------------------------+\n\n");

    if(!inputs_getInt(option, "Elija una opcion del menu: ", ERROR_MESSAGE, 1, MENU_CATEGORY_MAX))
    {
        returnValue = OK;
    }

    return returnValue;
}
