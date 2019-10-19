#ifndef GAMES_H_INCLUDED
#define GAMES_H_INCLUDED

#include "categories.h"

#define GAME_NAME_MAX 51 /**< Longitud maxima de la descripcion de un Juego. >*/
#define ID_INIT_GAME 200 /**< Numeracion inicial de un Juego. >*/
#define GAMES_MAX 99 /**< Cantidad maxima de Juegos en un arreglo. >*/
#define GAMES_PRICE_MAX 10000000 /** Precio maximo de un Juego. >*/

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

/** \brief Funcion que determina si la estructura es un Juego.
 *
 * \param game sGame Estructura de Juego a evaluar.
 * \param category sCategory Estructura de Categoria a evaluar.
 * \return int
 *          [0] Si no es un Juego.
 *          [1] Si es un Juego.
 *
 */
int games_isGame(sGame game, sCategory category);

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
 *          [-1] Si hubo un error en el intercambio.
 *          [0] Si el intercambio fue exitoso.
 *
 */
int games_swap(sGame* game1, sGame* game2);

/** \brief Inicializacion del arreglo de estructuras.
 *
 * \param gamesList[] sGame Arreglo de estructuras.
 * \param gamesLength int Longitud del arreglo.
 * \return int
 *          [-1] Si hubo un error al inicializar.
 *          [0] Si la inicializacion se realizo correctamente.
 *
 */
int games_init(sGame gamesList[], int gamesLength);

/** \brief Harcodeo de estructuras de ejemplo.
 *
 * \param gamesList[] sGame Arreglo de estructuras.
 * \param gamesLength int Longitud del arreglo.
 * \return void No retorna valores.
 *
 */
void games_hardcode(sGame gamesList[], int gamesLength);

/** \brief Obtiene el primer indice vacio del arreglo
 *
 * \param gamesList[] sGame Arreglo de estructuras.
 * \param gamesLength int Longitud del arreglo.
 * \return int
 *          Indice de la primera posicion vacia del arreglo.
 *          [-1] Si no hay ninguna posicion vacia.
 *
 */
int games_getEmptyIndex(sGame gamesList[], int gamesLength);

/** \brief Obtiene el indice de la estructura buscada por el ID.
 *
 * \param gamesList[] sGame Arreglo de estructuras.
 * \param gamesLength int Longitud del arreglo.
 * \param id int ID a buscar.
 * \return int
 *          Indice del ID buscado.
 *          [-1] Si el ID buscado no existe o esta inactivo.
 *
 */
int games_getIndexById(sGame gamesList[], int gamesLength, int id);

/** \brief Seleccion de una estructura consultando por pantalla al usuario.
 *
 * \param message[] char Mensaje de solicitud al usuario.
 * \param eMessage[] char Mensaje ante error del valor ingresado por el usuario.
 * \param gamesList[] sGame Arreglo de estructuras de Juegos.
 * \param gamesLength int Longitud del arreglo de Juegos.
 * \param categoriesList[] sCategory Arreglo de estructuras de Categorias.
 * \param categoriesLength int Longitud del arreglo de Categorias.
 * \return int
 *          ID de la estructura elegida por el usuario.
 *          [-1] Si la estructura elegida no se encuentra.
 *
 */
int games_userSelection(char message[], char eMessage[], sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength);

/** \brief Agregar una nueva estructura en una posicion vacia del arreglo.
 *
 * \param gamesList[] sGame Arreglo de estructuras de Juegos.
 * \param gamesLength int Longitud del arreglo de Juegos.
 * \param categoriesList[] sCategory Arreglo de estructuras de Categorias.
 * \param categoriesLength int Longitud del arreglo de Categorias.
 * \return int
 *          [-1] Si hubo un error al cargar la estructura.
 *          [0] Si pudo cargarse correctamente la estructura.
 *
 */
int games_add(sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength);

