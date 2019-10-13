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

/** \brief Obtiene el primer indice vacio del arreglo
 *
 * \param gamesList[] sGame Arreglo de estrucutras.
 * \param gamesLength int Longitud del arreglo.
 * \return int
 *          Indice de la primera posicion vacia del arreglo.
 *          [ERROR] Si no hay ninguna posicion vacia.
 *
 */
int games_getEmptyIndex(sGame gamesList[], int gamesLength);

/** \brief Obtiene el indice de la estructura buscada por el ID.
 *
 * \param gamesList[] sGame Arreglo de estrucutras.
 * \param gamesLength int Longitud del arreglo.
 * \param id int ID a buscar.
 * \return int
 *          Indice del ID buscado.
 *          [ERROR] Si el ID buscado no existe o esta inactivo.
 *
 */
int games_getIndexById(sGame gamesList[], int gamesLength, int id);

/** \brief Seleccion de una estructura consultando por pantalla al usuario.
 *
 * \param message[] char Mensaje de solicitud al usuario.
 * \param eMessage[] char Mensaje ante error del valor ingresado por el usuario.
 * \param gamesList[] sGame Arreglo de estrucutras de Juegos.
 * \param gamesLength int Longitud del arreglo de Juegos.
 * \param categoriesList[] sCategory Arreglo de estrucutras de Categorias.
 * \param categoriesLength int Longitud del arreglo de Categorias.
 * \return int
 *          ID de la estructura elegida por el usuario.
 *          [ERROR] Si la estructura elegida no se encuentra.
 *
 */
int games_userSelection(char message[], char eMessage[], sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength);
int games_add(sGame gamesList[], int gamesLength);
int games_modify(sGame gamesList[], int gamesLength);
int games_delete(sGame gamesList[], int gamesLength);

/** \brief Ordenamiento de un arreglo de estructuras.
 *
 * \param gamesList[] sGame Arreglo de estrucutras de Juegos.
 * \param gamesLength int Longitud del arreglo de Juegos.
 * \param categoriesList[] sCategory Arreglo de estrucutras de Categorias.
 * \param categoriesLength int Longitud del arreglo de Categorias.
 * \param order int
 *          [ASC] Para orden ascendente.
 *          [DESC] Para orden descendente.
 * \return int
 *          [ERROR] Si no se realizo ningun ordenamiento.
 *          [OK] Si al menos hizo un minimo ordenamiento.
 *
 */
int games_sort(sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength, int order);

/** \brief Impresion con formato tabla de una estructura.
 *
 * \param game sGame Estructura de Juego.
 * \param categoriesList[] sCategory Arreglo de estrucutras de Categorias.
 * \param categoriesLength int Longitud del arreglo de Categorias.
 * \return void No retorna valores.
 *
 */
void games_print(sGame game, sCategory categoriesList[], int categoriesLength);

/** \brief Impresion con formato tabla de un arreglo de estructuras.
 *
 * \param gamesList[] sGame Arreglo de estrucutras de Juegos.
 * \param gamesLength int Longitud del arreglo de Juegos.
 * \param categoriesList[] sCategory Arreglo de estrucutras de Categorias.
 * \param categoriesLength int Longitud del arreglo de Categorias.
 * \return int Cantidad de estructuras impresas.
 *
 */
int games_printList(sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength);


#endif // GAMES_H_INCLUDED
