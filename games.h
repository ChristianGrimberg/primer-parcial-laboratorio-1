#ifndef GAMES_H_INCLUDED
#define GAMES_H_INCLUDED

#include "categories.h"

#define GAME_NAME_MAX 51 /**< Longitud maxima de la descripcion de un Juego. >*/
#define ID_INIT_GAME 200 /**< Numeracion inicial de un Juego. >*/
#define GAMES_MAX 100 /**< Cantidad maxima de categorias en un arreglo. >*/

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

/** \brief Funcion que compara dos estructuras de Juegos.
 *
 * \param game1 sGame Primer estructura a comparar.
 * \param game2 sGame Segunda estructura a comparar.
 * \return int
 *          [-1] Si el ID de la estructura 1 es mayor al ID de la  estructura 2.
 *          [1] Si el ID de la estructura 1 es menor al ID de la estructura 2.
 *          [0] Si ambos ID son iguales.
 *
 */
int games_compare(sGame game1, sGame game2);

/** \brief Intercambio de estructuras.
 *
 * \param game1 sGame* Direccion de memoria de la estructura 1.
 * \param game2 sGame* Direccion de memoria de la estructura 2.
 * \return int
 *          [ERROR] Si hubo un error en el intercambio.
 *          [OK] Si el intercambio fue exitoso.
 *
 */
int games_swap(sGame* game1, sGame* game2);

/** \brief Inicializacion de arreglo de estructuras.
 *
 * \param gamesList[] sGame Arreglo de estrucutras.
 * \param gamesLength int Longitud del arreglo.
 * \return int
 *          [ERROR] Si hubo un error al inicializar.
 *          [OK] Si la inicializacion se realizo correctamente.
 *
 */
int games_init(sGame gamesList[], int gamesLength);

/** \brief Harcodeo de estructuras de ejemplo.
 *
 * \param gamesList[] sGame Arreglo de estrucutras.
 * \param gamesLength int Longitud del arreglo.
 * \return void No retorna valores.
 *
 */
void games_hardcode(sGame gamesList[], int gamesLength);
int games_getEmptyIndex(sGame gamesList[], int gamesLength);
int games_getIndexId(sGame gamesList[], int gamesLength, int id);
int games_userSelection(sGame gamesList[], int gamesLength);
int games_add(sGame gamesList[], int gamesLength);
int games_modify(sGame gamesList[], int gamesLength);
int games_delete(sGame gamesList[], int gamesLength);
int games_sort(sGame gamesList[], int gamesLength, int order);

/** \brief Impresion con formato tabla de una estructura.
 *
 * \param game sGame Estructura a imprimir.
 * \return void No retorna valores.
 *
 */
void games_print(sGame game);
int games_printList(sGame gamesList[], int gamesLength);


#endif // GAMES_H_INCLUDED
