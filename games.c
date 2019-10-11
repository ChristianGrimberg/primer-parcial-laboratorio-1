#include "games.h"

static int isGame(sGame game);
static sGame nullGame(void);
static int getNewId(void);
static int printGame(sGame game);

static int getNewId(void)
{
    static int gameId = ID_INIT_GAME;
    gameId++;
    return gameId;
}
