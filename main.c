#include "rents.h"

int main()
{
    sCategory categories[CATEGORIES_MAX];
    sGame games[GAMES_MAX];

    if(categories_init(categories, CATEGORIES_MAX) == OK)
    {
        if(HARDCODE == TRUE)
        {
            categories_hardcode(categories, CATEGORIES_MAX);
            games_hardcode(games, GAMES_MAX);
        }

        if(categories_sort(categories, CATEGORIES_MAX, ASC) == ERROR
           || games_sort(games, GAMES_MAX, categories, CATEGORIES_MAX, DESC) == ERROR)
        {
            printf("No se hizo ningun orden.\n");
        }

        if(categories_printList(categories, CATEGORIES_MAX) == 0
           || games_printList(games, GAMES_MAX, categories, CATEGORIES_MAX) == 0)
        {
            printf("No hay datos a imprimir.\n");
        }
    }

    return 0;
}
