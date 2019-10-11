#ifndef CATEGORIES_H_INCLUDED
#define CATEGORIES_H_INCLUDED

#include "inputs.h"

#define CATEGORY_NAME_MAX 51 /**< Longitud maxima de la descripcion de una Categoria. >*/
#define ID_INIT_CATEGORY 100 /**< Numeracion inicial de una Categoria. >*/

/*! \struct sCategory
 * \brief Tipo de dato de una Categoria.
 *
 * \field id int Campo ID de la estructura.
 * \field description[] char Descripcion de la estructura.
 * \field isEmpty int Indicador de posicion llena o vacia..
 *
 */
typedef struct
{
    int id; /**< Campo ID de la estructura. >*/
    char description[CATEGORY_NAME_MAX]; /**< Descripcion de la estructura. >*/
    int isEmpty; /**< Indicador de posicion llena o vacia. >*/
} sCategory;

int categories_compare(sCategory game1, sCategory game2);
int categories_swap(sCategory* game1, sCategory* game2);
int categories_init(sCategory gamesList[], int gamesLength);
void categories_hardcode(sCategory gamesList[], int gamesLength);
int categories_getIndex(sCategory gamesList[], int gamesLength);
int categories_getId(sCategory gamesList[], int gamesLength);
int categories_userSelection(sCategory gamesList[], int gamesLength);
int categories_add(sCategory gamesList[], int gamesLength);
int categories_modify(sCategory gamesList[], int gamesLength);
int categories_delete(sCategory gamesList[], int gamesLength);
int categories_sort(sCategory gamesList[], int gamesLength, int order);
int categories_print(sCategory game);
int categories_printList(sCategory gamesList[], int gamesLength);

#endif // CATEGORIES_H_INCLUDED
