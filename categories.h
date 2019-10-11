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
