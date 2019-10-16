#include "menu.h"

int main()
{
    int lifeCycle; /**< Indicador del ciclo de vida de cada menu. >*/
    int optionMenu; /**< Opcion elegida por el usuario del menu principal. >*/
    sCategory categories[CATEGORIES_MAX]; /**< Arreglo de Categorias. >*/
    sGame games[GAMES_MAX];/**< Arreglo de Juegos. >*/
    sCustomer customers[CUSTOMERS_MAX]; /**< Arreglo de Clientes. >*/
    sRental rents[RENTS_MAX]; /**< Arreglo de Alquileres. >*/

    if(categories_init(categories, CATEGORIES_MAX) == OK
       && games_init(games, GAMES_MAX) == OK
       && customers_init(customers, CUSTOMERS_MAX) == OK
       && rents_init(rents, RENTS_MAX) == OK)
    {
        if(HARDCODE == TRUE)
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
            case 1:
                do
                {
                    lifeCycle = menu_category(&optionMenu);

                    switch(optionMenu)
                    {
                    }

                    if(optionMenu == MENU_CATEGORY_MAX || optionMenu == ERROR)
                    {
                        break;
                    }
                    else
                    {
                        inputs_pauseScreen(CONTINUE_MESSAGE);
                    }
                }while(lifeCycle == OK);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            }

            if(optionMenu == MENU_MAIN_MAX || optionMenu == ERROR)
            {
                inputs_pauseScreen(QUIT_MESSAGE);
                break;
            }
            else
            {
                inputs_pauseScreen(CONTINUE_MESSAGE);
            }
        }while(lifeCycle == OK);
    }
    else
    {
        printf("Error de inicializacion en arreglos de estructuras.\n");
    }

    return 0;
}
