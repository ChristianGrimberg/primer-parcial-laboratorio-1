#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "rents.h"

#define MENU_MAIN_MAX 6 /**< Opcion maxima del menu principal. >*/
#define MENU_CATEGORY_MAX 5 /**< Opcion maxima del menu de Categorias. >*/
#define MENU_GAME_MAX 5 /**< Opcion maxima del menu de Juegos. >*/
#define MENU_CUSTOMERS_MAX 5 /**< Opcion maxima del menu de Juegos. >*/
#define MENU_RENTS_MAX 5 /**< Opcion maxima del menu de Alquileres. >*/

/** \brief Funcion que imprime el menu principal del programa.
 *
 * \param option int* Opcion elegida del menu.
 * \return int
 *      [ERROR] Si hubo un error.
 *      Retorna la opcion elegida en el menu.
 *
 */
int menu_main(int* option);

/** \brief Funcion que imprime el menu ABM de Categorias.
 *
 * \param option int* Opcion elegida del menu.
 * \return int
 *      [ERROR] Si hubo un error.
 *      Retorna la opcion elegida en el menu.
 *
 */
int menu_categories(int* option);

/** \brief Funcion que imprime el menu ABM de Juegos.
 *
 * \param option int* Opcion elegida del menu.
 * \return int
 *      [ERROR] Si hubo un error.
 *      Retorna la opcion elegida en el menu.
 *
 */
int menu_games(int* option);

/** \brief Funcion que imprime el menu ABM de Clientes.
 *
 * \param option int* Opcion elegida del menu.
 * \return int
 *      [ERROR] Si hubo un error.
 *      Retorna la opcion elegida en el menu.
 *
 */
int menu_customers(int* option);

/** \brief Funcion que imprime el menu ABM de Alquileres.
 *
 * \param option int* Opcion elegida del menu.
 * \return int
 *      [ERROR] Si hubo un error.
 *      Retorna la opcion elegida en el menu.
 *
 */
int menu_rents(int* option);

#endif // MENU_H_INCLUDED
