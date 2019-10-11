#include "customers.h"

/** \brief Funcion que determina si la estructura es un Cliente.
 *
 * \param category sCategory Estructura a evaluar.
 * \return int
 *          [0] Si no es un Cliente.
 *          [1] Si es un Cliente.
 *
 */
static int isCustomer(sCustomer customer);

/** \brief Funcion que devuelve una estructura vacia.
 *
 * \param void No requiere parametros.
 * \return sCategory Devuelve una estructura con valores "nulos".
 *
 */
static sCustomer nullCustomer(void);

/** \brief Obtiene un nuevo ID autoincremental.
 *
 * \param void No requiere parametros.
 * \return int Retorna un nuevo ID incremental.
 *
 */
static int getNewId(void);
static int printCustomer(sCustomer customer);

static int getNewId(void)
{
    static int customerId = ID_INIT_GAME;
    customerId++;
    return customerId;
}
