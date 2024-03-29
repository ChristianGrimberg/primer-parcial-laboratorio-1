#include "categories.h"

/** \brief Funcion que devuelve una estructura vacia.
 *
 * \param void No requiere parametros.
 * \return sCategory Devuelve una estructura con valores "nulos".
 *
 */
static sCategory nullCategory(void);

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
 * \param categoriesList[] sCategory Arreglo de estructuras.
 * \param categoriesLength int Longitud del arreglo.
 * \return int
 *          [0] Si la estructura esta vacia.
 *          [1] Si la estructura esta llena y pudo imprimirse.
 *
 */
static int printCategory(sCategory category, sCategory categoriesList[], int categoriesLength);

int categories_isCategory(sCategory category, sCategory categoriesList[], int categoriesLength)
{
    int returnValue = 0;
    int i;

    if(category.id != -1
       && !category.isEmpty
       && category.description != NULL
       && categoriesList != NULL
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        for(i = 0; i < categoriesLength; i++)
        {
            if(!categoriesList[i].isEmpty
               && categoriesList[i].id == category.id
               && strcmp(arrays_stringToCamelCase(categoriesList[i].description, CATEGORY_NAME_MAX),
                         arrays_stringToCamelCase(category.description, CATEGORY_NAME_MAX)) == 0)
            {
                returnValue = 1;
                break;
            }
        }
    }

    return returnValue;
}

int categories_compare(sCategory category1, sCategory category2)
{
    int compare = -2;

    if(!category1.isEmpty
       && !category2.isEmpty)
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
    int returnValue = -1;
    sCategory aux1;
    sCategory aux2;

    aux1 = *category1;
    aux2 = *category2;
    *category1 = *category2;
    *category2 = aux1;

    if(categories_compare(*category1, aux2) == 0
       && categories_compare(*category2, aux1) == 0)
    {
        returnValue = 0;
    }

    return returnValue;
}

int categories_init(sCategory categoriesList[], int categoriesLength)
{
    int returnValue = -1;
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
            returnValue = 0;
        }
    }

    return returnValue;
}

