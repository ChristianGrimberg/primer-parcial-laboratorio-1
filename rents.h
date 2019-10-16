#ifndef RENTS_H_INCLUDED
#define RENTS_H_INCLUDED

#include "customers.h"

#define ID_INIT_RENTAL 300 /**< Numeracion inicial de un Alquiler. >*/
#define RENTS_MAX 999 /**< Cantidad maxima de Alquileres en un arreglo. >*/

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

/** \brief Funcion que compara dos estructuras de Juegos.
 *
 * \param rental1 sRental Primer estructura a comparar.
 * \param rental2 SRental Segunda estructura a comparar.
 * \return int
 *          [-1] Si el ID de la estructura 1 es mayor al ID de la  estructura 2.
 *          [1] Si el ID de la estructura 1 es menor al ID de la estructura 2.
 *          [0] Si ambos ID son iguales.
 *
 */
int rents_compare(sRental rental1, sRental rental2);

/** \brief Intercambio de estructuras.
 *
 * \param rental1 sRental* Direccion de memoria de la estructura 1.
 * \param rental2 SRental* Direccion de memoria de la estructura 2.
 * \return int
 *          [ERROR] Si hubo un error en el intercambio.
 *          [OK] Si el intercambio fue exitoso.
 *
 */
int rents_swap(sRental* rental1, sRental* rental2);

/** \brief Inicializacion del arreglo de estructuras.
 *
 * \param rentsList[] sRental Arreglo de estructuras.
 * \param rentsLength int Longitud del arreglo.
 * \return int
 *          [ERROR] Si hubo un error al inicializar.
 *          [OK] Si la inicializacion se realizo correctamente.
 *
 */
int rents_init(sRental rentsList[], int rentsLength);

/** \brief Harcodeo de estructuras de ejemplo.
 *
 * \param rentsList[] sRental Arreglo de estructuras.
 * \param rentsLength int Longitud del arreglo.
 * \return void No retorna valores.
 *
 */
void rents_hardcode(sRental rentsList[], int rentsLength);

/** \brief Obtiene el primer indice vacio del arreglo
 *
 * \param rentsList[] sRental Arreglo de estructuras.
 * \param rentsLength int Longitud del arreglo.
 * \return int
 *          Indice de la primera posicion vacia del arreglo.
 *          [ERROR] Si no hay ninguna posicion vacia.
 *
 */
int rents_getEmptyIndex(sRental rentsList[], int rentsLength);

/** \brief Obtiene el indice de la estructura buscada por el ID.
 *
 * \param rentsList[] sRental Arreglo de estructuras.
 * \param rentsLength int Longitud del arreglo.
 * \param id int ID a buscar.
 * \return int
 *          Indice del ID buscado.
 *          [ERROR] Si el ID buscado no existe o esta inactivo.
 *
 */
int rents_getIndexById(sRental rentsList[], int rentsLength, int id);

/** \brief Seleccion de una estructura consultando por pantalla al usuario.
 *
 * \param message[] char Mensaje de solicitud al usuario.
 * \param eMessage[] char Mensaje ante error del valor ingresado por el usuario.
 * \param rentsList[] sRental Arreglo de estructuras de Alquileres.
 * \param rentsLength int Longitud del arreglo de Alquileres.
 * \param customersList[] sCustomer Arreglo de estructuras de Clientes.
 * \param customersLength int Longitud del arreglo de Clientes.
 * \param gamesList[] sGame Arreglo de estructuras de Juegos.
 * \param gamesLength int Longitud del arreglo de Juegos.
 * \param categoriesList[] sCategory Arreglo de estructuras de Categorias.
 * \param categoriesLength int Longitud del arreglo de Categorias.
 * \return int
 *          ID de la estructura elegida por el usuario.
 *          [ERROR] Si la estructura elegida no se encuentra.
 *
 */
int rents_userSelection(char message[], char eMessage[], sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength);

/** \brief Agregar una nueva estructura en una posicion vacia del arreglo.
 *
 * \param rentsList[] sRental Arreglo de estructuras de Alquileres.
 * \param rentsLength int Longitud del arreglo de Alquileres.
 * \param customersList[] sCustomer Arreglo de estructuras de Clientes.
 * \param customersLength int Longitud del arreglo de Clientes.
 * \param gamesList[] sGame Arreglo de estructuras de Juegos.
 * \param gamesLength int Longitud del arreglo de Juegos.
 * \param categoriesList[] sCategory Arreglo de estructuras de Categorias.
 * \param categoriesLength int Longitud del arreglo de Categorias.
 * \return int
 *          [ERROR] Si hubo un error al cargar la estructura.
 *          [OK] Si pudo cargarse correctamente la estructura.
 *
 */
