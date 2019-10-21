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
 * \param rentsList[] sRental Arreglo de estructuras de Alquileres.
 * \param rentsLength int Longitud del arreglo de Alquileres.
 * \param customersList[] sCustomer Arreglo de estructuras de Clientes.
 * \param customersLength int Longitud del arreglo de Clientes.
 * \param gamesList[] sGame Arreglo de estructuras de Juegos.
 * \param gamesLength int Longitud del arreglo de Juegos.
 * \param categoriesList[] sCategory Arreglo de estructuras de Categorias.
 * \param categoriesLength int Longitud del arreglo de Categorias.
 * \return int
 *          [0] Si la estructura esta vacia.
 *          [1] Si la estructura esta llena y pudo imprimirse.
 *
 */
static int printRental(sRental rental, sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength);

/** \brief Indicador de que el Cliente tiene al menos un Alquiler realizado.
 *
 * \param rentsList[] sRental Arreglo de estructuras.
 * \param rentsLength int Longitud del arreglo.
 * \param customersList[] sCustomer Arreglo de estructuras de Clientes.
 * \param customersLength int Longitud del arreglo de Clientes.
 * \param gameId int ID de Juego.
 * \return int
 *          [0] Si el Cliente no tiene Alquileres.
 *          [1] Si el Cliente tiene al menos un Alquiler.
 *
 */
static int customerWithRents(sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, int gameId);

/** \brief Indicador de que el Juego tiene al menos un Alquiler realizado.
 *
 * \param rentsList[] sRental Arreglo de estructuras.
 * \param rentsLength int Longitud del arreglo.
 * \param gamesList[] sGame Arreglo de estructuras de Juegos.
 * \param gamesLength int Longitud del arreglo de Juegos.
 * \param categoriesList[] sCategory Arreglo de estructuras de Categorias.
 * \param categoriesLength int Longitud del arreglo de Categorias.
 * \param customerId int ID de Cliente.
 * \return int
 *          [0] Si el Juego no tiene Alquileres.
 *          [1] Si el Juego tiene al menos un Alquiler.
 *
 */
static int gameWithRents(sRental rentsList[], int rentsLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength, int gameId);

int rents_isRental(sRental rental, sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength)
{
    int returnValue = 0;
    int i;
    int customerIndex;
    int gameIndex;
    int categoryIndex;

    if(rental.id != -1
       && !rental.isEmpty
       && rental.customerId != -1
       && rental.gameId != -1
       && structs_isDate(rental.date)
       && rentsList != NULL && gamesList != NULL && categoriesList != NULL
       && rentsLength > 0 && rentsLength <= RENTS_MAX
       && gamesLength > 0 && gamesLength <= GAMES_MAX
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        for(i = 0; i < rentsLength; i++)
        {
            customerIndex = customers_getIndexById(customersList, customersLength, rentsList[i].customerId);
            gameIndex = games_getIndexById(gamesList, gamesLength, rentsList[i].gameId);
            categoryIndex = categories_getIndexById(categoriesList, categoriesLength, gamesList[gameIndex].categoryId);

            if(!rentsList[i].isEmpty
               && customers_isCustomer(customersList[customerIndex], customersList, customersLength)
               && games_isGame(gamesList[gameIndex], gamesList, gamesLength, categoriesList, categoriesLength)
               && categories_isCategory(categoriesList[categoryIndex], categoriesList, categoriesLength)
               && rentsList[i].id == rental.id
               && rentsList[i].customerId == rental.customerId
               && structs_dateCompare(rentsList[i].date, rental.date) == 0)
            {
                returnValue = 1;
                break;
            }
        }
    }

    return returnValue;
}

int rents_compare(sRental rental1, sRental rental2)
{
    int compare = -2;

    if(!rental1.isEmpty
       && !rental2.isEmpty)
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
    int returnValue = -1;
    sRental aux1;
    sRental aux2;

    aux1 = *rental1;
    aux2 = *rental2;
    *rental1 = *rental2;
    *rental2 = aux1;

    if(rents_compare(*rental1, aux2) == 0
       && rents_compare(*rental2, aux1) == 0)
    {
        returnValue = 0;
    }

    return returnValue;
}

