#include "rents.h"

/** \brief Funcion que devuelve una estructura vacia.
 *
 * \param void No requiere parametros.
 * \return sRental Devuelve una estructura con valores "nulos".
 *
 */
static sRental nullRental(void);

/** \brief Obtiene un nuevo ID autoincremental.
 *
 * \param void No requiere parametros.
 * \return int Retorna un nuevo ID incremental.
 *
 */
static int getNewId(void);

/** \brief Imprime en pantalla los valores de la estructura.
 *
 * \param rental sRental Estructura a imprimir.
 * \return int
 *          [0] Si la estructura esta vacia.
 *          [1] Si la estructura esta llena y pudo imprimirse.
 *
 */
static int printRental(sRental rental);

int rents_isRental(sRental rental, sCustomer customer, sGame game, sCategory category)
{
    int returnValue = 0;

    if(rental.id != EMPTY_ID
       && customers_isCustomer(customer) && rental.customerId == customer.id
       && games_isGame(game, category) && rental.gameId == game.id
       && categories_isCategory(category) && game.categoryId == category.id
       && rental.isEmpty == FALSE)
    {
        returnValue = 1;
    }

    return returnValue;
}

int rents_compare(sRental rental1, sRental rental2)
{
    int compare = -2;

    if(rental1.isEmpty == FALSE
       && rental2.isEmpty == FALSE)
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

static int getNewId(void)
{
    static int rentalId = ID_INIT_RENTAL;
    rentalId++;
    return rentalId;
}
