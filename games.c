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
 * \param game sGame Estructura a evaluar.
 * \return int
 *          [0] Si no es un Juego.
 *          [1] Si es un Juego.
 *
 */
static int isGame(sGame game);

/** \brief Obtiene un nuevo ID autoincremental.
 *
 * \param void No requiere parametros.
 * \return int Retorna un nuevo ID incremental.
 *
 */
static int getNewId(void);

/** \brief Imprime en pantalla los valores de la estructura.
 *
 * \param game sGame Estructura a imprimir.
 * \return int
 *          [0] Si la estructura esta vacia.
 *          [1] Si la estructura esta llena y pudo imprimirse.
 *
 */
static int printGame(sGame game);

int games_compare(sGame game1, sGame game2)
{
    int compare = -2;

    if(isGame(game1) && isGame(game2))
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

static int isGame(sGame game)
{
    int returnValue = 0;

    if(game.id != EMPTY_ID
       && game.description != NULL
       && game.categoryId != EMPTY_ID
       && game.isEmpty == FALSE)
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
