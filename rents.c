#include "rents.h"

/** \brief Funcion que determina si la estructura es un Alquiler.
 *
 * \param category sCategory Estructura a evaluar.
 * \return int
 *          [0] Si no es un Alquiler.
 *          [1] Si es un Alquiler.
 *
 */
static int isCustomer(sRental rental);

/** \brief Funcion que devuelve una estructura vacia.
 *
 * \param void No requiere parametros.
 * \return sCategory Devuelve una estructura con valores "nulos".
 *
 */
static sCustomer nullRental(void);

/** \brief Obtiene un nuevo ID autoincremental.
 *
 * \param void No requiere parametros.
 * \return int Retorna un nuevo ID incremental.
 *
 */
static int getNewId(void);
static int printRental(sRental rental);

static int getNewId(void)
{
    static int rentalId = ID_INIT_RENTAL;
    rentalId++;
    return rentalId;
}
