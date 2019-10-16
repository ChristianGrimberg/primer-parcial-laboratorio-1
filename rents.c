#include "rents.h"

/** \brief Funcion que devuelve una estructura vacia.
 *
 * \param void No requiere parametros.
 * \return sRental Devuelve una estructura con valores "nulos".
 *
 */
static sRental nullRental(void);

/** \brief Obtiene un nuevo ID autoincremental.
 *
 * \param void No requiere parametros.
 * \return int Retorna un nuevo ID incremental.
 *
 */
static int getNewId(void);

/** \brief Imprime en pantalla los valores de la estructura.
 *
 * \param rental sRental Estructura de Alquiler a imprimir.
 * \param customer sCustomer Estructura de Cliente a imprimir.
 * \param game sGame Estructura de Juego a imprimir.
 * \param category sCategory Estructura de Categoria a imprimir.
 * \return int
 *          [0] Si la estructura esta vacia.
 *          [1] Si la estructura esta llena y pudo imprimirse.
 *
 */
static int printRental(sRental rental, sCustomer customer, sGame game, sCategory category);

int rents_isRental(sRental rental, sCustomer customer, sGame game, sCategory category)
{
    int returnValue = 0;

    if(rental.id != EMPTY_ID
       && customers_isCustomer(customer) && rental.customerId == customer.id
       && games_isGame(game, category) && rental.gameId == game.id
       && categories_isCategory(category) && game.categoryId == category.id
       && rental.isEmpty == FALSE)
    {
        returnValue = 1;
    }

    return returnValue;
}