int rents_add(sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength);

/** \brief Modificacion de una estructura.
 *
 * \param rentsList[] sRental Arreglo de estructuras de Alquileres.
 * \param rentsLength int Longitud del arreglo de Alquileres.
 * \param customersList[] sCustomer Arreglo de estructuras de Clientes.
 * \param customersLength int Longitud del arreglo de Clientes.
 * \param gamesList[] sGame Arreglo de estructuras de Juegos.
 * \param gamesLength int Longitud del arreglo de Juegos.
 * \param categoriesList[] sCategory Arreglo de estructuras de Categorias.
 * \param categoriesLength int Longitud del arreglo de Categorias.
 * \return int
 *          [ERROR] Si hubo un error al modificar la estructura.
 *          [OK] Si pudo modificarse correctamente la estructura.
 *
 */
int rents_modify(sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength);

/** \brief Inactivacion de una estructura dentro de un arreglo.
 *
 * \param rentsList[] sRental Arreglo de estructuras de Alquileres.
 * \param rentsLength int Longitud del arreglo de Alquileres.
 * \param customersList[] sCustomer Arreglo de estructuras de Clientes.
 * \param customersLength int Longitud del arreglo de Clientes.
 * \param gamesList[] sGame Arreglo de estructuras de Juegos.
 * \param gamesLength int Longitud del arreglo de Juegos.
 * \param categoriesList[] sCategory Arreglo de estructuras de Categorias.
 * \param categoriesLength int Longitud del arreglo de Categorias.
 * \return int
 *          [ERROR] Si hubo un error al inactivar la estructura.
 *          [OK] Si pudo inactivarse correctamente la estructura.
 *
 */
int rents_delete(sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength);

/** \brief Ordenamiento de un arreglo de estructuras.
 *
 * \param rentsList[] sRental Arreglo de estructuras de Alquileres.
 * \param rentsLength int Longitud del arreglo de Alquileres.
 * \param customersList[] sCustomer Arreglo de estructuras de Clientes.
 * \param customersLength int Longitud del arreglo de Clientes.
 * \param gamesList[] sGame Arreglo de estructuras de Juegos.
 * \param gamesLength int Longitud del arreglo de Juegos.
 * \param categoriesList[] sCategory Arreglo de estructuras de Categorias.
 * \param categoriesLength int Longitud del arreglo de Categorias.
 * \param order int
 *          [ASC] Para orden ascendente.
 *          [DESC] Para orden descendente.
 * \return int
 *          [ORDERED] Si no se realizo ningun ordenamiento.
 *          [DISORDERED] Si al menos hizo un minimo ordenamiento.
 *
 */
int rents_sort(sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength, int order);

/** \brief Impresion con formato tabla de una estructura.
 *
 * \param rental sRental Estructura de Alquiler.
 * \param customersList[] sCustomer Arreglo de estructuras de Clientes.
 * \param customersLength int Longitud del arreglo de Clientes.
 * \param gamesList[] sGame Arreglo de estructuras de Juegos.
 * \param gamesLength int Longitud del arreglo de Juegos.
 * \param categoriesList[] sCategory Arreglo de estructuras de Categorias.
 * \param categoriesLength int Longitud del arreglo de Categorias.
 * \return void No retorna valores.
 *
 */
void rents_print(sRental rental, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength);

/** \brief Impresion con formato tabla de un arreglo de estructuras.
 *
 * \param rentsList[] sRental Arreglo de estructuras de Alquileres.
 * \param rentsLength int Longitud del arreglo de Alquileres.
 * \param customersList[] sCustomer Arreglo de estructuras de Clientes.
 * \param customersLength int Longitud del arreglo de Clientes.
 * \param gamesList[] sGame Arreglo de estructuras de Juegos.
 * \param gamesLength int Longitud del arreglo de Juegos.
 * \param categoriesList[] sCategory Arreglo de estructuras de Categorias.
 * \param categoriesLength int Longitud del arreglo de Categorias.
 * \return int Cantidad de estructuras impresas.
 *
 */
int rents_printList(sRental rentsList[], int rentsLength, sCustomer customersList[], int customersLength, sGame gamesList[], int gamesLength, sCategory categoriesList[], int categoriesLength);

#endif // RENTS_H_INCLUDED
