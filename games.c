#include "games.h"

/** \brief Funcion que devuelve una estructura vacia.
 *
 * \param void No requiere parametros.
 * \return sGame Devuelve una estructura con valores "nulos".
 *
 */
static sGame nullGame(void);

/** \brief Obtiene un nuevo ID autoincremental.
 *
 * \param void No requiere parametros.
 * \return int Retorna un nuevo ID incremental.
 *
 */
static int getNewId(void);

/** \brief Imprime en pantalla los valores de la estructura.
 *
 * \param game sGame Estructura de Juego.
 * \param category sCategory Estructura de Categoria.
 * \return int
 *          [0] Si las estructuras estan vacias.
 *          [1] Si la estructuras estan llenas y se imprimieron.
 *
 */
static int printGame(sGame game, sCategory category);

int games_isGame(sGame game, sCategory category)
{
    int returnValue = 0;

    if(game.id != -1
       && game.description != NULL
       && game.isEmpty == 0
       && categories_isCategory(category) && category.id == game.categoryId)
    {
        returnValue = 1;
    }

    return returnValue;
}

int games_compare(sGame game1, sGame game2)
{
    int compare = -2;

    if(!game1.isEmpty
       && !game1.isEmpty)
    {
        if(game1.id > game2.id)
        {
            compare = 1;
        }
        else
        {
            if(game1.id < game2.id)
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

int games_swap(sGame* game1, sGame* game2)
{
    int returnValue = -1;
    sGame aux1;
    sGame aux2;

    aux1 = *game1;
    aux2 = *game2;
    *game1 = *game2;
    *game2 = aux1;

    if(games_compare(*game1, aux2) == 0
       && games_compare(*game2, aux1) == 0)
    {
        returnValue = 0;
    }

    return returnValue;
}

int games_init(sGame gamesList[], int gamesLength)
{
    int returnValue = -1;
    int i;

    if(gamesList != NULL
       && gamesLength > 0 && gamesLength <= GAMES_MAX)
    {
        for(i = 0 ; i < gamesLength; i++)
        {
            gamesList[i] = nullGame();
        }

        if(i == gamesLength)
        {
            returnValue = 0;
        }
    }

    return returnValue;
}

void games_hardcode(sGame gamesList[], int gamesLength)
{
    int indexHardcodeMax = 9;

    sGame gamesAux[] = {
        {getNewId(), "monopoly", 1200.0, 101, 0},
        {getNewId(), "quien es quien", 550.0, 101, 0},
        {getNewId(), "age of empires", 3500.0, 103, 0},
        {getNewId(), "truco", 150.0, 104, 0},
        {getNewId(), "cartas de magia", 600.0, 105, 0},
        {getNewId(), "ruleta", 4000.0, 102, 0},
        {getNewId(), "bingo", 400.0, 102, 0},
        {getNewId(), "uno", 450.0, 104, 0},
        {getNewId(), "poker", 650.0, 104, 0},
        {getNewId(), "set de magia", 5500.0, 105, 0},
    };

    if(gamesList != NULL
       && gamesLength > 0 && gamesLength <= GAMES_MAX)
    {
        for (int i = 0; i < gamesLength; i++)
        {
            if(i <= indexHardcodeMax)
            {
                gamesList[i] = gamesAux[i];
            }
            else
            {
                gamesList[i] = nullGame();
            }
        }
    }
}

int games_getEmptyIndex(sGame gamesList[], int gamesLength)
{
    int returnValue = -1;
    int i;

    if(gamesList != NULL
       && gamesLength > 0 && gamesLength <= GAMES_MAX)
    {
        for (i = 0; i < gamesLength; i++)
        {
            if(gamesList[i].isEmpty)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}

int games_getIndexById(sGame gamesList[], int gamesLength, int id)
{
    int returnValue = -1;

    if(gamesList != NULL
       && gamesLength > 0 && gamesLength <= GAMES_MAX)
    {
        for (int i = 0; i < gamesLength; i++)
        {
            if(gamesList[i].id == id
               && !gamesList[i].isEmpty)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}

int games_userSelection(char message[], char eMessage[], sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength)
{
    int returnValue = -1;
    int auxId = 0;
    int auxIndex = 0;

    if(message != NULL && eMessage != NULL
       && gamesList != NULL && categoriesList != NULL
       && gamesLength > 0 && gamesLength <= GAMES_MAX
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        if (games_printList(gamesList, gamesLength, categoriesList, categoriesLength) == 0)
        {
            printf("No hay Juegos activos.\n");
        }
        else
        {
            if(!inputs_getInt(&auxId, message, eMessage, ID_INIT_GAME+1, ID_INIT_GAME+GAMES_MAX))
            {
                auxIndex = games_getIndexById(gamesList, gamesLength, auxId);

                if(auxIndex != -1)
                {
                    returnValue = auxId;
                }
                else
                {
                    printf("No se encuentra el Juego ingresado.\n");
                }
            }
        }
    }

    return returnValue;
}

int games_add(sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength)
{
    int returnValue = -1;
    int indexGameAux;
    int idCategoryAux;
    float priceAux;
    char descriptionAux[CATEGORY_NAME_MAX];

    if(gamesList != NULL && categoriesList != NULL
       && gamesLength > 0 && gamesLength <= GAMES_MAX
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        indexGameAux = games_getEmptyIndex(gamesList, gamesLength);

        if(indexGameAux != -1
           && !inputs_getString(descriptionAux,
                                "Ingrese la descripcion del Juego: ", ERROR_MESSAGE, 1, GAME_NAME_MAX)
           && !inputs_getFloat(&priceAux,
                               "Ingrese el precio: ", ERROR_MESSAGE, 0, GAMES_PRICE_MAX))
        {
            idCategoryAux = categories_userSelection("Seleccione un Categoria: ", ERROR_MESSAGE, categoriesList, categoriesLength);

            if(idCategoryAux != -1)
            {
                gamesList[indexGameAux].id = getNewId();
                strcpy(gamesList[indexGameAux].description, descriptionAux);
                gamesList[indexGameAux].price = priceAux;
                gamesList[indexGameAux].categoryId = idCategoryAux;
                gamesList[indexGameAux].isEmpty = 0;
                returnValue = 0;
            }
        }
    }

    return returnValue;
}

int games_modify(sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength)
{
    int returnValue = -1;
    int id;
    int index;
    int option;
    int categoryIdAux;
    float priceAux;
    char descriptionAux[CATEGORY_NAME_MAX];

    if(gamesList != NULL && categoriesList != NULL
       && gamesLength > 0 && gamesLength <= GAMES_MAX
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        id = games_userSelection("Ingrese el ID del Juego a modificar: ",
            ERROR_MESSAGE, gamesList, gamesLength, categoriesList, categoriesLength);

        if(id != -1)
        {
            index = games_getIndexById(gamesList, gamesLength, id);

            if(index != -1)
            {
                inputs_clearScreen();

                printf("=======================================================\n");
                printf("                MODIFICAR JUEGO\n");
                printf("=======================================================\n");
                printf("    1 - Modificar la Descripcion\n");
                printf("    2 - Modificar el Precio\n");
                printf("    3 - Modificar la Categoria\n");
                printf("    4 - Volver al menu principal\n");
                printf("=======================================================\n");

                if(!inputs_getInt(&option, "Ingrese la opcion deseada: ", ERROR_MESSAGE, 1, 4))
                {
                    switch(option)
                    {
                        case 1:
                            if(!inputs_getString(descriptionAux, "Ingrese una nueva descripcion: ", ERROR_MESSAGE, 1, GAME_NAME_MAX))
                            {
                                strcpy(gamesList[index].description, descriptionAux);
                                printf("Descripcion modificada con exito.\n");
                                returnValue = 0;
                            }
                            break;
                        case 2:
                            if(!inputs_getFloat(&priceAux, "Ingrese el nuevo precio: ", ERROR_MESSAGE, 0, GAMES_PRICE_MAX))
                            {
                                gamesList[index].price = priceAux;
                                printf("Precio modificado con exito.\n");
                                returnValue = 0;
                            }
                            break;
                        case 3:
                            categoryIdAux = categories_userSelection("Elija una nueva Categoria: ", ERROR_MESSAGE, categoriesList, categoriesLength);

                            if(categoryIdAux != -1)
                            {
                                gamesList[index].categoryId = categoryIdAux;
                                printf("Categoria modificada con exito.\n");
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

int games_delete(sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength)
{
    int returnValue = -1;
    int id;
    int index;

    if(gamesList != NULL && categoriesList != NULL
       && gamesLength > 0 && gamesLength <= GAMES_MAX
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        id = games_userSelection("Ingrese el ID del Juego a dar de baja: ",
            ERROR_MESSAGE, gamesList, gamesLength, categoriesList, categoriesLength);

        if(id != -1)
        {
            index = games_getIndexById(gamesList, gamesLength, id);

            if(index != -1)
            {
                inputs_clearScreen();
                printf("ATENCION! ESTA A PUNTO DE DAR DE BAJA EL SIGUIENTE JUEGO:\n");
                games_print(gamesList[index], categoriesList, categoriesLength);

                if(inputs_userResponse("ESTA DE ACUERDO? [S] [N]: "))
                {
                    gamesList[index].isEmpty = 1;
                    returnValue = 0;
                }
            }
        }
    }

    return returnValue;
}

int games_sort(sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength, int order)
{
    int returnValue = -1;
    int categoryIndex1;
    int categoryIndex2;

    if(gamesList != NULL && categoriesList != NULL
       && gamesLength > 0 && gamesLength <= GAMES_MAX
       && (order == ASC || order == DESC))
    {
        for(int i= 0; i < gamesLength-1 ; i++)
        {
            for(int j = i+1; j < gamesLength; j++)
            {
                categoryIndex1 = categories_getIndexById(categoriesList, categoriesLength, gamesList[i].categoryId);
                categoryIndex2 = categories_getIndexById(categoriesList, categoriesLength, gamesList[j].categoryId);

                if(games_isGame(gamesList[i], categoriesList[categoryIndex1])
                   && games_isGame(gamesList[j], categoriesList[categoryIndex2]))
                {
                    if((strcmp(arrays_stringToCamelCase(gamesList[i].description, GAME_NAME_MAX),
                               arrays_stringToCamelCase(gamesList[j].description, GAME_NAME_MAX)) > 0
                        && order == ASC)
                        || (strcmp(arrays_stringToCamelCase(gamesList[i].description, GAME_NAME_MAX),
                               arrays_stringToCamelCase(gamesList[j].description, GAME_NAME_MAX)) < 0
                        && order == DESC))
                    {
                        if(games_swap(&gamesList[i], &gamesList[j]) == -1)
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

void games_print(sGame game, sCategory categoriesList[], int categoriesLength)
{
    int categoryIndex;

    categoryIndex = categories_getIndexById(categoriesList, categoriesLength, game.categoryId);

    if(games_isGame(game, categoriesList[categoryIndex])
       && categories_isCategory(categoriesList[categoryIndex]))
    {
        printf("+=======+======================+===========+======================+\n");
        printf("|   ID  |      DESCRIPCION     |   PRECIO  |       CATEGORIA      |\n");
        printf("+=======+======================+===========+======================+\n");

        if(printGame(game, categoriesList[categoryIndex]) == 0)
        {
            printf("Juego vacio.\n");
        }
        printf("+-------+----------------------+-----------+----------------------+\n");
    }
}

int games_printList(sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength)
{
    int itemsCounter = 0;
    int flag = 0;
    int categoryIndex;

    if(gamesList != NULL && categoriesList != NULL
       && gamesLength >0 && gamesLength <= GAMES_MAX
       && categoriesLength > 0 && categoriesLength <= CATEGORIES_MAX)
    {
        for (int i = 0; i < gamesLength; i++)
        {
            categoryIndex = categories_getIndexById(categoriesList, categoriesLength, gamesList[i].categoryId);

            if(categoryIndex != -1
               && games_isGame(gamesList[i], categoriesList[categoryIndex]))
            {
                itemsCounter++;

                if(itemsCounter == 1)
                {
                    printf("+=======+======================+===========+======================+\n");
                    printf("|   ID  |      DESCRIPCION     |   PRECIO  |       CATEGORIA      |\n");
                    printf("+=======+======================+===========+======================+\n");
                }

                if(printGame(gamesList[i], categoriesList[categoryIndex]) == 1)
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
            printf("+-------+----------------------+-----------+----------------------+\n");
        }
    }

    return itemsCounter;
}

static sGame nullGame()
{
    sGame aux;

    aux.id = -1;
    strcpy(aux.description, "NULL");
    aux.price = 0.0f;
    aux.categoryId = -1;
    aux.isEmpty = 1;

    return aux;
}

static int getNewId(void)
{
    static int gameId = ID_INIT_GAME;
    gameId++;
    return gameId;
}

static int printGame(sGame game, sCategory category)
{
    int counter = 0;

    if(games_isGame(game, category))
    {
        printf("| %5d | %20s | %9.2f | %20s |\n",
               game.id, arrays_stringToCamelCase(game.description, GAME_NAME_MAX)
               ,game.price, arrays_stringToCamelCase(category.description, CATEGORY_NAME_MAX));
        counter = 1;
    }

    return counter;
}
