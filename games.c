#include "games.h"

/** \brief Funcion que devuelve una estructura vacia.
 *
 * \param void No requiere parametros.
 * \return sGame Devuelve una estructura con valores "nulos".
 *
 */
static sGame nullGame(void);

/** \brief Funcion que determina si la estructura es un Juego.
 *
 * \param game sGame Estructura de Juego a evaluar.
 * \param category sCategory Estructura de Categoria a evaluar.
 * \return int
 *          [0] Si no es un Juego.
 *          [1] Si es un Juego.
 *
 */
static int isGame(sGame game, sCategory category);

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

int games_compare(sGame game1, sGame game2)
{
    int compare = -2;

    if(game1.isEmpty == FALSE
       && game1.isEmpty == FALSE)
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
    int returnValue = ERROR;
    sGame aux1;
    sGame aux2;

    aux1 = *game1;
    aux2 = *game2;
    *game1 = *game2;
    *game2 = aux1;

    if(games_compare(*game1, aux2) == 0
       && games_compare(*game2, aux1) == 0)
    {
        returnValue = OK;
    }

    return returnValue;
}

int games_init(sGame gamesList[], int gamesLength)
{
    int returnValue = ERROR;
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
            returnValue = OK;
        }
    }

    return returnValue;
}

void games_hardcode(sGame gamesList[], int gamesLength)
{
    int indexHardcodeMax = 9;

    sGame gamesAux[] = {
        {getNewId(), "monopoly", 1200.0, 101, FALSE},
        {getNewId(), "quien es quien", 550.0, 101, FALSE},
        {getNewId(), "age of empires", 3500.0, 103, FALSE},
        {getNewId(), "truco", 150.0, 104, FALSE},
        {getNewId(), "cartas de magia", 600.0, 105, FALSE},
        {getNewId(), "ruleta", 4000.0, 102, FALSE},
        {getNewId(), "bingo", 400.0, 102, FALSE},
        {getNewId(), "uno", 450.0, 104, FALSE},
        {getNewId(), "poker", 650.0, 104, FALSE},
        {getNewId(), "set de magia", 5500.0, 105, FALSE},
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

void games_print(sGame game, sCategory categoriesList[], int categoriesLength)
{
    int categoryIndex;

    categoryIndex = categories_getIndexById(categoriesList, categoriesLength, game.categoryId);

    if(categoryIndex != ERROR
       && isGame(game, categoriesList[categoryIndex]))
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

            if(categoryIndex != ERROR
               && isGame(gamesList[i], categoriesList[categoryIndex]))
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

    aux.id = EMPTY_ID;
    strcpy(aux.description, "NULL");
    aux.price = 0.0f;
    aux.categoryId = EMPTY_ID;
    aux.isEmpty = TRUE;

    return aux;
}

static int isGame(sGame game, sCategory category)
{
    int returnValue = 0;
    int categoryIndex;

    if(game.id != EMPTY_ID
       && game.description != NULL
       && game.isEmpty == FALSE
       && categories_isCategory(category))
    {
        returnValue = 1;
    }

    return returnValue;
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

    if(isGame(game, category))
    {
        printf("| %5d | %20s | %9.2f | %20s |\n",
               game.id, arrays_stringToCamelCase(game.description, GAMES_MAX)
               ,game.price, arrays_stringToCamelCase(category.description, CATEGORIES_MAX));
        counter = 1;
    }

    return counter;
}
