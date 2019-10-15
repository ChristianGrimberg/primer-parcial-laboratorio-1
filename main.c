#include "rents.h"

int main()
{
    sCategory categories[CATEGORIES_MAX];
    sGame games[GAMES_MAX];
    sCustomer customers[CUSTOMERS_MAX];
    sRental rents[RENTS_MAX];

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
        }

        if(categories_sort(categories, CATEGORIES_MAX, ASC) == ERROR
           || games_sort(games, GAMES_MAX, categories, CATEGORIES_MAX, ASC) == ERROR
           || customers_sort(customers, CUSTOMERS_MAX, ASC) == ERROR)
        {
            printf("No se hizo ningun orden.\n");
        }

        if(categories_printList(categories, CATEGORIES_MAX) == 0
           || games_printList(games, GAMES_MAX, categories, CATEGORIES_MAX) == 0
           || customers_printList(customers, CUSTOMERS_MAX) == 0
           || rents_printList(rents, RENTS_MAX, customers, CUSTOMERS_MAX, games, GAMES_MAX, categories, CATEGORIES_MAX) == 0)
        {
            printf("No hay datos a imprimir.\n");
        }
    }
    else
    {
        printf("Los datos no han podido inicializarse.\n");
    }

    return 0;
}
