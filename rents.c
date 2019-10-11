#include "rents.h"

/** \brief Funcion que devuelve una estructura vacia.
 *
 * \param void No requiere parametros.
 * \return sRental Devuelve una estructura con valores "nulos".
 *
 */
static sRental nullRental(void);

/** \brief Funcion que determina si la estructura es un Alquiler.
 *
 * \param rental sRental Estructura a evaluar.
 * \return int
 *          [0] Si no es un Alquiler.
 *          [1] Si es un Alquiler.
 *
 */
static int isRental(sRental rental);

/** \brief Obtiene un nuevo ID autoincremental.
 *
 * \param void No requiere parametros.
 * \return int Retorna un nuevo ID incremental.
 *
 */
static int getNewId(void);
static int printRental(sRental rental);

int rents_compare(sRental rental1, sRental rental2)
{
    int compare = -2;

    if(isRental(rental1) && isRental(rental2))
    {
        if(rental1.id > rental2.id)
        {
            compare = 1;
        }
        else
        {
            if(rental1.id < rental2.id)
            {
                compare = -1;
            }
            else
            {
                compare = 0;
            }
        }
    }

    return compare;
}

static sRental nullRental()
{
    sRental aux;

    aux.id = EMPTY_ID;
    aux.gameId = EMPTY_ID;
    aux.customerId = EMPTY_ID;
    aux.date = structs_nullDate();
    aux.isEmpty = TRUE;

    return aux;
}

static int isRental(sRental rental)
{
    int returnValue = 0;

    if(rental.id != EMPTY_ID && rental.gameId != EMPTY_ID
       && rental.customerId != EMPTY_ID && rental.isEmpty == FALSE)
    {
        returnValue = 1;
    }

    return returnValue;
}

static int getNewId(void)
{
    static int rentalId = ID_INIT_RENTAL;
    rentalId++;
    return rentalId;
}
