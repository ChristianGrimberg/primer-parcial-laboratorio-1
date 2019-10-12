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

/** \brief Imprime en pantalla los valores de la estructura.
 *
 * \param category sCategory Estructura a imprimir.
 * \return int
 *          [0] Si la estructura esta vacia.
 *          [1] Si la estructura esta llena y pudo imprimirse.
 *
 */
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

int categories_swap(sCategory* category1, sCategory* category2)
{
    int returnValue = ERROR;
    sCategory aux1;
    sCategory aux2;

    aux1 = *category1;
    aux2 = *category2;
    *category1 = *category2;
    *category2 = aux1;

    if(categories_compare(*category1, aux2) == 0
       && categories_compare(*category2, aux1) == 0)
    {
        returnValue = OK;
    }

    return returnValue;
}

int categories_init(sCategory categoriesList[], int categoriesLength)
{
    int returnValue = ERROR;
    int i;

    if(categoriesList != NULL
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        for(i = 0 ; i < categoriesLength; i++)
        {
            categoriesList[i] = nullCategory();
        }

        if(i == categoriesLength)
        {
            returnValue = OK;
        }
    }

    return returnValue;
}

void categories_hardcode(sCategory categoriesList[], int categoriesLength)
{
    int indexHardcodeMax = 4;

    sCategory categoriesAux[] = {
        {getNewId(), "mesa", FALSE},
        {getNewId(), "azar", FALSE},
        {getNewId(), "estrategia", FALSE},
        {getNewId(), "salon", FALSE},
        {getNewId(), "magia", FALSE}
    };

    if(categoriesList != NULL && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        for (int i = 0; i < categoriesLength; i++)
        {
            if(i <= indexHardcodeMax)
            {
                categoriesList[i] = categoriesAux[i];
            }
            else
            {
                categoriesList[i] = nullCategory();
            }
        }
    }
}

void categories_print(sCategory category)
{
    if(isCategory(category))
    {
        printf("+=======+======================+\n");
        printf("|   ID  |      DESCRIPCION     |\n");
        printf("+=======+======================+\n");
        if(printCategory(category) == 0)
        {
            printf("Categoria vacia.\n");
        }
        printf("+-------+----------------------+\n");
    }
}

int categories_printList(sCategory categoriesList[], int categoriesLength)
{
    int itemsCounter = 0;
    int flag = 0;

    if(categoriesList != NULL && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        for (int i = 0; i < categoriesLength; i++)
        {
            if(isCategory(categoriesList[i]))
            {
                itemsCounter++;

                if(itemsCounter == 1)
                {
                    printf("+=======+======================+\n");
                    printf("|   ID  |      DESCRIPCION     |\n");
                    printf("+=======+======================+\n");
                }

                if(printCategory(categoriesList[i]))
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
        }

        if(flag == 1)
        {
            printf("+-------+----------------------+\n");
        }
    }

    return itemsCounter;
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

    if(category.id != EMPTY_ID
       && category.description != NULL
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

static int printCategory(sCategory category)
{
    int counter = 0;

    if(isCategory(category))
    {
        printf("| %5d | %20s |\n", category.id, arrays_stringToCamelCase(category.description, CATEGORY_NAME_MAX));
        counter = 1;
    }

    return counter;
}
