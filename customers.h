#ifndef CUSTOMERS_H_INCLUDED
#define CUSTOMERS_H_INCLUDED

#include "games.h"

#define CUSTOMER_NAME_MAX 51 /**< Longitud maxima de la descripcion de un Cliente. >*/
#define PHONE_MAX 21 /**< Se define la cantidad maxima de caracteres telefonicos. >*/
#define CUSTOMER_ADDRESS_MAX 51 /**< Longitud maxima de la direccion de un Cliente. >*/
#define ID_INIT_CUSTOMER 300 /**< Numeracion inicial de un Cliente. >*/

/*! \struct sCustomer
 * \brief Tipo de dato de un Cliente.
 *
 * \field id int Campo ID de la estructura.
 * \field name[] char Nombre de la estructura.
 * \field LastName[] char Apellido de la estructura.
 * \field sex char Genero de la estructura.
 * \field phone[] char Telefono de la estructura.
 * \field address[] char Direccion de la estructura.
 * \field isEmpty int Indicador de posicion llena o vacia..
 *
 */
typedef struct
{
    int id; /**< Campo ID de la estructura. >*/
    char name[CUSTOMER_NAME_MAX]; /**< Nombre de la estructura. >*/
    char lastName[CUSTOMER_NAME_MAX]; /**< Apellido de la estructura. >*/
    char sex; /**< Genero de la estructura. >*/
    char phone[PHONE_MAX]; /**< Telefono de la estructura. >*/
    char address[CUSTOMER_ADDRESS_MAX]; /**< Direccion de la estructura. >*/
    int isEmpty; /**< Indicador de posicion llena o vacia. >*/
} sCustomer;

int customers_compare(sCustomer customer1, sCustomer customer2);
int customers_swap(sCustomer* customer1, sCustomer* customer2);
int customers_init(sCustomer customersList[], int customersLength);
void customers_hardcode(sCustomer customersList[], int customersLength);
int customers_getIndex(sCustomer customersList[], int customersLength);
int customers_getId(sCustomer customersList[], int customersLength);
int customers_userSelection(sCustomer customersList[], int customersLength);
int customers_add(sCustomer customersList[], int customersLength);
int customers_modify(sCustomer customersList[], int customersLength);
int customers_delete(sCustomer customersList[], int customersLength);
int customers_sort(sCustomer customersList[], int customersLength, int order);
int customers_print(sCustomer customer);
int customers_printList(sCustomer customersList[], int customersLength);

#endif // CUSTOMERS_H_INCLUDED
