#include "menu.h"

int menu_main(int* option)
{
    int returnValue = -1;

    inputs_clearScreen();

    printf(" +=======================================================+\n");
    printf(" |           ALQUILER DE JUEGOS INFANTILES               |\n");
    printf(" +=======================================================+\n");
    printf(" | [1] ABM DE CATEGORIAS DE JUEGOS                       |\n");
    printf(" | [2] ABM DE JUEGOS INFANTILES                          |\n");
    printf(" | [3] ABM DE CLIENTES                                   |\n");
    printf(" | [4] ALQUILER DE JUEGOS INFANTILES                     |\n");
    printf(" | [5] INFORMES                                          |\n");
    printf(" | [6] SALIR DEL PROGRAMA                                |\n");
    printf(" +-------------------------------------------------------+\n\n");

    if(!inputs_getInt(option, "Elija una opcion del menu: ", ERROR_MESSAGE, 1, MENU_MAIN_MAX))
    {
        returnValue = 0;
    }

    return returnValue;
}

int menu_categories(int* option)
{
    int returnValue = -1;

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
        returnValue = 0;
    }

    return returnValue;
}

int menu_games(int* option)
{
    int returnValue = -1;

    inputs_clearScreen();

    printf(" +=======================================================+\n");
    printf(" |                 ABM DE JUEGOS                         |\n");
    printf(" +=======================================================+\n");
    printf(" | [1] ALTA DE JUEGO                                     |\n");
    printf(" | [2] BAJA DE JUEGO                                     |\n");
    printf(" | [3] MODIFICACION DE JUEGO                             |\n");
    printf(" | [4] LISTADO DE JUEGOS                                 |\n");
    printf(" | [5] VOLVER AL MENU PRINCIPAL                          |\n");
    printf(" +-------------------------------------------------------+\n\n");

    if(!inputs_getInt(option, "Elija una opcion del menu: ", ERROR_MESSAGE, 1, MENU_GAME_MAX))
    {
        returnValue = 0;
    }

    return returnValue;
}

int menu_customers(int* option)
{
    int returnValue = -1;

    inputs_clearScreen();

    printf(" +=======================================================+\n");
    printf(" |                 ABM DE CLIENTES                       |\n");
    printf(" +=======================================================+\n");
    printf(" | [1] ALTA DE CLIENTE                                   |\n");
    printf(" | [2] BAJA DE CLIENTE                                   |\n");
    printf(" | [3] MODIFICACION DE CLIENTE                           |\n");
    printf(" | [4] LISTADO DE CLIENTES                               |\n");
    printf(" | [5] VOLVER AL MENU PRINCIPAL                          |\n");
    printf(" +-------------------------------------------------------+\n\n");

    if(!inputs_getInt(option, "Elija una opcion del menu: ", ERROR_MESSAGE, 1, MENU_CUSTOMERS_MAX))
    {
        returnValue = 0;
    }

    return returnValue;
}

int menu_rents(int* option)
{
    int returnValue = -1;

    inputs_clearScreen();

    printf(" +=======================================================+\n");
    printf(" |                 ALQUILER DE JUEGOS                    |\n");
    printf(" +=======================================================+\n");
    printf(" | [1] ALQUILER DE JUEGO                                 |\n");
    printf(" | [2] ANULACION DE ALQUILER                             |\n");
    printf(" | [3] MODIFICACION DE ALQUILER                          |\n");
    printf(" | [4] LISTADO DE ALQUILERES REALIZADOS                  |\n");
    printf(" | [5] VOLVER AL MENU PRINCIPAL                          |\n");
    printf(" +-------------------------------------------------------+\n\n");

    if(!inputs_getInt(option, "Elija una opcion del menu: ", ERROR_MESSAGE, 1, MENU_RENTS_MAX))
    {
        returnValue = 0;
    }

    return returnValue;
}