int rents_compare(sRental rental1, sRental rental2)
{
    int compare = -2;

    if(rental1.isEmpty == FALSE
       && rental2.isEmpty == FALSE)
    {
        if(rental1.id > rental2.id)
        {
            compare = 1;
        }
        else
        {
            if(rental1.id < rental2.id)
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

int rents_swap(sRental* rental1, sRental* rental2)
{
    int returnValue = ERROR;
    sRental aux1;
    sRental aux2;

    aux1 = *rental1;
    aux2 = *rental2;
    *rental1 = *rental2;
    *rental2 = aux1;

    if(rents_compare(*rental1, aux2) == 0
       && rents_compare(*rental2, aux1) == 0)
    {
        returnValue = OK;
    }

    return returnValue;
}

int rents_init(sRental rentsList[], int rentsLength)
{
    int returnValue = ERROR;
    int i;

    if(rentsList != NULL
       && rentsLength > 0 && rentsLength <= RENTS_MAX)
    {
        for(i = 0 ; i < rentsLength; i++)
        {
            rentsList[i] = nullRental();
        }

        if(i == rentsLength)
        {
            returnValue = OK;
        }
    }

    return returnValue;
}

void rents_hardcode(sRental rentsList[], int rentsLength)
{
    int indexHardcodeMax = 4;

    sRental rentsAux[] = {
        {getNewId(), 201, 301, {1, 1, 2019}, FALSE},
        {getNewId(), 205, 303, {12, 10, 2019}, FALSE},
        {getNewId(), 202, 305, {21, 5, 2019}, FALSE},
        {getNewId(), 203, 302, {5, 3, 2019}, FALSE},
        {getNewId(), 204, 304, {8, 9, 2019}, FALSE},
    };

    if(rentsList != NULL
       && rentsLength > 0 && rentsLength <= RENTS_MAX)
    {
        for (int i = 0; i < rentsLength; i++)
        {
            if(i <= indexHardcodeMax)
            {
                rentsList[i] = rentsAux[i];
            }
            else
            {
                rentsList[i] = nullRental();
            }
        }
    }
}

int rents_getEmptyIndex(sRental rentsList[], int rentsLength)
{
    int returnValue = ERROR;
    int i;

    if(rentsList != NULL
       && rentsLength > 0 && rentsLength <= RENTS_MAX)
    {
        for (i = 0; i < rentsLength; i++)
        {
            if(rentsList[i].isEmpty == TRUE)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}

int rents_getIndexById(sRental rentsList[], int rentsLength, int id)
{
    int returnValue = ERROR;

    if(rentsList != NULL
       && rentsLength > 0 && rentsLength <= RENTS_MAX)
    {
        for (int i = 0; i < rentsLength; i++)
        {
            if(rentsList[i].id == id
               && rentsList[i].isEmpty == FALSE)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}

int rents_userSelection(char message[], char eMessage[], sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength)
{
    int returnValue = ERROR;
    int auxId = 0;
    int auxIndex = 0;

    if(message != NULL && eMessage != NULL
       && rentsList != NULL && customersList != NULL
       && gamesList != NULL && categoriesList != NULL
       && rentsLength > 0 && rentsLength <= RENTS_MAX
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX
       && gamesLength >0 && gamesLength <= GAMES_MAX
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        if(rents_printList(rentsList, rentsLength, customersList, customersLength,
                           gamesList, gamesLength, categoriesList, categoriesLength) == 0)
        {
            printf("No hay Alquileres activos.\n");
        }
        else
        {
            if(!inputs_getInt(&auxId, message, eMessage, ID_INIT_RENTAL+1, ID_INIT_RENTAL+RENTS_MAX))
            {
                auxIndex = rents_getIndexById(rentsList, rentsLength, auxId);

                if(auxIndex != ERROR)
                {
                    returnValue = auxId;
                }
                else
                {
                    printf("No se encuentra el Alquiler ingresado.\n");
                }
            }
        }
    }

    return returnValue;
}

int rents_sort(sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength, int order)
{
    int returnValue = ERROR;
    int customerIndex1;
    int customerIndex2;
    int gameIndex1;
    int gameIndex2;
    int categoryIndex1;
    int categoryIndex2;

    if(rentsList != NULL && customersList != NULL
       && gamesList != NULL && categoriesList != NULL
       && rentsLength > 0 && rentsLength <= RENTS_MAX
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX
       && gamesLength >0 && gamesLength <= GAMES_MAX
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX
       && (order == ASC || order == DESC))
    {
        for(int i= 0; i < rentsLength-1 ; i++)
        {
            for(int j = i+1; j < rentsLength; j++)
            {
                customerIndex1 = customers_getIndexById(customersList, customersLength, rentsList[i].customerId);
                customerIndex2 = customers_getIndexById(customersList, customersLength, rentsList[j].customerId);
                gameIndex1 = games_getIndexById(gamesList, gamesLength, rentsList[i].gameId);
                gameIndex2 = games_getIndexById(gamesList, gamesLength, rentsList[j].gameId);
                categoryIndex1 = categories_getIndexById(categoriesList, categoriesLength, gamesList[gameIndex1].categoryId);
                categoryIndex2 = categories_getIndexById(categoriesList, categoriesLength, gamesList[gameIndex2].categoryId);

                if(customers_isCustomer(customersList[customerIndex1])
                   && customers_isCustomer(customersList[customerIndex2])
                   && games_isGame(gamesList[gameIndex1], categoriesList[categoryIndex1])
                   && games_isGame(gamesList[gameIndex2], categoriesList[categoryIndex2])
                   && categories_isCategory(categoriesList[categoryIndex1])
                   && categories_isCategory(categoriesList[categoryIndex2])
                   && rents_isRental(rentsList[i], customersList[customerIndex1], gamesList[gameIndex1], categoriesList[categoryIndex1])
                   && rents_isRental(rentsList[j], customersList[customerIndex2], gamesList[gameIndex2], categoriesList[categoryIndex2]))
                {
                    if((strcmp(arrays_stringToCamelCase(categoriesList[categoryIndex1].description, CATEGORY_NAME_MAX),
                               arrays_stringToCamelCase(categoriesList[categoryIndex2].description, CATEGORY_NAME_MAX)) > 0
                        && order == ASC)
                        || (strcmp(arrays_stringToCamelCase(categoriesList[categoryIndex1].description, CATEGORY_NAME_MAX),
                               arrays_stringToCamelCase(categoriesList[categoryIndex2].description, CATEGORY_NAME_MAX)) < 0
                        && order == DESC))
                    {
                        if(rents_swap(&rentsList[i], &rentsList[j]) == OK)
                        {
                            returnValue = OK;
                        }
                    }
                    else
                    {
                        if(strcmp(arrays_stringToCamelCase(categoriesList[categoryIndex1].description, CATEGORY_NAME_MAX),
                               arrays_stringToCamelCase(categoriesList[categoryIndex2].description, CATEGORY_NAME_MAX)) == 0)
                        {
                            if((gamesList[gameIndex1].price > gamesList[gameIndex2].price && order == ASC)
                               || (gamesList[gameIndex1].price < gamesList[gameIndex2].price && order == DESC))
                            {
                                if(rents_swap(&rentsList[i], &rentsList[j]) == OK)
                                {
                                    returnValue = OK;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return returnValue;
}

void rents_print(sRental rental, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength)
{
    int customerIndex;
    int gameIndex;
    int categoryIndex;

    if(customersList != NULL && gamesList != NULL && categoriesList != NULL
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX
       && gamesLength >0 && gamesLength <= GAMES_MAX
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        customerIndex = customers_getIndexById(customersList, customersLength, rental.customerId);
        gameIndex = games_getIndexById(gamesList, gamesLength, rental.gameId);
        categoryIndex = categories_getIndexById(categoriesList, categoriesLength, gamesList[gameIndex].categoryId);

        if(customers_isCustomer(customersList[customerIndex])
           && games_isGame(gamesList[gameIndex], categoriesList[categoryIndex])
           && categories_isCategory(categoriesList[categoryIndex])
           && rents_isRental(rental, customersList[customerIndex], gamesList[gameIndex], categoriesList[categoryIndex]))
        {
            printf("+=======+======================+======================+===========+======================+======================+\n");
            printf("|   ID  |         JUEGO        |       CATEGORIA      |   PRECIO  | APELLIDO DEL CLIENTE |  NOMBRE DEL CLIENTE  |\n");
            printf("+=======+======================+======================+===========+======================+======================+\n");

            if(printRental(rental, customersList[customerIndex], gamesList[gameIndex], categoriesList[categoryIndex]) == 0)
            {
                printf("Alquiler vacio.\n");
            }
            printf("+-------+----------------------+----------------------+-----------+----------------------+----------------------+\n");
        }
    }
}

int rents_printList(sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength)
{
    int itemsCounter = 0;
    int flag = 0;
    int customerIndex;
    int gameIndex;
    int categoryIndex;

    if(rentsList != NULL && customersList != NULL
       && gamesList != NULL && categoriesList != NULL
       && rentsLength > 0 && rentsLength <= RENTS_MAX
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX
       && gamesLength >0 && gamesLength <= GAMES_MAX
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        for (int i = 0; i < rentsLength; i++)
        {
            customerIndex = customers_getIndexById(customersList, customersLength, rentsList[i].customerId);
            gameIndex = games_getIndexById(gamesList, gamesLength, rentsList[i].gameId);
            categoryIndex = categories_getIndexById(categoriesList, categoriesLength, gamesList[gameIndex].categoryId);

            if(customers_isCustomer(customersList[customerIndex])
               && games_isGame(gamesList[gameIndex], categoriesList[categoryIndex])
               && categories_isCategory(categoriesList[categoryIndex])
               && rents_isRental(rentsList[i], customersList[customerIndex], gamesList[gameIndex], categoriesList[categoryIndex]))
            {
                itemsCounter++;

                if(itemsCounter == 1)
                {
                    printf("+=======+======================+======================+===========+======================+======================+\n");
                    printf("|   ID  |         JUEGO        |       CATEGORIA      |   PRECIO  | APELLIDO DEL CLIENTE |  NOMBRE DEL CLIENTE  |\n");
                    printf("+=======+======================+======================+===========+======================+======================+\n");
                }

                if(printRental(rentsList[i], customersList[customerIndex], gamesList[gameIndex], categoriesList[categoryIndex]) == 1)
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
            printf("+-------+----------------------+----------------------+-----------+----------------------+----------------------+\n");
        }
    }

    return itemsCounter;
}

static sRental nullRental()
{
    sRental aux;

    aux.id = EMPTY_ID;
    aux.gameId = EMPTY_ID;
    aux.customerId = EMPTY_ID;
    aux.date = structs_nullDate();
    aux.isEmpty = TRUE;

    return aux;
}

static int getNewId(void)
{
    static int rentalId = ID_INIT_RENTAL;
    rentalId++;
    return rentalId;
}

static int printRental(sRental rental, sCustomer customer, sGame game, sCategory category)
{
    int counter = 0;

    if(rents_isRental(rental, customer, game, category))
    {
        printf("| %5d | %20s | %20s | %9.2f | %20s | %20s |\n",
               rental.id, arrays_stringToCamelCase(game.description, GAME_NAME_MAX),
               arrays_stringToCamelCase(category.description, CATEGORIES_MAX), game.price,
               arrays_stringToCamelCase(customer.lastName, CUSTOMER_NAME_MAX),
               arrays_stringToCamelCase(customer.name, CUSTOMER_NAME_MAX));
        counter = 1;
    }

    return counter;
}
