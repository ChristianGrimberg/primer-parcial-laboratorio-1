#include "menu.h"

int menu_main(int* option)
{
    int returnValue = -1;

    inputs_clearScreen();

    printf(" +=======================================================+\n");
    printf(" |           ALQUILER DE JUEGOS INFANTILES               |\n");
    printf(" +=======================================================+\n");
    printf(" | [1] ABM de Categorias de Juegos                       |\n");
    printf(" | [2] ABM de Juegos Infantiles                          |\n");
    printf(" | [3] ABM de Clientes                                   |\n");
    printf(" | [4] Alquileres                                        |\n");
    printf(" | [5] Informes y Reportes                               |\n");
    printf(" | [6] Salir del programa                                |\n");
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
    printf(" | [1] Alta de Categoria                                 |\n");
    printf(" | [2] Baja de Categoria                                 |\n");
    printf(" | [3] Modificacion de Categoria                         |\n");
    printf(" | [4] Listado de Categorias en orden Ascendente         |\n");
    printf(" | [5] Listado de Categorias en orden Descendente        |\n");
    printf(" | [6] Volver al menu principal                          |\n");
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
    printf(" | [1] Alta de Juego                                     |\n");
    printf(" | [2] Baja de Juego                                     |\n");
    printf(" | [3] Modificacion de Juego                             |\n");
    printf(" | [4] Listado de Juegos en orden Ascendente             |\n");
    printf(" | [5] Listado de Juegos en orden Descendente            |\n");
    printf(" | [6] Volver al menu principal                          |\n");
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
    printf(" | [1] Alta de Cliente                                   |\n");
    printf(" | [2] Baja de Cliente                                   |\n");
    printf(" | [3] Modificacion de Cliente                           |\n");
    printf(" | [4] Listado de Clientes en orden Ascendente           |\n");
    printf(" | [5] Listado de Clientes en orden Descendente          |\n");
    printf(" | [6] Volver al menu principal                          |\n");
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
    printf(" | [1] Alquiler de un Juego                              |\n");
    printf(" | [2] Devolucion de un Alquiler                         |\n");
    printf(" | [3] Modificacion de un Alquiler                       |\n");
    printf(" | [4] Alquileres actuales en orden Ascendente           |\n");
    printf(" | [5] Alquileres actuales en orden Descendente          |\n");
    printf(" | [6] Volver al menu principal                          |\n");
    printf(" +-------------------------------------------------------+\n\n");

    if(!inputs_getInt(option, "Elija una opcion del menu: ", ERROR_MESSAGE, 1, MENU_RENTS_MAX))
    {
        returnValue = 0;
    }

    return returnValue;
}

int menu_reports(int* option)
{
    int returnValue = -1;

    inputs_clearScreen();

    printf(" +=======================================================+\n");
    printf(" |             INFORMES Y REPORTES DEL SISTEMA           |\n");
    printf(" +=======================================================+\n");
    printf(" | [1] Juegos de Mesa                                    |\n");
    printf(" | [2] Alquileres por Cliente                            |\n");
    printf(" | [3] Importes totales por Cliente                      |\n");
    printf(" | [4] Clientes sin Alquileres                           |\n");
    printf(" | [5] Juegos sin Alquileres                             |\n");
    printf(" | [6] Alquileres por sexo                               |\n");
    printf(" | [7] Volver al menu principal                          |\n");
    printf(" +-------------------------------------------------------+\n\n");

    if(!inputs_getInt(option, "Elija una opcion del menu: ", ERROR_MESSAGE, 1, MENU_REPORTS_MAX))
    {
        returnValue = 0;
    }

    return returnValue;
}
