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
