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

    if(categoriesList != NULL
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
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

int categories_getEmptyIndex(sCategory categoriesList[], int categoriesLength)
{
    int returnValue = ERROR;
    int i;

    if(categoriesList != NULL
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        for (i = 0; i < categoriesLength; i++)
        {
            if(categoriesList[i].isEmpty == TRUE)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}

int categories_getIndexById(sCategory categoriesList[], int categoriesLength, int id)
{
    int returnValue = ERROR;

    if(categoriesList != NULL
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        for (int i = 0; i < categoriesLength; i++)
        {
            if(categoriesList[i].id == id
               && categoriesList[i].isEmpty == FALSE)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}

int categories_userSelection(char message[], char eMessage[], sCategory categoriesList[], int categoriesLength)
{
    int returnValue = ERROR;
    int auxId = 0;
    int auxIndex = 0;

    if(message != NULL && eMessage != NULL
       && categoriesList != NULL
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        if (categories_printList(categoriesList, categoriesLength) == 0)
        {
            printf("No hay categorias activas.\n");
        }
        else
        {
            if(!inputs_getInt(&auxId, message, eMessage, ID_INIT_CATEGORY+1, ID_INIT_CATEGORY+CATEGORIES_MAX))
            {
                auxIndex = categories_getIndexById(categoriesList, categoriesLength, auxId);

                if(auxIndex != ERROR)
                {
                    returnValue = auxId;
                }
                else
                {
                    printf("No se encuentra la categoria ingresada.\n");
                }
            }
        }
    }

    return returnValue;
}

int categories_add(sCategory categoriesList[], int categoriesLength)
{
    int returnValue = ERROR;
    int indexAux;

    if(categoriesList != NULL
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        indexAux = categories_getEmptyIndex(categoriesList, categoriesLength);

        if(!inputs_getString(categoriesList[indexAux].description,
                             "Ingrese la descripcion del juego: ", ERROR_MESSAGE,
                             1, CATEGORY_NAME_MAX))
        {
            categoriesList[indexAux].id = getNewId();
            categoriesList[indexAux].isEmpty = FALSE;
            returnValue = OK;
        }
    }

    return returnValue;
}

int categories_modify(sCategory categoriesList[], int categoriesLength)
{
    int returnValue = ERROR;
    int id;
    int index;
    char descriptionAux[CATEGORY_NAME_MAX];

    if(categoriesList != NULL
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        id = categories_userSelection("Ingrese el ID de la Categoria a modificar: ",
            ERROR_MESSAGE, categoriesList, categoriesLength);

        if(id != ERROR)
        {
            index = categories_getIndexById(categoriesList, categoriesLength, id);

            if(index != ERROR
               && !inputs_getString(descriptionAux, "Ingrese la nueva descripcion: ",
                                    ERROR_MESSAGE, 1, CATEGORY_NAME_MAX))
            {
                strcpy(categoriesList[index].description, descriptionAux);
                returnValue = OK;
            }
        }
    }

    return returnValue;
}

int categories_delete(sCategory categoriesList[], int categoriesLength)
{
    int returnValue = ERROR;
    int id;
    int index;

    if(categoriesList != NULL
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        id = categories_userSelection("Ingrese el ID de la Categoria a dar de baja: ",
            ERROR_MESSAGE, categoriesList, categoriesLength);

        if(id != ERROR)
        {
            index = categories_getIndexById(categoriesList, categoriesLength, id);

            if(index != ERROR)
            {
                inputs_clearScreen();
                printf("ATENCION! ESTA A PUNTO DE DAR DE BAJA A LA SIGUIENTE CATEGORIA:\n");
                categories_print(categoriesList[index]);

                if(inputs_userResponse("ESTA DE ACUERDO? [S] [N]: "))
                {
                    categoriesList[index].isEmpty = TRUE;
                    returnValue = OK;
                }
            }
        }
    }

    return returnValue;
}

int categories_sort(sCategory categoriesList[], int categoriesLength, int order)
{
    int returnValue = ERROR;

    if(categoriesList != NULL
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX
       && (order == ASC || order == DESC))
    {
        for(int i= 0; i < categoriesLength-1 ; i++)
        {
            for(int j = i+1; j < categoriesLength; j++)
            {
                if(isCategory(categoriesList[i])
                   && isCategory(categoriesList[j]))
                {
                    if((strcmp(arrays_stringToCamelCase(categoriesList[i].description, CATEGORY_NAME_MAX),
                               arrays_stringToCamelCase(categoriesList[j].description, CATEGORY_NAME_MAX)) > 0
                        && order == ASC)
                        || (strcmp(arrays_stringToCamelCase(categoriesList[i].description, CATEGORY_NAME_MAX),
                               arrays_stringToCamelCase(categoriesList[j].description, CATEGORY_NAME_MAX)) < 0
                        && order == DESC))
                    {
                        if(categories_swap(&categoriesList[i], &categoriesList[j]) == OK)
                        {
                            returnValue = OK;
                        }
                    }
                }
            }
        }
    }

    return returnValue;
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
