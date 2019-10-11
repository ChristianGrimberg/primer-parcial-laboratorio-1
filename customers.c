#include "customers.h"

/** \brief Funcion que devuelve una estructura vacia.
 *
 * \param void No requiere parametros.
 * \return sCustromer Devuelve una estructura con valores "nulos".
 *
 */
static sCustomer nullCustomer(void);

/** \brief Funcion que determina si la estructura es un Cliente.
 *
 * \param customer sCustomer Estructura a evaluar.
 * \return int
 *          [0] Si no es un Cliente.
 *          [1] Si es un Cliente.
 *
 */
static int isCustomer(sCustomer customer);

/** \brief Obtiene un nuevo ID autoincremental.
 *
 * \param void No requiere parametros.
 * \return int Retorna un nuevo ID incremental.
 *
 */
static int getNewId(void);
static int printCustomer(sCustomer customer);

int customers_compare(sCustomer customer1, sCustomer customer2)
{
    int compare = -2;

    if(isCustomer(customer1) && isCustomer(customer2))
    {
        if(customer1.id > customer2.id)
        {
            compare = 1;
        }
        else
        {
            if(customer1.id < customer2.id)
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

static sCustomer nullCustomer()
{
    sCustomer aux;

    aux.id = EMPTY_ID;
    strcpy(aux.name, "NULL");
    strcpy(aux.lastName, "NULL");
    strcpy(aux.address, "NULL");
    aux.sex = ' ';
    strcpy(aux.phone, "NULL");
    aux.isEmpty = TRUE;

    return aux;
}

static int isCustomer(sCustomer customer)
{
    int returnValue = 0;

    if(customer.id != EMPTY_ID && customer.name != NULL && customer.lastName != NULL
       && customer.phone != NULL && customer.isEmpty == FALSE)
    {
        returnValue = 1;
    }

    return returnValue;
}

static int getNewId(void)
{
    static int customerId = ID_INIT_CUSTOMER;
    customerId++;
    return customerId;
}