/** \brief Modificacion de una estructura.
 *
 * \param gamesList[] sGame Arreglo de estructuras de Juegos.
 * \param gamesLength int Longitud del arreglo de Juegos.
 * \param categoriesList[] sCategory Arreglo de estructuras de Categorias.
 * \param categoriesLength int Longitud del arreglo de Categorias.
 * \return int
 *          [-1] Si hubo un error al modificar la estructura.
 *          [0] Si pudo modificarse correctamente la estructura.
 *
 */
int games_modify(sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength);

/** \brief Inactivacion de una estructura dentro de un arreglo.
 *
 * \param gamesList[] sGame Arreglo de estructuras de Juegos.
 * \param gamesLength int Longitud del arreglo de Juegos.
 * \param categoriesList[] sCategory Arreglo de estructuras de Categorias.
 * \param categoriesLength int Longitud del arreglo de Categorias.
 * \return int
 *          [-1] Si hubo un error al inactivar la estructura.
 *          [0] Si pudo inactivarse correctamente la estructura.
 *
 */
int games_delete(sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength);

/** \brief Ordenamiento de un arreglo de estructuras.
 *
 * \param gamesList[] sGame Arreglo de estructuras de Juegos.
 * \param gamesLength int Longitud del arreglo de Juegos.
 * \param categoriesList[] sCategory Arreglo de estructuras de Categorias.
 * \param categoriesLength int Longitud del arreglo de Categorias.
 * \param order int
 *          [ASC] Para orden ascendente.
 *          [DESC] Para orden descendente.
 * \return int
 *          [-1] Si hubo un error para realizar el ordenamiento.
 *          [0] Si pudo procesar el algoritmo de ordenamiento.
 *
 */
int games_sort(sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength, int order);

/** \brief Clonacion de Arreglos de Juegos.
 *
 * \param gamesDestination[] sGame Arreglo destino de Juegos.
 * \param gamesOrigin[] sGame Arreglo origen de Juegos.
 * \param gamesLength int Longitud del arreglo de Juegos.
 * \param categoriesList[] sCategory Arreglo de estructuras de Categorias.
 * \param categoriesLength int Longitud del arreglo de Categorias.
 * \return int
 *          [-1] Si hubo un error al clonar.
 *          [0] Si la clonacion fue realizada con exito.
 *
 */
int games_cloneList(sGame gamesDestination[], sGame gamesOrigin[], int gamesLength, sCategory categoriesList[], int categoriesLength);

/** \brief Filtrado de Arreglo de Juegos por Categoria.
 *
 * \param gamesList[] sGame Arreglo de estructuras de Juegos.
 * \param gamesLength int Longitud del arreglo de Juegos.
 * \param categoriesList[] sCategory Arreglo de estructuras de Categorias.
 * \param categoriesLength int Longitud del arreglo de Categorias.
 * \param category sCategory Categoria a filtrar.
 * \return int
 *          [-1] Si hubo un error al filtrar.
 *          [0] Si el arreglo fue recorrido con exito.
 *
 */
int games_filterListByCategory(sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength, sCategory category);

/** \brief Impresion con formato tabla de una estructura.
 *
 * \param game sGame Estructura de Juego.
 * \param categoriesList[] sCategory Arreglo de estructuras de Categorias.
 * \param categoriesLength int Longitud del arreglo de Categorias.
 * \return void No retorna valores.
 *
 */
void games_print(sGame game, sCategory categoriesList[], int categoriesLength);

/** \brief Impresion con formato tabla de un arreglo de estructuras.
 *
 * \param gamesList[] sGame Arreglo de estructuras de Juegos.
 * \param gamesLength int Longitud del arreglo de Juegos.
 * \param categoriesList[] sCategory Arreglo de estructuras de Categorias.
 * \param categoriesLength int Longitud del arreglo de Categorias.
 * \return int Cantidad de estructuras impresas.
 *
 */
int games_printList(sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength);


#endif // GAMES_H_INCLUDED
