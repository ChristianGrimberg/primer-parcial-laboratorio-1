#ifndef RENTS_H_INCLUDED
#define RENTS_H_INCLUDED

#include "customers.h"

#define ID_INIT_RENTAL 300 /**< Numeracion inicial de un Alquiler. >*/

/*! \struct sRental
 * \brief Tipo de dato de un Alquiler.
 *
 * \field id int Campo ID de la estructura.
 * \field gameId int Clave foranea del ID de Juegos.
 * \field CustomerId int Clave foranea del ID de Clientes.
 * \field date sDate Fecha de la estructura.
 * \field isEmpty int Indicador de posicion llena o vacia..
 *
 */
typedef struct
{
    int id; /**< Campo ID de la estructura. >*/
    int gameId; /**< Clave foranea del ID de Juegos. >*/
    int CustomerId; /**< Clave foranea del ID de Clientes. >*/
    sDate date; /**< Fecha de la estructura. >*/
    int isEmpty; /**< Indicador de posicion llena o vacia. >*/
} sRental;

int rents_compare(sRental rental1, sRental rental2);
int rents_swap(sRental* rental1, sRental* rental2);
int rents_init(sRental rentsList[], int rentsLength);
void rents_hardcode(sRental rentsList[], int rentsLength);
int rents_getIndex(sRental rentsList[], int rentsLength);
int rents_getId(sRental rentsList[], int rentsLength);
int rents_userSelection(sRental rentsList[], int rentsLength);
int rents_add(sRental rentsList[], int rentsLength);
int rents_modify(sRental rentsList[], int rentsLength);
int rents_delete(sRental rentsList[], int rentsLength);
int rents_sort(sRental rentsList[], int rentsLength, int order);
int rents_print(sRental rental);
int rents_printList(sRental rentsList[], int rentsLength);

#endif // RENTS_H_INCLUDED
