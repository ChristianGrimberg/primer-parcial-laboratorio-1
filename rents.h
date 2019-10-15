#ifndef RENTS_H_INCLUDED
#define RENTS_H_INCLUDED

#include "customers.h"

#define ID_INIT_RENTAL 300 /**< Numeracion inicial de un Alquiler. >*/
#define RENTS_MAX 100 /**< Cantidad maxima de Alquileres en un arreglo. >*/

/*! \struct sRental
 * \brief Tipo de dato de un Alquiler.
 *
 * \field id int Campo ID de la estructura.
 * \field gameId int Clave foranea del ID de Juegos.
 * \field CustomerId int Clave foranea del ID de Clientes.
 * \field date sDate Fecha de la estructura.
 * \field isEmpty int Indicador de posicion llena o vacia.
 *
 */
typedef struct
{
    int id; /**< Campo ID de la estructura. >*/
    int gameId; /**< Clave foranea del ID de Juegos. >*/
    int customerId; /**< Clave foranea del ID de Clientes. >*/
    sDate date; /**< Fecha de la estructura. >*/
    int isEmpty; /**< Indicador de posicion llena o vacia. >*/
} sRental;

/** \brief Funcion que determina si la estructura es un Alquiler.
 *
 * \param rental sRental Estructura de Alquiler a evaluar.
 * \param customer sCustomer Estructura de Cliente a evaluar.
 * \param game sGame Estructura de Juego a evaluar.
 * \param category sCategory Estructura de Categoria a evaluar.
 * \return int
 *          [0] Si no es un Alquiler.
 *          [1] Si es un Alquiler.
 *
 */
int rents_isRental(sRental rental, sCustomer customer, sGame game, sCategory category);
int rents_compare(sRental rental1, sRental rental2);
int rents_swap(sRental* rental1, sRental* rental2);
int rents_init(sRental rentsList[], int rentsLength);
void rents_hardcode(sRental rentsList[], int rentsLength);
int rents_getEmptyIndex(sRental rentsList[], int rentsLength);
int rents_getIndexById(sRental rentsList[], int rentsLength, int id);
int rents_userSelection(char message[], char eMessage[], sRental rentsList[], int rentsLength);
int rents_add(sRental rentsList[], int rentsLength);
int rents_modify(sRental rentsList[], int rentsLength);
int rents_delete(sRental rentsList[], int rentsLength);
int rents_sort(sRental rentsList[], int rentsLength, int order);

/** \brief Impresion con formato tabla de una estructura.
 *
 * \param rental sRental Estructura a imprimir.
 * \return void No retorna valores.
 *
 */
void rents_print(sRental rental);
int rents_printList(sRental rentsList[], int rentsLength);

#endif // RENTS_H_INCLUDED
