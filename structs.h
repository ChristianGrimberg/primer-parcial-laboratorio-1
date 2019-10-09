#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1 /**< Valor booleano de verdadero. >*/
#define FALSE 0 /**< Valor booleano de falso. >*/
#define ERROR -1 /**< Opcion de retorno de error. >*/
#define OK 0 /**< Opcion de retorno OK. >*/
#define DAY_MIN 1 /**< Dia minimo de cada mes. >*/
#define DAY_28 28 /**< Dia maximo de febrero de anio no bisiesto. >*/
#define DAY_29 29 /**< Dia maximo de febrero de anio bisiesto. >*/
#define DAY_30 30 /**< Dia maximo de abril, junio, septiembre y noviembre. >*/
#define DAY_31 31 /**< Dia maximo de enero, marzo, mayo, julio, agosto, octubre y diciembre. >*/
#define MONTH_MIN 1 /**< Mes minimo de cada anio. >*/
#define MONTH_MAX 12 /**< Mes maximo de cada anio. >*/
#define YEAR_MIN 1900 /**< Anio minimo definido por el programa. >*/
#define YEAR_MAX 2500 /**< Anio maximo definido por el programa. >*/
#define ASC 1 /**< Metodo para ordenar de forma Ascendente. >*/
#define DESC 0 /**< Metodo para ordenar de forma Descendente. >*/
#define HARDCODE TRUE /**< Indicador de harcoding para propositos de testeo. >*/

/*! \struct sDate
 * \brief Tipo de Dato generico para almacenar una Fecha.
 *
 * \field day int Valor del dia de la Fecha.
 * \field month int Valor del mes de la Fecha.
 * \field year int Valor del anio de la Fecha.
 *
 */
typedef struct
{
    int day; /**< Valor del dia de la fecha. >*/
    int month; /**< Valor del mes de la fecha. >*/
    int year; /**< Valor del anio de la fecha. >*/
} sDate;

/** \brief Funcion que evalua si la fecha ingresada es v�lida
 *
 * \param date sDate Fecha a evaluar.
 * \return int
 *      Si es una fecha retorna [1] si no [0].
 *
 */
int structs_isDate(sDate date);

/** \brief Funcion que compara dos fechas.
 *
 * \param date1 sDate Primer fecha.
 * \param date2 sDate Segunda fecha.
 * \return int
 *      Si son iguales retorna [0].
 *      Si la primer fecha es posterior [1].
 *      Si la segunda fecha es posterior [-1].
 *      Si hubo un error [-2].
 *
 */
int structs_dateCompare(sDate date1, sDate date2);

/** \brief Funcion de intercambio de fechas.
 *
 * \param date1 sDate Primer fecha.
 * \param date2 sDate Segunda fecha.
 * \return int
 *      Si el intercambio se realizo devuelve [0] si no [-1].
 *
 */
int structs_swapDate(sDate* date1, sDate* date2);

#endif // STRUCTS_H_INCLUDED
