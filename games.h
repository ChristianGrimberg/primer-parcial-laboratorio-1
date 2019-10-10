#ifndef GAMES_H_INCLUDED
#define GAMES_H_INCLUDED

#include "categories.h"

#define GAME_NAME_MAX 51 /**< Longitud maxima de la descripcion de un juego. >*/

/*! \struct sGame
 * \brief Tipo de dato de un Juego.
 *
 * \field id int Campo ID de la estructura.
 * \field description[] char Descripcion de la estructura.
 * \field price float Importe de la estructura.
 * \field categoryId int Clave foranea del ID de Categoria.
 * \field isEmpty int Indicador de posicion llena o vacia..
 *
 */
typedef struct
{
    int id; /**< Campo ID de la estructura. >*/
    char description[GAME_NAME_MAX]; /**< Descripcion de la estructura. >*/
    float price; /**< Importe de la estructura. >*/
    int categoryId; /**< Clave foranea del ID de Categoria. >*/
    int isEmpty; /**< Indicador de posicion llena o vacia. >*/
} sGame;

int games_compare(sGame game1, sGame game2);
int games_swap(sGame* game1, sGame* game2);
int games_init(sGame gamesList[], int gamesLength);
void games_hardcode(sGame gamesList[], int gamesLength);
int games_getIndex(sGame gamesList[], int gamesLength);
int games_getId(sGame gamesList[], int gamesLength);
int games_userSelection(sGame gamesList[], int gamesLength);
int games_add(sGame gamesList[], int gamesLength);
int games_modify(sGame gamesList[], int gamesLength);
int games_delete(sGame gamesList[], int gamesLength);
int games_sort(sGame gamesList[], int gamesLength, int order);
int games_print(sGame game);
int games_printList(sGame gamesList[], int gamesLength);


#endif // GAMES_H_INCLUDED