int rents_init(sRental rentsList[], int rentsLength)
{
    int returnValue = -1;
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
            returnValue = 0;
        }
    }

    return returnValue;
}

void rents_hardcode(sRental rentsList[], int rentsLength)
{
    int indexHardcodeMax = 6;

    sRental rentsAux[] = {
        {getNewId(), 201, 301, {1, 1, 2012}, 0},
        {getNewId(), 205, 303, {12, 10, 2010},0},
        {getNewId(), 202, 305, {21, 5, 2019}, 0},
        {getNewId(), 203, 302, {5, 3, 2014}, 0},
        {getNewId(), 204, 304, {8, 9, 2016}, 0},
        {getNewId(), 209, 305, {15, 6, 2017}, 0},
        {getNewId(), 206, 305, {12, 3, 2016}, 0}
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
    int returnValue = -1;
    int i;

    if(rentsList != NULL
       && rentsLength > 0 && rentsLength <= RENTS_MAX)
    {
        for (i = 0; i < rentsLength; i++)
        {
            if(rentsList[i].isEmpty == 1)
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
    int returnValue = -1;

    if(rentsList != NULL
       && rentsLength > 0 && rentsLength <= RENTS_MAX)
    {
        for (int i = 0; i < rentsLength; i++)
        {
            if(!rentsList[i].isEmpty
               && rentsList[i].id == id)
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
    int returnValue = -1;
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

                if(auxIndex != -1)
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

int rents_add(sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength)
{
    int returnValue = -1;
    int indexRentalAux;
    int idGameAux;
    int indexGameAux;
    int idCustomerAux;
    sDate dateAux;
    sDate dateMin = {DAY_MIN, MONTH_MIN, YEAR_MIN};
    sDate dateMax = {DAY_31, MONTH_MAX, YEAR_MAX};

    if(rentsList != NULL && customersList != NULL
       && gamesList != NULL && categoriesList != NULL
       && rentsLength > 0 && rentsLength <= RENTS_MAX
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX
       && gamesLength >0 && gamesLength <= GAMES_MAX
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        indexRentalAux = rents_getEmptyIndex(rentsList, rentsLength);

        if(indexRentalAux != -1)
        {
            idGameAux = games_userSelection("Seleccione un Juego: ", ERROR_MESSAGE, gamesList, gamesLength, categoriesList, categoriesLength);
            indexGameAux = games_getIndexById(gamesList, gamesLength, idGameAux);

            if(idGameAux != -1 && indexGameAux != -1)
            {
                idCustomerAux = customers_userSelection("Seleccione un Cliente: ", ERROR_MESSAGE, customersList, customersLength);

                if(idCustomerAux != -1
                   && !inputs_getDate(&dateAux, "Ingrese una fecha: ", ERROR_MESSAGE, dateMin, dateMax)
                   && games_subtractStock(gamesList[indexGameAux], gamesList, gamesLength, categoriesList, categoriesLength) == 0)
                {
                    rentsList[indexRentalAux].id = getNewId();
                    rentsList[indexRentalAux].gameId = idGameAux;
                    rentsList[indexRentalAux].customerId = idCustomerAux;
                    rentsList[indexRentalAux].date = dateAux;
                    rentsList[indexRentalAux].isEmpty = 0;
                    returnValue = 0;
                }
            }
        }
    }

    return returnValue;
}

int rents_modify(sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength)
{
    int returnValue = -1;
    int indexRentalAux;
    int idRentalAux;
    int idGameAux;
    int idCustomerAux;
    int option;
    sDate dateAux;
    sDate dateMin = {DAY_MIN, MONTH_MIN, YEAR_MIN};
    sDate dateMax = {DAY_31, MONTH_MAX, YEAR_MAX};

    if(rentsList != NULL && customersList != NULL
       && gamesList != NULL && categoriesList != NULL
       && rentsLength > 0 && rentsLength <= RENTS_MAX
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX
       && gamesLength >0 && gamesLength <= GAMES_MAX
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        idRentalAux = rents_userSelection("Ingrese el ID del Alquiler a modificar: ", ERROR_MESSAGE, rentsList, rentsLength, customersList, customersLength, gamesList, gamesLength, categoriesList, categoriesLength);

        if(idRentalAux != -1)
        {
            indexRentalAux = rents_getIndexById(rentsList, rentsLength, idRentalAux);

            if(indexRentalAux != -1)
            {
                inputs_clearScreen();

                printf("=======================================================\n");
                printf("                MODIFICAR ALQUILER\n");
                printf("=======================================================\n");
                printf("    1 - Modificar el Juego\n");
                printf("    2 - Modificar el Cliente\n");
                printf("    3 - Modificar la Fecha\n");
                printf("    4 - Volver al menu principal\n");
                printf("=======================================================\n");

                if(!inputs_getInt(&option, "Ingrese la opcion deseada: ", ERROR_MESSAGE, 1, 4))
                {
                    switch(option)
                    {
                        case 1:
                            idGameAux = games_userSelection("Elija un nuevo Juego: ", ERROR_MESSAGE, gamesList, gamesLength, categoriesList, categoriesLength);

                            if(idGameAux != -1)
                            {
                                rentsList[indexRentalAux].gameId = idGameAux;
                                printf("Cambio de Juego exitoso.\n");
                                returnValue = 0;
                            }
                            break;
                        case 2:
                            idCustomerAux = customers_userSelection("Elija un nuevo Cliente: ", ERROR_MESSAGE, customersList, customersLength);

                            if(idCustomerAux != -1)
                            {
                                rentsList[indexRentalAux].customerId = idCustomerAux;
                                printf("Cambio de Cliente exitoso.\n");
                                returnValue = 0;
                            }
                            break;
                        case 3:
                            if(!inputs_getDate(&dateAux, "Ingrese una nueva Fecha: ", ERROR_MESSAGE, dateMin, dateMax))
                            {
                                rentsList[indexRentalAux].date = dateAux;
                                printf("Fecha modificada con exito.\n");
                                returnValue = 0;
                            }
                            break;
                        case 4:
                            printf("Operacion cancelada.\n");
                            returnValue = 0;
                            break;
                    }
                }
            }
        }
    }

    return returnValue;
}

int rents_delete(sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength)
{
    int returnValue = -1;
    int id;
    int rentalIndex;
    int gameIndex;

    if(rentsList != NULL && customersList != NULL
       && gamesList != NULL && categoriesList != NULL
       && rentsLength > 0 && rentsLength <= RENTS_MAX
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX
       && gamesLength >0 && gamesLength <= GAMES_MAX
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        id = rents_userSelection("Ingrese el ID del Alquiler a devolver: ", ERROR_MESSAGE, rentsList, rentsLength, customersList, customersLength, gamesList, gamesLength, categoriesList, categoriesLength);

        if(id != -1)
        {
            rentalIndex = rents_getIndexById(rentsList, rentsLength, id);
            gameIndex = games_getIndexById(gamesList, gamesLength, rentsList[rentalIndex].gameId);

            if(rentalIndex != -1 && gameIndex != -1)
            {
                inputs_clearScreen();
                printf("Se esta devolviendo el siguiente Alquiler:\n");
                rents_print(rentsList[rentalIndex], rentsList, rentsLength, customersList, customersLength, gamesList, gamesLength, categoriesList, categoriesLength);

                if(inputs_userResponse("ESTA DE ACUERDO? [S] [N]: ")
                   && games_addStock(gamesList[gameIndex], gamesList, gamesLength, categoriesList, categoriesLength) == 0)
                {
                    rentsList[rentalIndex].isEmpty = 1;
                    returnValue = 0;
                }
            }
        }
    }

    return returnValue;
}

int rents_sort(sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength, int order)
{
    int returnValue = -1;
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

                if(customerIndex1 != -1 && customerIndex2 != -1
                   && gameIndex1 != -1 && gameIndex2 != -1
                   && categoryIndex1 != -1 && categoryIndex2 != -1
                   && customers_isCustomer(customersList[customerIndex1], customersList, customersLength)
                   && customers_isCustomer(customersList[customerIndex2], customersList, customersLength)
                   && games_isGame(gamesList[gameIndex1], gamesList, gamesLength, categoriesList, categoriesLength)
                   && games_isGame(gamesList[gameIndex2], gamesList, gamesLength, categoriesList, categoriesLength)
                   && categories_isCategory(categoriesList[categoryIndex1], categoriesList, categoriesLength)
                   && categories_isCategory(categoriesList[categoryIndex2], categoriesList, categoriesLength)
                   && rents_isRental(rentsList[i], rentsList, rentsLength, customersList, customersLength, gamesList, gamesLength, categoriesList, categoriesLength)
                   && rents_isRental(rentsList[j], rentsList, rentsLength, customersList, customersLength, gamesList, gamesLength, categoriesList, categoriesLength))
                {
                    if((structs_dateCompare(rentsList[i].date, rentsList[j].date) > 0 && order == ASC)
                        || (structs_dateCompare(rentsList[i].date, rentsList[j].date) < 0 && order == DESC))
                    {
                        if(rents_swap(&rentsList[i], &rentsList[j]) == -1)
                        {
                            returnValue = -1;
                            break;
                        }
                    }
                    else
                    {
                        if(structs_dateCompare(rentsList[i].date, rentsList[j].date) == 0)
                        {
                            if((gamesList[gameIndex1].price > gamesList[gameIndex2].price && order == ASC)
                               || (gamesList[gameIndex1].price < gamesList[gameIndex2].price && order == DESC))
                            {
                                if(rents_swap(&rentsList[i], &rentsList[j]) == -1)
                                {
                                    returnValue = -1;
                                    break;
                                }
                            }
                        }
                    }
                }

                returnValue = 0;
            }
        }
    }

    return returnValue;
}

int rents_cloneList(sRental rentsDestination[], sRental rentsOrigin[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength)
{
    int returnValue = -1;
    int i;
    int customerIndex;
    int gameIndex;
    int categoryIndex;

    if(rentsDestination != NULL && rentsOrigin != NULL && customersList != NULL
       && gamesList != NULL && categoriesList != NULL
       && rentsLength > 0 && rentsLength <= RENTS_MAX
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX
       && gamesLength >0 && gamesLength <= GAMES_MAX
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        for(i = 0; i < rentsLength; i++)
        {
            customerIndex = customers_getIndexById(customersList, customersLength, rentsOrigin[i].customerId);
            gameIndex = games_getIndexById(gamesList, gamesLength, rentsOrigin[i].gameId);
            categoryIndex = categories_getIndexById(categoriesList, categoriesLength, gamesList[gameIndex].categoryId);

            if(customerIndex != -1 && gameIndex != -1 && categoryIndex != -1
               && customers_isCustomer(customersList[customerIndex], customersList, customersLength)
               && games_isGame(gamesList[gameIndex], gamesList, gamesLength, categoriesList, categoriesLength)
               && categories_isCategory(categoriesList[categoryIndex], categoriesList, categoriesLength)
               && rents_isRental(rentsOrigin[i], rentsOrigin, rentsLength, customersList, customersLength, gamesList, gamesLength, categoriesList, categoriesLength))
            {
                rentsDestination[i] = rentsOrigin[i];

                if(rents_compare(rentsDestination[i], rentsOrigin[i]) != 0)
                {
                    break;
                }
            }
        }

        if(i == rentsLength)
        {
            returnValue = 0;
        }
    }

    return returnValue;
}

int rents_filterListByCustomer(sCustomer customer, sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength)
{
    int returnValue = -1;
    int i;

    if(rentsList != NULL
       && rentsLength > 0 && rentsLength <= RENTS_MAX
       && customers_isCustomer(customer, customersList, customersLength))
    {
        for(i = 0; i < rentsLength; i++)
        {
            if(rentsList[i].customerId != -1
               && rentsList[i].customerId != customer.id)
            {
                rentsList[i].isEmpty = 1;
            }
        }

        if(i == rentsLength)
        {
            returnValue = 0;
        }
    }

    return returnValue;
}

float rents_getTotalPrices(sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength)
{
    float priceAccumulator = 0;
    int i;
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
        for(i = 0; i < rentsLength; i++)
        {
            customerIndex = customers_getIndexById(customersList, customersLength, rentsList[i].customerId);
            gameIndex = games_getIndexById(gamesList, gamesLength, rentsList[i].gameId);
            categoryIndex = categories_getIndexById(categoriesList, categoriesLength, gamesList[gameIndex].categoryId);

            if(customerIndex != -1 && gameIndex != -1 && categoryIndex != -1
               && rents_isRental(rentsList[i], rentsList, rentsLength, customersList, customersLength, gamesList, gamesLength, categoriesList, categoriesLength))
            {
                priceAccumulator += gamesList[gameIndex].price;
            }
        }
    }

    return priceAccumulator;
}

int rents_getCustomersWithoutRents(sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength)
{
    int returnValue = -1;
    int i;

    if(rentsList != NULL && customersList != NULL
       && rentsLength > 0 && rentsLength <= RENTS_MAX
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX)
    {
        for(i = 0; i < customersLength; i++)
        {
            if(customerWithRents(rentsList, rentsLength, customersList, customersLength, customersList[i].id))
            {
                customersList[i].isEmpty = 1;
            }
        }

        if(i == customersLength)
        {
            returnValue = 0;
        }
    }

    return returnValue;
}

int rents_getGamesWithoutRents(sRental rentsList[], int rentsLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength)
{
    int returnValue = -1;
    int i;

    if(rentsList != NULL && gamesList != NULL && categoriesList != NULL
       && rentsLength > 0 && rentsLength <= RENTS_MAX
       && gamesLength >0 && gamesLength <= GAMES_MAX
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        for(i = 0; i < gamesLength; i++)
        {
            if(gameWithRents(rentsList, rentsLength, gamesList, gamesLength, categoriesList, categoriesLength, gamesList[i].id))
            {
                gamesList[i].isEmpty = 1;
            }
        }

        if(i == gamesLength)
        {
            returnValue = 0;
        }
    }

    return returnValue;
}

float rents_priceAverageOfRentsByCategory(sCategory category, sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength)
{
    float priceAverage = 0;
    int counter = 0;
    int gameIndex;

    if(customersList != NULL && gamesList != NULL && categoriesList != NULL
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX
       && gamesLength >0 && gamesLength <= GAMES_MAX
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        for(int i = 0; i < rentsLength; i++)
        {
            gameIndex = games_getIndexById(gamesList, gamesLength, rentsList[i].gameId);

            if(gameIndex != -1
               && rents_isRental(rentsList[i], rentsList, rentsLength, customersList, customersLength, gamesList, gamesLength, categoriesList, categoriesLength)
               && categories_isCategory(category, categoriesList, categoriesLength)
               && gamesList[gameIndex].categoryId == category.id)
            {
                counter++;
                priceAverage += gamesList[gameIndex].price;
            }
        }

        if(priceAverage > 0)
        {
            priceAverage = priceAverage / counter;
        }
    }

    return priceAverage;
}

void rents_print(sRental rental, sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength)
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

        if(customerIndex != -1 && gameIndex != -1 && categoryIndex != -1
           && rents_isRental(rental, rentsList, rentsLength, customersList, customersLength, gamesList, gamesLength, categoriesList, categoriesLength))
        {
            printf("+=======+============+==================+==================+===========+==================+==================+\n");
            printf("|   ID  |    FECHA   |       JUEGO      |     CATEGORIA    |   PRECIO  |  NOMBRE CLIENTE  | APELLIDO CLIENTE |\n");
            printf("+=======+============+==================+==================+===========+==================+==================+\n");

            if(printRental(rental, rentsList, rentsLength, customersList, customersLength, gamesList, gamesLength, categoriesList, categoriesLength) == 0)
            {
                printf("Alquiler vacio.\n");
            }
            printf("+-------+------------+------------------+------------------+-----------+------------------+------------------+\n");
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

            if(customerIndex != -1 && gameIndex != -1 && categoryIndex != -1
               && rents_isRental(rentsList[i], rentsList, rentsLength, customersList, customersLength, gamesList, gamesLength, categoriesList, categoriesLength))
            {
                itemsCounter++;

                if(itemsCounter == 1)
                {
                    printf("+=======+============+==================+==================+===========+==================+==================+\n");
                    printf("|   ID  |    FECHA   |       JUEGO      |     CATEGORIA    |   PRECIO  |  NOMBRE CLIENTE  | APELLIDO CLIENTE |\n");
                    printf("+=======+============+==================+==================+===========+==================+==================+\n");
                }

                if(printRental(rentsList[i], rentsList, rentsLength, customersList, customersLength, gamesList, gamesLength, categoriesList, categoriesLength) == 1)
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
            printf("+-------+------------+------------------+------------------+-----------+------------------+------------------+\n");
        }
    }

    return itemsCounter;
}

int rents_printListBySex(sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength)
{
    int itemsCounter = 0;
    int flag = 0;
    int customerIndex;
    int gameIndex;
    int categoryIndex;
    char sexAux;

    if(rentsList != NULL && customersList != NULL
       && gamesList != NULL && categoriesList != NULL
       && rentsLength > 0 && rentsLength <= RENTS_MAX
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX
       && gamesLength >0 && gamesLength <= GAMES_MAX
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        do
        {
            if(!inputs_getChar(&sexAux, "Ingrese el Sexo [F] o [M]: ", ERROR_MESSAGE, 'A', 'z'))
            {
                sexAux = toupper((char)sexAux);
            }
        }while(sexAux != 'F' && sexAux != 'M');

        for (int i = 0; i < rentsLength; i++)
        {
            customerIndex = customers_getIndexById(customersList, customersLength, rentsList[i].customerId);
            gameIndex = games_getIndexById(gamesList, gamesLength, rentsList[i].gameId);
            categoryIndex = categories_getIndexById(categoriesList, categoriesLength, gamesList[gameIndex].categoryId);

            if(customerIndex != -1 && gameIndex != -1 && categoryIndex != -1
               && rents_isRental(rentsList[i], rentsList, rentsLength, customersList, customersLength, gamesList, gamesLength, categoriesList, categoriesLength)
               && tolower((char)customersList[customerIndex].sex) == tolower((char)sexAux))
            {
                itemsCounter++;

                if(itemsCounter == 1)
                {
                    printf("+=======+============+==================+==================+===========+==================+==================+\n");
                    printf("|   ID  |    FECHA   |       JUEGO      |     CATEGORIA    |   PRECIO  |  NOMBRE CLIENTE  | APELLIDO CLIENTE |\n");
                    printf("+=======+============+==================+==================+===========+==================+==================+\n");
                }

                if(printRental(rentsList[i], rentsList, rentsLength, customersList, customersLength, gamesList, gamesLength, categoriesList, categoriesLength) == 1)
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
            printf("+-------+------------+------------------+------------------+-----------+------------------+------------------+\n");
        }
    }

    return itemsCounter;
}

int rents_printListByPriceAverage(sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength)
{
    int itemsCounter = 0;
    int flag = 0;
    int customerIndex;
    int gameIndex;
    int categoryIndex;
    int categoryId;
    float priceAverage;

    if(rentsList != NULL && customersList != NULL
       && gamesList != NULL && categoriesList != NULL
       && rentsLength > 0 && rentsLength <= RENTS_MAX
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX
       && gamesLength >0 && gamesLength <= GAMES_MAX
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        categoryId = categories_userSelection("Seleccione la Categoria: ", ERROR_MESSAGE, categoriesList, categoriesLength);
        categoryIndex = categories_getIndexById(categoriesList, categoriesLength, categoryId);

        if(categoryId != -1 && categoryIndex != -1)
        {
            priceAverage = rents_priceAverageOfRentsByCategory(categoriesList[categoryIndex], rentsList, rentsLength, customersList, customersLength, gamesList, gamesLength, categoriesList, categoriesLength);
        }

        for (int i = 0; i < rentsLength; i++)
        {
            customerIndex = customers_getIndexById(customersList, customersLength, rentsList[i].customerId);
            gameIndex = games_getIndexById(gamesList, gamesLength, rentsList[i].gameId);

            if(customerIndex != -1 && gameIndex != -1 && categoryIndex != -1
               && rents_isRental(rentsList[i], rentsList, rentsLength, customersList, customersLength, gamesList, gamesLength, categoriesList, categoriesLength)
               && gamesList[gameIndex].categoryId == categoryId
               && gamesList[gameIndex].price >= priceAverage)
            {
                itemsCounter++;

                if(itemsCounter == 1)
                {
                    printf("+=======+============+==================+==================+===========+==================+==================+\n");
                    printf("|   ID  |    FECHA   |       JUEGO      |     CATEGORIA    |   PRECIO  |  NOMBRE CLIENTE  | APELLIDO CLIENTE |\n");
                    printf("+=======+============+==================+==================+===========+==================+==================+\n");
                }

                if(printRental(rentsList[i], rentsList, rentsLength, customersList, customersLength, gamesList, gamesLength, categoriesList, categoriesLength) == 1)
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
            printf("+-------+------------+------------------+------------------+-----------+------------------+------------------+\n");
            printf("Promedio de Alquileres por la categoria %s es: $ %.2f\n", categoriesList[categoryIndex].description, priceAverage);
        }
    }

    return itemsCounter;
}

int rents_printListOfTotalPricesByGame(sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength)
{
    int itemsCounter = 0;
    int flag = 0;
    int customerIndex;
    int gameId;
    int gameIndex;
    int categoryIndex;
    float totalPrices = 0;

    if(rentsList != NULL && customersList != NULL
       && gamesList != NULL && categoriesList != NULL
       && rentsLength > 0 && rentsLength <= RENTS_MAX
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX
       && gamesLength >0 && gamesLength <= GAMES_MAX
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        gameId = games_userSelection("Seleccione un Juego: ", ERROR_MESSAGE, gamesList, gamesLength, categoriesList, categoriesLength);
        gameIndex = games_getIndexById(gamesList, gamesLength, gameId);

        if(gameId != -1 && gameIndex != -1)
        {
            for (int i = 0; i < rentsLength; i++)
            {
                customerIndex = customers_getIndexById(customersList, customersLength, rentsList[i].customerId);
                categoryIndex = categories_getIndexById(categoriesList, categoriesLength, gamesList[gameIndex].categoryId);

                if(customerIndex != -1 && gameIndex != -1 && categoryIndex != -1
                   && rents_isRental(rentsList[i], rentsList, rentsLength, customersList, customersLength, gamesList, gamesLength, categoriesList, categoriesLength)
                   && rentsList[i].gameId == gameId)
                {
                    itemsCounter++;

                    totalPrices += gamesList[gameIndex].price;

                    if(itemsCounter == 1)
                    {
                        printf("+=======+============+==================+==================+===========+==================+==================+\n");
                        printf("|   ID  |    FECHA   |       JUEGO      |     CATEGORIA    |   PRECIO  |  NOMBRE CLIENTE  | APELLIDO CLIENTE |\n");
                        printf("+=======+============+==================+==================+===========+==================+==================+\n");
                    }

                    if(printRental(rentsList[i], rentsList, rentsLength, customersList, customersLength, gamesList, gamesLength, categoriesList, categoriesLength) == 1)
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
        }

        if(flag == 1)
        {
            printf("+-------+------------+------------------+------------------+-----------+------------------+------------------+\n");
            printf("El total de precios por el Juego %s es: $ %.2f\n", gamesList[gameIndex].description, totalPrices);
        }
    }

    return itemsCounter;
}

int rents_printListGamesAfter2015(sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength)
{
    int itemsCounter = 0;
    int flag = 0;
    int customerIndex;
    int gameIndex;
    int categoryIndex;
    sDate dateAux = {1, 1, 2015};

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

            if(customerIndex != -1 && gameIndex != -1 && categoryIndex != -1
               && rents_isRental(rentsList[i], rentsList, rentsLength, customersList, customersLength, gamesList, gamesLength, categoriesList, categoriesLength)
               && structs_dateCompare(rentsList[i].date, dateAux) >= 0)
            {
                itemsCounter++;

                if(itemsCounter == 1)
                {
                    printf("+=======+============+==================+==================+===========+==================+==================+\n");
                    printf("|   ID  |    FECHA   |       JUEGO      |     CATEGORIA    |   PRECIO  |  NOMBRE CLIENTE  | APELLIDO CLIENTE |\n");
                    printf("+=======+============+==================+==================+===========+==================+==================+\n");
                }

                if(printRental(rentsList[i], rentsList, rentsLength, customersList, customersLength, gamesList, gamesLength, categoriesList, categoriesLength) == 1)
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
            printf("+-------+------------+------------------+------------------+-----------+------------------+------------------+\n");
        }
    }

    return itemsCounter;
}

static sRental nullRental()
{
    sRental aux;

    aux.id = -1;
    aux.gameId = -1;
    aux.customerId = -1;
    aux.date = structs_nullDate();
    aux.isEmpty = 1;

    return aux;
}

static int getNewId(void)
{
    static int rentalId = ID_INIT_RENTAL;
    rentalId++;
    return rentalId;
}

static int printRental(sRental rental, sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength)
{
    int counter = 0;
    int customerIndex;
    int gameIndex;
    int categoryIndex;

    if(rents_isRental(rental, rentsList, rentsLength, customersList, customersLength, gamesList, gamesLength, categoriesList, categoriesLength))
    {
        customerIndex = customers_getIndexById(customersList, customersLength,rental.customerId);
        gameIndex = games_getIndexById(gamesList, gamesLength, rental.gameId);
        categoryIndex = categories_getIndexById(categoriesList, categoriesLength, gamesList[gameIndex].categoryId);

        printf("| %5d | %02d/%02d/%4d | %16s | %16s | %9.2f | %16s | %16s |\n",
               rental.id,
               rental.date.day, rental.date.month, rental.date.year,
               arrays_stringToCamelCase(gamesList[gameIndex].description, GAME_NAME_MAX),
               arrays_stringToCamelCase(categoriesList[categoryIndex].description, CATEGORIES_MAX),
               gamesList[gameIndex].price,
               arrays_stringToCamelCase(customersList[customerIndex].name, CUSTOMER_NAME_MAX),
               arrays_stringToCamelCase(customersList[customerIndex].lastName, CUSTOMER_NAME_MAX));
        counter = 1;
    }

    return counter;
}

static int customerWithRents(sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, int customerId)
{
    int rented = 0;
    int customerIndex;
    int i;

    if(rentsList != NULL && customersList != NULL
       && rentsLength > 0 && rentsLength <= RENTS_MAX
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX)
    {
        customerIndex = customers_getIndexById(customersList, customersLength, customerId);

        if(customerIndex != -1
           && customers_isCustomer(customersList[customerIndex], customersList, customersLength))
        {
            for(i = 0; i < rentsLength; i++)
            {
                if(!rentsList[i].isEmpty
                   && rentsList[i].customerId == customerId)
                {
                    rented = 1;
                    break;
                }
            }
        }
    }

    return rented;
}

static int gameWithRents(sRental rentsList[], int rentsLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength, int gameId)
{
    int rented = 0;
    int gameIndex;
    int categoryIndex;
    int i;

    if(rentsList != NULL && gamesList != NULL && categoriesList != NULL
       && rentsLength > 0 && rentsLength <= RENTS_MAX
       && gamesLength > 0 && gamesLength <= GAMES_MAX
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        gameIndex = games_getIndexById(gamesList, gamesLength, gameId);
        categoryIndex = categories_getIndexById(categoriesList, categoriesLength, gamesList[gameIndex].categoryId);

        if(gameIndex != -1 && categoryIndex != -1
           && games_isGame(gamesList[gameIndex], gamesList, gamesLength, categoriesList, categoriesLength))
        {
            for(i = 0; i < rentsLength; i++)
            {
                if(!rentsList[i].isEmpty
                   && rentsList[i].gameId == gameId)
                {
                    rented = 1;
                    break;
                }
            }
        }
    }

    return rented;
}
