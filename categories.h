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
int categories_swap(sCategory* category1, sCategory* category2);
int categories_init(sCategory categoriesList[], int categoriesLength);
void categories_hardcode(sCategory categoriesList[], int categoriesLength);
int categories_getIndex(sCategory categoriesList[], int categoriesLength);
int categories_getId(sCategory categoriesList[], int categoriesLength);
int categories_userSelection(sCategory categoriesList[], int categoriesLength);
int categories_add(sCategory categoriesList[], int categoriesLength);
int categories_modify(sCategory categoriesList[], int categoriesLength);
int categories_delete(sCategory categoriesList[], int categoriesLength);
int categories_sort(sCategory categoriesList[], int categoriesLength, int order);
int categories_print(sCategory category);
int categories_printList(sCategory categoriesList[], int categoriesLength);

#endif // CATEGORIES_H_INCLUDED
