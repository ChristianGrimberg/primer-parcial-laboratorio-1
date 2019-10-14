#ifndef CUSTOMERS_H_INCLUDED
#define CUSTOMERS_H_INCLUDED

#include "games.h"

#define CUSTOMER_NAME_MAX 51 /**< Longitud maxima de la descripcion de un Cliente. >*/
#define PHONE_MAX 21 /**< Se define la cantidad maxima de caracteres telefonicos. >*/
#define CUSTOMER_ADDRESS_MAX 51 /**< Longitud maxima de la direccion de un Cliente. >*/
#define ID_INIT_CUSTOMER 300 /**< Numeracion inicial de un Cliente. >*/
#define CUSTOMERS_MAX 100 /**< Cantidad maxima de Clientes en un arreglo. >*/

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

/** \brief Funcion que determina si la estructura es un Cliente.
 *
 * \param customer sCustomer Estructura a evaluar.
 * \return int
 *          [0] Si no es un Cliente.
 *          [1] Si es un Cliente.
 *
 */
int customers_isCustomer(sCustomer customer);

/** \brief Funcion que compara dos estructuras de Juegos.
 *
 * \param customer1 sCustomer Primer estructura a comparar.
 * \param customer2 sCustomer Segunda estructura a comparar.
 * \return int
 *          [-1] Si el ID de la estructura 1 es mayor al ID de la  estructura 2.
 *          [1] Si el ID de la estructura 1 es menor al ID de la estructura 2.
 *          [0] Si ambos ID son iguales.
 *
 */
int customers_compare(sCustomer customer1, sCustomer customer2);

/** \brief Intercambio de estructuras.
 *
 * \param customer1 sCustomer* Direccion de memoria de la estructura 1.
 * \param customer2 sCustomer* Direccion de memoria de la estructura 2.
 * \return int
 *          [ERROR] Si hubo un error en el intercambio.
 *          [OK] Si el intercambio fue exitoso.
 *
 */
int customers_swap(sCustomer* customer1, sCustomer* customer2);

/** \brief Inicializacion del arreglo de estructuras.
 *
 * \param customersList[] sCustomer Arreglo de estrucutras.
 * \param customersLength int Longitud del arreglo.
 * \return int
 *          [ERROR] Si hubo un error al inicializar.
 *          [OK] Si la inicializacion se realizo correctamente.
 *
 */
int customers_init(sCustomer customersList[], int customersLength);

/** \brief Harcodeo de estructuras de ejemplo.
 *
 * \param customersList[] sCustomer Arreglo de estrucutras.
 * \param customersLength int Longitud del arreglo.
 * \return void No retorna valores.
 *
 */
void customers_hardcode(sCustomer customersList[], int customersLength);

/** \brief Obtiene el primer indice vacio del arreglo
 *
 * \param customersList[] sCustomer Arreglo de estrucutras.
 * \param customersLength int Longitud del arreglo.
 * \return int
 *          Indice de la primera posicion vacia del arreglo.
 *          [ERROR] Si no hay ninguna posicion vacia.
 *
 */
int customers_getEmptyIndex(sCustomer customersList[], int customersLength);

/** \brief Obtiene el indice de la estructura buscada por el ID.
 *
 * \param customersList[] sCustomer Arreglo de estrucutras.
 * \param customersLength int Longitud del arreglo.
 * \param id int ID a buscar.
 * \return int
 *          Indice del ID buscado.
 *          [ERROR] Si el ID buscado no existe o esta inactivo.
 *
 */
int customers_getIndexById(sCustomer customersList[], int customersLength, int id);

/** \brief Seleccion de una estructura consultando por pantalla al usuario.
 *
 * \param message[] char Mensaje de solicitud al usuario.
 * \param eMessage[] char Mensaje ante error del valor ingresado por el usuario.
 * \param customersList[] sCustomer Arreglo de estrucutras.
 * \param customersLength int Longitud del arreglo.
 * \return int
 *          ID de la estructura elegida por el usuario.
 *          [ERROR] Si la estructura elegida no se encuentra.
 *
 */
int customers_userSelection(char message[], char eMessage[], sCustomer customersList[], int customersLength);
int customers_add(sCustomer customersList[], int customersLength);
int customers_modify(sCustomer customersList[], int customersLength);
int customers_delete(sCustomer customersList[], int customersLength);

/** \brief Ordenamiento de un arreglo de estructuras por dos opciones.
 *
 * \param customersList[] sCustomer Arreglo de estrucutras.
 * \param customersLength int Longitud del arreglo.
 * \param order int
 *          [ASC] Para orden ascendente.
 *          [DESC] Para orden descendente.
 * \return int
 *          [ERROR] Si no se realizo ningun ordenamiento.
 *          [OK] Si al menos hizo un minimo ordenamiento.
 *
 */
int customers_sort(sCustomer customersList[], int customersLength, int order);

/** \brief Impresion con formato tabla de una estructura.
 *
 * \param customer sCustomer Estructura a imprimir.
 * \return void No retorna valores.
 *
 */
void customers_print(sCustomer customer);

/** \brief Impresion con formato tabla de un arreglo de estructuras.
 *
 * \param customersList[] sCustomer Arreglo de estrucutras.
 * \param customersLength int Longitud del arreglo.
 * \return int Cantidad de estructuras impresas.
 *
 */
int customers_printList(sCustomer customersList[], int customersLength);

#endif // CUSTOMERS_H_INCLUDED
