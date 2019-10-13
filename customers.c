#include "customers.h"

/** \brief Funcion que devuelve una estructura vacia.
 *
 * \param void No requiere parametros.
 * \return sCustromer Devuelve una estructura con valores "nulos".
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

/** \brief Imprime en pantalla los valores de la estructura.
 *
 * \param customer sCustomer Estructura a imprimir.
 * \return int
 *          [0] Si la estructura esta vacia.
 *          [1] Si la estructura esta llena y pudo imprimirse.
 *
 */
static int printCustomer(sCustomer customer);

int customers_isCustomer(sCustomer customer)
{
    int returnValue = 0;

    if(customer.id != EMPTY_ID
       && customer.name != NULL
       && customer.lastName != NULL
       && customer.phone != NULL
       && customer.isEmpty == FALSE)
    {
        returnValue = 1;
    }

    return returnValue;
}

int customers_compare(sCustomer customer1, sCustomer customer2)
{
    int compare = -2;

    if(customers_isCustomer(customer1)
       && customers_isCustomer(customer2))
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

int customers_swap(sCustomer* customer1, sCustomer* customer2)
{
    int returnValue = ERROR;
    sCustomer aux1;
    sCustomer aux2;

    aux1 = *customer1;
    aux2 = *customer2;
    *customer1 = *customer2;
    *customer2 = aux1;

    if(customers_compare(*customer1, aux2) == 0
       && customers_compare(*customer2, aux1) == 0)
    {
        returnValue = OK;
    }

    return returnValue;
}

int customers_init(sCustomer customersList[], int customersLength)
{
    int returnValue = ERROR;
    int i;

    if(customersList != NULL
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX)
    {
        for(i = 0 ; i < customersLength; i++)
        {
            customersList[i] = nullCustomer();
        }

        if(i == customersLength)
        {
            returnValue = OK;
        }
    }

    return returnValue;
}

void customers_hardcode(sCustomer customersList[], int customersLength)
{
    int indexHardcodeMax = 7;

    sCustomer customersAux[] = {
        {getNewId(), "marcelo", "tinelli", 'm', "+54 11 2000-3000", "carlos calvo 2820", FALSE},
        {getNewId(), "susana", "gimenez", 'f', "+54 11 1000-9000", "cordoba 1560", FALSE},
        {getNewId(), "ricardo", "darin", 'm', "+54 11 5000-7000", "corrientes 960", FALSE},
        {getNewId(), "moria", "casan", 'f', "+54 11 3000-1000", "tilcara 150", FALSE},
        {getNewId(), "marley", "wieber", 'm', "+54 11 8000-5000", "junin 58220", FALSE},
        {getNewId(), "mirtha", "legrand", 'f', "+54 11 4000-2000", "mitre 1200", FALSE},
        {getNewId(), "veronica", "lozano", 'f', "+54 11 6000-4000", "santa fe 2820", FALSE},
        {getNewId(), "sebastian", "yatra", 'm', "+54 11 7000-6000", "san juan 70",  FALSE}
    };

    if(customersList != NULL
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX)
    {
        for (int i = 0; i < customersLength; i++)
        {
            if(i <= indexHardcodeMax)
            {
                customersList[i] = customersAux[i];
            }
            else
            {
                customersList[i] = nullCustomer();
            }
        }
    }
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

static int getNewId(void)
{
    static int customerId = ID_INIT_CUSTOMER;
    customerId++;
    return customerId;
}
