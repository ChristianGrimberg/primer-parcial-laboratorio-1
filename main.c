/**
 * ============================================================================
 * Nombre         : Primer parcial de Laboratorio 1
 * Autor          : Christian Grimberg
 * Descripcion    : Alquiler de Juegos Infantiles
 * ============================================================================
 */

#include "menu.h"

int main()
{
    int lifeCycle; /**< Indicador del ciclo de vida de cada menu. >*/
    int optionMenu; /**< Opcion elegida por el usuario del menu principal. >*/
    int quantity; /**< Cantidad retornada en una funcion. >*/
    sCategory categories[CATEGORIES_MAX]; /**< Arreglo de Categorias. >*/
    sGame games[GAMES_MAX];/**< Arreglo de Juegos. >*/
    sGame tableGames[GAMES_MAX]; /**< Arreglo de Juegos de Mesa. >*/
    sCustomer customers[CUSTOMERS_MAX]; /**< Arreglo de Clientes. >*/
    sRental rents[RENTS_MAX]; /**< Arreglo de Alquileres. >*/

    if(categories_init(categories, CATEGORIES_MAX) == -1
       || games_init(games, GAMES_MAX) == -1
       || customers_init(customers, CUSTOMERS_MAX) == -1
       || rents_init(rents, RENTS_MAX) == -1)
   {
       printf("Error de inicializacion en arreglos de estructuras.\n");
       exit(1);
   }
    else
    {
        /**< El enunciado requiere que las Categorias esten minimamente harcodeadas. >*/
        categories_hardcode(categories, CATEGORIES_MAX);

        if(HARDCODE)
        {
            games_hardcode(games, GAMES_MAX);
            customers_hardcode(customers, CUSTOMERS_MAX);
            rents_hardcode(rents, RENTS_MAX);
        }

        do
        {
            lifeCycle = menu_main(&optionMenu);

            if(optionMenu == MENU_MAIN_MAX || optionMenu == -1)
            {
                inputs_pauseScreen(QUIT_MESSAGE);
                break;
            }

            switch(optionMenu)
            {
            case 1: /**< Menu ABM de Categorias. >*/
                do
                {
                    lifeCycle = menu_categories(&optionMenu);

                    if(optionMenu == MENU_CATEGORY_MAX || optionMenu == -1)
                    {
                        break;
                    }

                    switch(optionMenu)
                    {
                    case 1: /**< Agregar nueva Categoria. >*/
                        if(categories_add(categories, CATEGORIES_MAX) == 0)
                        {
                            printf("Categoria agregada con exito.\n");
                        }
                        break;
                    case 2: /**< Baja de una Categoria. >*/
                        inputs_clearScreen();

                        if(categories_delete(categories, CATEGORIES_MAX) == 0)
                        {
                            printf("Categoria eliminada correctamente.\n");
                        }
                        break;
                    case 3: /**< Modificar una Categoria. >*/
                        inputs_clearScreen();

                        if(categories_modify(categories, CATEGORIES_MAX) == 0)
                        {
                            printf("Categoria modificada con exito.\n");
                        }
                        break;
                    case 4: /**< Listado ordenado por descripcion ascendente de Categorias. >*/
                    case 5: /**< Listado ordenado por descripcion descendente de Categorias. >*/
                        inputs_clearScreen();

                        if((optionMenu == 4 && categories_sort(categories, CATEGORIES_MAX, ASC) == 0)
                           || (optionMenu == 5 && categories_sort(categories, CATEGORIES_MAX, DESC) == 0))
                        {
                            quantity = categories_printList(categories, CATEGORIES_MAX);

                            if(quantity > 0)
                            {
                                printf("Se encontraron %d Categorias en el sistema.\n", quantity);
                            }
                            else
                            {
                                printf("No hay Categorias cargadas en el sistema.\n");
                            }
                        }
                        break;
                    }
                    inputs_pauseScreen(CONTINUE_MESSAGE);
                }while(lifeCycle == 0);
                break;
            case 2: /**< Menu ABM de Juegos. >*/
                do
                {
                    lifeCycle = menu_games(&optionMenu);

                    if(optionMenu == MENU_GAME_MAX || optionMenu == -1)
                    {
                        break;
                    }

                    switch(optionMenu)
                    {
                    case 1: /**< Agregar nuevo Juego. >*/
                        if(games_add(games, GAMES_MAX, categories, CATEGORIES_MAX) == 0)
                        {
                            printf("Juego agregado con exito.\n");
                        }
                        break;
                    case 2: /**< Baja de un Juego. >*/
                        inputs_clearScreen();

                        if(games_delete(games, GAMES_MAX, categories, CATEGORIES_MAX) == 0)
                        {
                            printf("Juego eliminado correctamente.\n");
                        }
                        break;
                    case 3: /**< Modificar un Juego. >*/
                        inputs_clearScreen();

                        if(games_modify(games, GAMES_MAX, categories, CATEGORIES_MAX) == 0)
                        {
                            printf("Juego modificado con exito.\n");
                        }
                        break;
                    case 4: /**< Listado ordenado por descripcion ascendente de Juegos. >*/
                    case 5: /**< Listado ordenado por descripcion descendente de Juegos. >*/
                        inputs_clearScreen();

                        if((optionMenu == 4 && games_sort(games, GAMES_MAX, categories, CATEGORIES_MAX, ASC) == 0)
                           || (optionMenu == 5 && games_sort(games, GAMES_MAX, categories, CATEGORIES_MAX, DESC) == 0))
                        {
                            quantity = games_printList(games, GAMES_MAX, categories, CATEGORIES_MAX);

                            if(quantity > 0)
                            {
                                printf("Se encontraron %d Juegos en el sistema.\n", quantity);
                            }
                            else
                            {
                                printf("No hay Juegos cargados en el sistema.\n");
                            }
                        }
                        break;
                    }
                    inputs_pauseScreen(CONTINUE_MESSAGE);
                }while(lifeCycle == 0);
                break;
            case 3: /**< Menu ABM de Clientes. >*/
                do
                {
                    lifeCycle = menu_customers(&optionMenu);

                    if(optionMenu == MENU_CUSTOMERS_MAX || optionMenu == -1)
                    {
                        break;
                    }

                    switch(optionMenu)
                    {
                    case 1: /**< Agregar nuevo Cliente. >*/
                        if(customers_add(customers, CUSTOMERS_MAX) == 0)
                        {
                            printf("Cliente agregado con exito.\n");
                        }
                        break;
                    case 2: /**< Baja de un Cliente. >*/
                        inputs_clearScreen();

                        if(customers_delete(customers, CUSTOMERS_MAX) == 0)
                        {
                            printf("Cliente eliminado correctamente.\n");
                        }
                        break;
                    case 3: /**< Modificar un Cliente. >*/
                        inputs_clearScreen();

                        if(customers_modify(customers, CUSTOMERS_MAX) == 0)
                        {
                            printf("Cliente modificado con exito.\n");
                        }
                        break;
                    case 4: /**< Listado ordenado por apellidos y nombre de forma ascendente de Clientes. >*/
                    case 5:  /**< Listado ordenado por apellidos y nombre de forma descendente de Clientes. >*/
                        inputs_clearScreen();

                        if((optionMenu == 4 && customers_sort(customers, CUSTOMERS_MAX, ASC) == 0)
                           || (optionMenu == 5 && customers_sort(customers, CUSTOMERS_MAX, DESC) == 0))
                        {
                            quantity = customers_printList(customers, CUSTOMERS_MAX);

                            if(quantity > 0)
                            {
                                printf("Se encontraron %d Clientes en el sistema.\n", quantity);
                            }
                            else
                            {
                                printf("No hay Clientes cargados en el sistema.\n");
                            }
                        }
                        break;
                    }
                    inputs_pauseScreen(CONTINUE_MESSAGE);
                }while(lifeCycle == 0);
                break;
            case 4: /**< Menu ABM de Alquileres. >*/
                do
                {
                    lifeCycle = menu_rents(&optionMenu);

                    if(optionMenu == MENU_RENTS_MAX || optionMenu == -1)
                    {
                        break;
                    }

                    switch(optionMenu)
                    {
                    case 1: /**< Alquilar un Juego. >*/
                        if(rents_add(rents, RENTS_MAX, customers, CUSTOMERS_MAX, games, GAMES_MAX, categories, CATEGORIES_MAX) == 0)
                        {
                            printf("Alquiler efectuado con exito.\n");
                        }
                        break;
                    case 2: /**< Anulacion de un Alquiler. >*/
                        inputs_clearScreen();

                        if(rents_delete(rents, RENTS_MAX, customers, CUSTOMERS_MAX, games, GAMES_MAX, categories, CATEGORIES_MAX) == 0)
                        {
                            printf("Alquiler anulado correctamente.\n");
                        }
                        break;
                    case 3: /**< Modificar un Alquiler. >*/
                        inputs_clearScreen();

                        if(rents_modify(rents, RENTS_MAX, customers, CUSTOMERS_MAX, games, GAMES_MAX, categories, CATEGORIES_MAX) == 0)
                        {
                            printf("Alquiler modificado con exito.\n");
                        }
                        break;
                    case 4: /**< Listado ordenado por fecha y precio de Alquileres de forma ascendente. >*/
                    case 5:  /**< Listado ordenado por fecha y precio de Alquileres de forma ascendente. >*/
                        inputs_clearScreen();

                        if((optionMenu == 4
                                && rents_sort(rents, RENTS_MAX, customers, CUSTOMERS_MAX, games, GAMES_MAX, categories, CATEGORIES_MAX, ASC) == 0)
                           || (optionMenu == 5
                                && rents_sort(rents, RENTS_MAX, customers, CUSTOMERS_MAX, games, GAMES_MAX, categories, CATEGORIES_MAX, DESC) == 0))
                        {
                            quantity = rents_printList(rents, RENTS_MAX, customers, CUSTOMERS_MAX, games, GAMES_MAX, categories, CATEGORIES_MAX);

                            if(quantity > 0)
                            {
                                printf("Se encontraron %d Alquileres realizados en el sistema.\n", quantity);
                            }
                            else
                            {
                                printf("No hay Alquileres realizados en el sistema.\n");
                            }
                        }
                        break;
                    }
                    inputs_pauseScreen(CONTINUE_MESSAGE);
                }while(lifeCycle == 0);
                break;
            case 5: /**< Reportes del Sistema. >*/
                do
                {
                    lifeCycle = menu_reports(&optionMenu);

                    if(optionMenu == MENU_REPORTS_MAX || optionMenu == -1)
                    {
                        break;
                    }

                    switch(optionMenu)
                    {
                    case 1:
                        inputs_clearScreen();

                        if(games_init(tableGames, GAMES_MAX) != -1
                           && games_clone(tableGames, games, GAMES_MAX) == 0)
                        {
                        }
                        break;
                    }
                    inputs_pauseScreen(CONTINUE_MESSAGE);
                }while(lifeCycle == 0);
                break;
            }
            inputs_pauseScreen(CONTINUE_MESSAGE);
        }while(lifeCycle == 0);
    }

    return 0;
}
