#ifndef CATEGORIES_H_INCLUDED
#define CATEGORIES_H_INCLUDED

#include "inputs.h"

#define CATEGORY_NAME_MAX 51 /**< Longitud maxima de la descripcion de una Categoria. >*/
#define ID_INIT_CATEGORY 100 /**< Numeracion inicial de una Categoria. >*/
#define CATEGORIES_MAX 25 /**< Cantidad maxima de Categorias en un arreglo. >*/

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

/** \brief Funcion que determina si la estructura es una Categoria.
 *
 * \param category sCategory Estructura a evaluar.
 * \return int
 *          [0] Si no es una Categoria.
 *          [1] Si es una Categoria.
 *
 */
int categories_isCategory(sCategory category);

/** \brief Funcion que compara dos estructuras de Categorias.
 *
 * \param category1 sCategory Primer estructura a comparar.
 * \param category2 sCategory Segunda estructura a comparar.
 * \return int
 *          [-1] Si el ID de la estructura 1 es mayor al ID de la  estructura 2.
 *          [1] Si el ID de la estructura 1 es menor al ID de la estructura 2.
 *          [0] Si ambos ID son iguales.
 *
 */
int categories_compare(sCategory category1, sCategory category2);

/** \brief Intercambio de estructuras.
 *
 * \param category1 sCategory* Direccion de memoria de la estructura 1.
 * \param category2 sCategory* Direccion de memoria de la estructura 2.
 * \return int
 *          [-1] Si hubo un error en el intercambio.
 *          [0] Si el intercambio fue exitoso.
 *
 */
int categories_swap(sCategory* category1, sCategory* category2);

/** \brief Inicializacion del arreglo de estructuras.
 *
 * \param categoriesList[] sCategory Arreglo de estructuras.
 * \param categoriesLength int Longitud del arreglo.
 * \return int
 *          [-1] Si hubo un error al inicializar.
 *          [0] Si la inicializacion se realizo correctamente.
 *
 */
int categories_init(sCategory categoriesList[], int categoriesLength);

/** \brief Harcodeo de estructuras de ejemplo.
 *
 * \param categoriesList[] sCategory Arreglo de estructuras.
 * \param categoriesLength int Longitud del arreglo.
 * \return void No retorna valores.
 *
 */
void categories_hardcode(sCategory categoriesList[], int categoriesLength);

/** \brief Obtiene el primer indice vacio del arreglo
 *
 * \param categoriesList[] sCategory Arreglo de estructuras.
 * \param categoriesLength int Longitud del arreglo.
 * \return int
 *          Indice de la primera posicion vacia del arreglo.
 *          [-1] Si no hay ninguna posicion vacia.
 *
 */
int categories_getEmptyIndex(sCategory categoriesList[], int categoriesLength);

/** \brief Obtiene el indice de la estructura buscada por el ID.
 *
 * \param categoriesList[] sCategory Arreglo de estructuras.
 * \param categoriesLength int Longitud del arreglo.
 * \param id int ID a buscar.
 * \return int
 *          Indice del ID buscado.
 *          [-1] Si el ID buscado no existe o esta inactivo.
 *
 */
int categories_getIndexById(sCategory categoriesList[], int categoriesLength, int id);

/** \brief Obtiene el ID de la estructura buscada por la Descripcion.
 *
 * \param categoriesList[] sCategory Arreglo de estructuras.
 * \param categoriesLength int Longitud del arreglo.
 * \param description[] char Descripcion a buscar.
 * \return int
 *          ID buscado.
 *          [-1] Si la descripcion buscada no existe o esta inactiva.
 *
 */
int categories_getIdByDescription(sCategory categoriesList[], int categoriesLength, char description[]);

/** \brief Seleccion de una estructura consultando por pantalla al usuario.
 *
 * \param message[] char Mensaje de solicitud al usuario.
 * \param eMessage[] char Mensaje ante error del valor ingresado por el usuario.
 * \param categoriesList[] sCategory Arreglo de estructuras.
 * \param categoriesLength int Longitud del arreglo.
 * \return int
 *          ID de la estructura elegida por el usuario.
 *          [-1] Si la estructura elegida no se encuentra.
 *
 */
int categories_userSelection(char message[], char eMessage[], sCategory categoriesList[], int categoriesLength);

/** \brief Agregar una nueva estructura en una posicion vacia del arreglo.
 *
 * \param categoriesList[] sCategory Arreglo de estructuras.
 * \param categoriesLength int Longitud del arreglo.
 * \return int
 *          [-1] Si hubo un error al cargar la estructura.
 *          [0] Si pudo cargarse correctamente la estructura.
 *
 */
int categories_add(sCategory categoriesList[], int categoriesLength);

/** \brief Modificacion de la descripcion de la estructura.
 *
 * \param categoriesList[] sCategory Arreglo de estructuras.
 * \param categoriesLength int Longitud del arreglo.
 * \return int
 *          [-1] Si hubo un error al modificar la estructura.
 *          [0] Si pudo modificarse correctamente la estructura.
 *
 */
int categories_modify(sCategory categoriesList[], int categoriesLength);

/** \brief Inactivacion de una estructura dentro de un arreglo.
 *
 * \param categoriesList[] sCategory Arreglo de estructuras.
 * \param categoriesLength int Longitud del arreglo.
 * \return int
 *          [-1] Si hubo un error al inactivar la estructura.
 *          [0] Si pudo inactivarse correctamente la estructura.
 *
 */
int categories_delete(sCategory categoriesList[], int categoriesLength);

/** \brief Ordenamiento de un arreglo de estructuras.
 *
 * \param categoriesList[] sCategory Arreglo de estructuras.
 * \param categoriesLength int Longitud del arreglo.
 * \param order int
 *          [ASC] Para orden ascendente.
 *          [DESC] Para orden descendente.
 * \return int
 *          [-1] Si hubo un error para realizar el ordenamiento.
 *          [0] Si pudo procesar el algoritmo de ordenamiento.
 *
 */
int categories_sort(sCategory categoriesList[], int categoriesLength, int order);

/** \brief Impresion con formato tabla de una estructura.
 *
 * \param category sCategory Estructura a imprimir.
 * \return void No retorna valores.
 *
 */
void categories_print(sCategory category);

/** \brief Impresion con formato tabla de un arreglo de estructuras.
 *
 * \param categoriesList[] sCategory Arreglo de estructuras.
 * \param categoriesLength int Longitud del arreglo.
 * \return int Cantidad de estructuras impresas.
 *
 */
int categories_printList(sCategory categoriesList[], int categoriesLength);

#endif // CATEGORIES_H_INCLUDED
