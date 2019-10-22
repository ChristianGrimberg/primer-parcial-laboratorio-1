#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "rents.h"

#define MENU_MAIN_MAX 7 /**< Opcion maxima del menu principal. >*/
#define MENU_CATEGORY_MAX 6 /**< Opcion maxima del menu de Categorias. >*/
#define MENU_GAME_MAX 6 /**< Opcion maxima del menu de Juegos. >*/
#define MENU_CUSTOMERS_MAX 6 /**< Opcion maxima del menu de Juegos. >*/
#define MENU_RENTS_MAX 6 /**< Opcion maxima del menu de Alquileres. >*/
#define MENU_REPORTS_MAX 6 /**< Opcion maxima del menu de Reportes. >*/
#define MENU_COMPLEMENTARY_MAX 11 /**< Opcion maxima del menu de Informes Complementarios. >*/

/** \brief Funcion que imprime el menu principal del programa.
 *
 * \param option int* Opcion elegida del menu.
 * \return int
 *      [-1] Si hubo un error.
 *      Retorna la opcion elegida en el menu.
 *
 */
int menu_main(int* option);

/** \brief Funcion que imprime el menu ABM de Categorias.
 *
 * \param option int* Opcion elegida del menu.
 * \return int
 *      [-1] Si hubo un error.
 *      Retorna la opcion elegida en el menu.
 *
 */
int menu_categories(int* option);

/** \brief Funcion que imprime el menu ABM de Juegos.
 *
 * \param option int* Opcion elegida del menu.
 * \return int
 *      [-1] Si hubo un error.
 *      Retorna la opcion elegida en el menu.
 *
 */
int menu_games(int* option);

/** \brief Funcion que imprime el menu ABM de Clientes.
 *
 * \param option int* Opcion elegida del menu.
 * \return int
 *      [-1] Si hubo un error.
 *      Retorna la opcion elegida en el menu.
 *
 */
int menu_customers(int* option);

/** \brief Funcion que imprime el menu ABM de Alquileres.
 *
 * \param option int* Opcion elegida del menu.
 * \return int
 *      [-1] Si hubo un error.
 *      Retorna la opcion elegida en el menu.
 *
 */
int menu_rents(int* option);

/** \brief Funcion que imprime el menu Reportes.
 *
 * \param option int* Opcion elegida del menu.
 * \return int
 *      [-1] Si hubo un error.
 *      Retorna la opcion elegida en el menu.
 *
 */
int menu_reports(int* option);

/** \brief Funcion que imprime el menu de Informes Complementarios.
 *
 * \param option int* Opcion elegida del menu.
 * \return int
 *      [-1] Si hubo un error.
 *      Retorna la opcion elegida en el menu.
 *
 */
int menu_complementary(int* option);

#endif // MENU_H_INCLUDED
