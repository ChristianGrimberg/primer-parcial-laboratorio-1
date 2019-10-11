#include "categories.h"

/** \brief Funcion que devuelve una estructura vacia.
 *
 * \param void No requiere parametros.
 * \return sCategory Devuelve una estructura con valores "nulos".
 *
 */
static sCategory nullCategory(void);

/** \brief Funcion que determina si la estructura es una Categoria.
 *
 * \param category sCategory Estructura a evaluar.
 * \return int
 *          [0] Si no es una Categoria.
 *          [1] Si es una Categoria.
 *
 */
static int isCategory(sCategory category);

/** \brief Obtiene un nuevo ID autoincremental.
 *
 * \param void No requiere parametros.
 * \return int Retorna un nuevo ID incremental.
 *
 */
static int getNewId(void);
static int printCategory(sCategory category);

int categories_compare(sCategory category1, sCategory category2)
{
    int compare = -2;

    if(isCategory(category1) && isCategory(category2))
    {
        if(category1.id > category2.id)
        {
            compare = 1;
        }
        else
        {
            if(category1.id < category2.id)
            {
                compare = -1;
            }
            else
            {
                compare = 0;
            }
        }
    }

    return compare;
}

static sCategory nullCategory()
{
    sCategory aux;

    aux.id = EMPTY_ID;
    strcpy(aux.description, "NULL");
    aux.isEmpty = TRUE;

    return aux;
}

static int isCategory(sCategory category)
{
    int returnValue = 0;

    if(category.id != EMPTY_ID && category.description != NULL
       && category.isEmpty == FALSE)
    {
        returnValue = 1;
    }

    return returnValue;
}

static int getNewId()
{
    static int categoryId = ID_INIT_CATEGORY;
    categoryId++;
    return categoryId;
}