void categories_hardcode(sCategory categoriesList[], int categoriesLength)
{
    int indexHardcodeMax = 4;

    sCategory categoriesAux[] = {
        {getNewId(), "mesa", 0},
        {getNewId(), "azar", 0},
        {getNewId(), "estrategia", 0},
        {getNewId(), "salon", 0},
        {getNewId(), "magia", 0}
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
    int returnValue = -1;
    int i;

    if(categoriesList != NULL
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        for (i = 0; i < categoriesLength; i++)
        {
            if(categoriesList[i].isEmpty)
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
    int returnValue = -1;

    if(categoriesList != NULL
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        for (int i = 0; i < categoriesLength; i++)
        {
            if(!categoriesList[i].isEmpty
               && categoriesList[i].id == id)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}

int categories_getIdByDescription(sCategory categoriesList[], int categoriesLength, char categoryName[])
{
    int returnValue = -1;
    int i;

    if(categoriesList != NULL
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        for(i = 0; i < categoriesLength; i++)
        {
            if(!categoriesList[i].isEmpty)
            {
                if(strcmp(arrays_stringToCamelCase(categoriesList[i].description, CATEGORY_NAME_MAX),
                          arrays_stringToCamelCase(categoryName, CATEGORY_NAME_MAX)) == 0)
                {
                    returnValue = categoriesList[i].id;
                    break;
                }
            }
        }
    }

    return returnValue;
}

int categories_userSelection(char message[], char eMessage[], sCategory categoriesList[], int categoriesLength)
{
    int returnValue = -1;
    int auxId = 0;
    int auxIndex = 0;

    if(message != NULL && eMessage != NULL
       && categoriesList != NULL
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        if (categories_printList(categoriesList, categoriesLength) == 0)
        {
            printf("No hay Categorias activas.\n");
        }
        else
        {
            if(!inputs_getInt(&auxId, message, eMessage, ID_INIT_CATEGORY+1, ID_INIT_CATEGORY+CATEGORIES_MAX))
            {
                auxIndex = categories_getIndexById(categoriesList, categoriesLength, auxId);

                if(auxIndex != -1)
                {
                    returnValue = auxId;
                }
                else
                {
                    printf("No se encuentra la Categoria ingresada.\n");
                }
            }
        }
    }

    return returnValue;
}

int categories_add(sCategory categoriesList[], int categoriesLength)
{
    int returnValue = -1;
    int indexAux;
    char descriptionAux[CATEGORY_NAME_MAX];

    if(categoriesList != NULL
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        indexAux = categories_getEmptyIndex(categoriesList, categoriesLength);

        if(indexAux != -1
           && !inputs_getString(descriptionAux,
                             "Ingrese la descripcion de la Categoria: ", ERROR_MESSAGE,
                             1, CATEGORY_NAME_MAX))
        {
            categoriesList[indexAux].id = getNewId();
            strcpy(categoriesList[indexAux].description, descriptionAux);
            categoriesList[indexAux].isEmpty = 0;
            returnValue = 0;
        }
    }

    return returnValue;
}

int categories_modify(sCategory categoriesList[], int categoriesLength)
{
    int returnValue = -1;
    int id;
    int index;
    char descriptionAux[CATEGORY_NAME_MAX];

    if(categoriesList != NULL
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        id = categories_userSelection("Ingrese el ID de la Categoria a modificar: ",
            ERROR_MESSAGE, categoriesList, categoriesLength);

        if(id != -1)
        {
            index = categories_getIndexById(categoriesList, categoriesLength, id);

            if(index != -1
               && !inputs_getString(descriptionAux, "Ingrese la nueva descripcion: ",
                    ERROR_MESSAGE, 1, CATEGORY_NAME_MAX))
            {
                strcpy(categoriesList[index].description, descriptionAux);
                returnValue = 0;
            }
        }
    }

    return returnValue;
}

int categories_delete(sCategory categoriesList[], int categoriesLength)
{
    int returnValue = -1;
    int id;
    int index;

    if(categoriesList != NULL
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        id = categories_userSelection("Ingrese el ID de la Categoria a dar de baja: ",
            ERROR_MESSAGE, categoriesList, categoriesLength);

        if(id != -1)
        {
            index = categories_getIndexById(categoriesList, categoriesLength, id);

            if(index != -1)
            {
                inputs_clearScreen();
                printf("ATENCION! ESTA A PUNTO DE DAR DE BAJA A LA SIGUIENTE CATEGORIA:\n");
                categories_print(categoriesList[index], categoriesList, categoriesLength);

                if(inputs_userResponse("ESTA DE ACUERDO? [S] [N]: "))
                {
                    categoriesList[index].isEmpty = 1;
                    returnValue = 0;
                }
            }
        }
    }

    return returnValue;
}

int categories_sort(sCategory categoriesList[], int categoriesLength, int order)
{
    int returnValue = -1;

    if(categoriesList != NULL
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX
       && (order == ASC || order == DESC))
    {
        for(int i= 0; i < categoriesLength-1 ; i++)
        {
            for(int j = i+1; j < categoriesLength; j++)
            {
                if(categories_isCategory(categoriesList[i], categoriesList, categoriesLength)
                   && categories_isCategory(categoriesList[j], categoriesList, categoriesLength))
                {
                    if((strcmp(arrays_stringToCamelCase(categoriesList[i].description, CATEGORY_NAME_MAX),
                               arrays_stringToCamelCase(categoriesList[j].description, CATEGORY_NAME_MAX)) > 0
                        && order == ASC)
                        || (strcmp(arrays_stringToCamelCase(categoriesList[i].description, CATEGORY_NAME_MAX),
                               arrays_stringToCamelCase(categoriesList[j].description, CATEGORY_NAME_MAX)) < 0
                        && order == DESC))
                    {
                        if(categories_swap(&categoriesList[i], &categoriesList[j]) == -1)
                        {
                            returnValue = -1;
                            break;
                        }
                    }
                }

                returnValue = 0;
            }
        }
    }

    return returnValue;
}

void categories_print(sCategory category, sCategory categoriesList[], int categoriesLength)
{
    if(categories_isCategory(category, categoriesList, categoriesLength))
    {
        printf("+=======+======================+\n");
        printf("|   ID  |      DESCRIPCION     |\n");
        printf("+=======+======================+\n");
        if(printCategory(category, categoriesList, categoriesLength) == 0)
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

    if(categoriesList != NULL
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        for (int i = 0; i < categoriesLength; i++)
        {
            if(categories_isCategory(categoriesList[i], categoriesList, categoriesLength))
            {
                itemsCounter++;

                if(itemsCounter == 1)
                {
                    printf("+=======+======================+\n");
                    printf("|   ID  |      DESCRIPCION     |\n");
                    printf("+=======+======================+\n");
                }

                if(printCategory(categoriesList[i], categoriesList, categoriesLength) == 1)
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

    aux.id = -1;
    strcpy(aux.description, "NULL");
    aux.isEmpty = 1;

    return aux;
}

static int getNewId()
{
    static int categoryId = ID_INIT_CATEGORY;
    categoryId++;
    return categoryId;
}

static int printCategory(sCategory category, sCategory categoriesList[], int categoriesLength)
{
    int counter = 0;

    if(categories_isCategory(category, categoriesList, categoriesLength))
    {
        printf("| %5d | %20s |\n", category.id, arrays_stringToCamelCase(category.description, CATEGORY_NAME_MAX));
        counter = 1;
    }

    return counter;
}
