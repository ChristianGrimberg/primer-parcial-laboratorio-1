#include "games.h"

/** \brief Funcion que determina si la estructura es un Juego.
 *
 * \param category sCategory Estructura a evaluar.
 * \return int
 *          [0] Si no es un Juego.
 *          [1] Si es un Juego.
 *
 */
static int isGame(sGame game);

/** \brief Funcion que devuelve una estructura vacia.
 *
 * \param void No requiere parametros.
 * \return sCategory Devuelve una estructura con valores "nulos".
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
static int printGame(sGame game);

static int getNewId(void)
{
    static int gameId = ID_INIT_GAME;
    gameId++;
    return gameId;
}
