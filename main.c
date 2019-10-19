#include "menu.h"

int main()
{
    int lifeCycle; /**< Indicador del ciclo de vida de cada menu. >*/
    int optionMenu; /**< Opcion elegida por el usuario del menu principal. >*/
    int quantity; /**< Cantidad retornada en una funcion. >*/
    sCategory categories[CATEGORIES_MAX]; /**< Arreglo de Categorias. >*/
    sGame games[GAMES_MAX];/**< Arreglo de Juegos. >*/
    sCustomer customers[CUSTOMERS_MAX]; /**< Arreglo de Clientes. >*/
    sRental rents[RENTS_MAX]; /**< Arreglo de Alquileres. >*/

    if(categories_init(categories, CATEGORIES_MAX) == 0
       && games_init(games, GAMES_MAX) == 0
       && customers_init(customers, CUSTOMERS_MAX) == 0
       && rents_init(rents, RENTS_MAX) == 0)
    {
        if(HARDCODE)
        {
            categories_hardcode(categories, CATEGORIES_MAX);
            games_hardcode(games, GAMES_MAX);
            customers_hardcode(customers, CUSTOMERS_MAX);
            rents_hardcode(rents, RENTS_MAX);
        }

        do
        {
            lifeCycle = menu_main(&optionMenu);

            switch(optionMenu)
            {
            case 1: /**< Menu ABM de Categorias. >*/
                do
                {
                    lifeCycle = menu_categories(&optionMenu);

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
                    case 4: /**< Listado ordenado por descripcion de Categorias. >*/
                        inputs_clearScreen();
                        if(categories_sort(categories, CATEGORIES_MAX, ASC) == DISORDERED)
                        {
                            printf("Se ordeno la lista de Categorias por Descripcion.\n");
                        }

                        quantity = categories_printList(categories, CATEGORIES_MAX);
                        if(quantity > 0)
                        {
                            printf("Se encontraron %d Categorias en el sistema.\n", quantity);
                        }
                        else
                        {
                            printf("No hay Categorias cargadas en el sistema.\n");
                        }
                        break;
                    }

                    if(optionMenu == MENU_CATEGORY_MAX || optionMenu == -1)
                    {
                        break;
                    }
                    else
                    {
                        inputs_pauseScreen(CONTINUE_MESSAGE);
                    }
                }while(lifeCycle == 0);
                break;
            case 2: /**< Menu ABM de Juegos. >*/
                do
                {
                    lifeCycle = menu_games(&optionMenu);

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
                    case 4: /**< Listado ordenado por descripcion de Juegos. >*/
                        inputs_clearScreen();
                        if(games_sort(games, GAMES_MAX, categories, CATEGORIES_MAX, ASC) == DISORDERED)
                        {
                            printf("Se ordeno la lista de Juegos por descripcion.\n");
                        }

                        quantity = games_printList(games, GAMES_MAX, categories, CATEGORIES_MAX);
                        if(quantity > 0)
                        {
                            printf("Se encontraron %d Juegos en el sistema.\n", quantity);
                        }
                        else
                        {
                            printf("No hay Categorias cargadas en el sistema.\n");
                        }
                        break;
                    }

                    if(optionMenu == MENU_GAME_MAX || optionMenu == -1)
                    {
                        break;
                    }
                    else
                    {
                        inputs_pauseScreen(CONTINUE_MESSAGE);
                    }
                }while(lifeCycle == 0);
                break;
            case 3: /**< Menu ABM de Clientes. >*/
                do
                {
                    lifeCycle = menu_customers(&optionMenu);

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
                    case 4: /**< Listado ordenado por apellidos y nombre de Clientes. >*/
                        inputs_clearScreen();
                        if(customers_sort(customers, CUSTOMERS_MAX, ASC) == DISORDERED)
                        {
                            printf("Se ordeno la lista de Clientes de genero y apellido.\n");
                        }

                        quantity = customers_printList(customers, CUSTOMERS_MAX);
                        if(quantity > 0)
                        {
                            printf("Se encontraron %d Clientes en el sistema.\n", quantity);
                        }
                        else
                        {
                            printf("No hay Clientes cargados en el sistema.\n");
                        }
                        break;
                    }

                    if(optionMenu == MENU_CUSTOMERS_MAX || optionMenu == -1)
                    {
                        break;
                    }
                    else
                    {
                        inputs_pauseScreen(CONTINUE_MESSAGE);
                    }
                }while(lifeCycle == 0);
                break;
            case 4: /**< Menu ABM de Alquileres. >*/
                do
                {
                    lifeCycle = menu_rents(&optionMenu);

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
                    case 4: /**< Listado ordenado por categoria y precio de Alquileres. >*/
                        inputs_clearScreen();
                        if(rents_sort(rents, RENTS_MAX, customers, CUSTOMERS_MAX, games, GAMES_MAX, categories, CATEGORIES_MAX, ASC) == DISORDERED)
                        {
                            printf("Se ordeno la lista de Alquileres por categoria y precio.\n");
                        }

                        quantity = rents_printList(rents, RENTS_MAX, customers, CUSTOMERS_MAX, games, GAMES_MAX, categories, CATEGORIES_MAX);
                        if(quantity > 0)
                        {
                            printf("Se encontraron %d Alquileres realizados en el sistema.\n", quantity);
                        }
                        else
                        {
                            printf("No hay Alquiler realizados en el sistema.\n");
                        }
                        break;
                    }

                    if(optionMenu == MENU_RENTS_MAX || optionMenu == -1)
                    {
                        break;
                    }
                    else
                    {
                        inputs_pauseScreen(CONTINUE_MESSAGE);
                    }
                }while(lifeCycle == 0);
                break;
            case 5:
                break;
            }

            if(optionMenu == MENU_MAIN_MAX || optionMenu == -1)
            {
                inputs_pauseScreen(QUIT_MESSAGE);
                break;
            }
            else
            {
                inputs_pauseScreen(CONTINUE_MESSAGE);
            }
        }while(lifeCycle == 0);
    }
    else
    {
        printf("Error de inicializacion en arreglos de estructuras.\n");
    }

    return 0;
}
