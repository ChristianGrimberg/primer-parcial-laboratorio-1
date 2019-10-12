#include "rents.h"

int main()
{
    sCategory categories[CATEGORIES_MAX];

    if(categories_init(categories, CATEGORIES_MAX) == OK)
    {
        categories_hardcode(categories, CATEGORIES_MAX);

        if(categories_printList(categories, CATEGORIES_MAX) == 0)
        {
            printf("No hay categorias definidas.\n");
        }
    }

    return 0;
}
