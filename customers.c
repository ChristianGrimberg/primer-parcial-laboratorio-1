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

int customers_getEmptyIndex(sCustomer customersList[], int customersLength)
{
    int returnValue = ERROR;
    int i;

    if(customersList != NULL
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX)
    {
        for (i = 0; i < customersLength; i++)
        {
            if(customersList[i].isEmpty == TRUE)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}

int customers_getIndexById(sCustomer customersList[], int customersLength, int id)
{
    int returnValue = ERROR;

    if(customersList != NULL
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX)
    {
        for (int i = 0; i < customersLength; i++)
        {
            if(customersList[i].id == id
               && customersList[i].isEmpty == FALSE)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}

int customers_userSelection(char message[], char eMessage[], sCustomer customersList[], int customersLength)
{
    int returnValue = ERROR;
    int auxId = 0;
    int auxIndex = 0;

    if(message != NULL && eMessage != NULL
       && customersList != NULL
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX)
    {
        if (customers_printList(customersList, customersLength) == 0)
        {
            printf("No hay Clientes activos.\n");
        }
        else
        {
            if(!inputs_getInt(&auxId, message, eMessage, ID_INIT_CUSTOMER+1, ID_INIT_CUSTOMER+CUSTOMERS_MAX))
            {
                auxIndex = customers_getIndexById(customersList, customersLength, auxId);

                if(auxIndex != ERROR)
                {
                    returnValue = auxId;
                }
                else
                {
                    printf("No se encuentra el Cliente ingresado.\n");
                }
            }
        }
    }

    return returnValue;
}

int customers_add(sCustomer customersList[], int customersLength)
{
    int returnValue = ERROR;
    int indexAux;
    char nameAux[CUSTOMER_NAME_MAX];
    char lastNameAux[CUSTOMER_NAME_MAX];
    char sexAux;
    char phoneAux[CUSTOMER_PHONE_MAX];
    char addressAux[CUSTOMER_ADDRESS_MAX];

    if(customersList != NULL
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX)
    {
        indexAux = customers_getEmptyIndex(customersList, customersLength);

        if(indexAux != ERROR
           && !inputs_getString(nameAux, "Ingrese el Nombre: ", ERROR_MESSAGE, 1, CUSTOMER_NAME_MAX)
           && !inputs_getString(lastNameAux, "Ingrese el Apellido: ", ERROR_MESSAGE, 1, CUSTOMER_NAME_MAX))
        {
            do
            {
                if(!inputs_getChar(&sexAux, "Ingrese el Sexo [F] o [M]: ", ERROR_MESSAGE, 'a', 'Z'))
                {
                    sexAux = toupper((char)sexAux);
                }
            }while(sexAux != 'F' && sexAux != 'M');

            if(sexAux == 'F' || sexAux == 'M'
               && !inputs_getPhone(phoneAux, "Ingrese el Telefono [Formato: +54 11 1111-1111]: ",
                                   ERROR_MESSAGE, 1, CUSTOMER_PHONE_MAX)
               && !inputs_getString(addressAux, "Ingrese la Direccion: ",
                                   ERROR_MESSAGE, 1, CUSTOMER_ADDRESS_MAX))
            {
                customersList[indexAux].id = getNewId();
                strcpy(customersList[indexAux].name, nameAux);
                strcpy(customersList[indexAux].lastName, lastNameAux);
                customersList[indexAux].sex = sexAux;
                strcpy(customersList[indexAux].phone, phoneAux);
                strcpy(customersList[indexAux].address, addressAux);
                customersList[indexAux].isEmpty = FALSE;
                returnValue = OK;
            }
        }
    }

    return returnValue;
}

int customers_modify(sCustomer customersList[], int customersLength)
{
    int returnValue = ERROR;
    int idAux;
    int indexAux;
    int option;
    char nameAux[CUSTOMER_NAME_MAX];
    char lastNameAux[CUSTOMER_NAME_MAX];
    char sexAux;
    char phoneAux[CUSTOMER_PHONE_MAX];
    char addressAux[CUSTOMER_ADDRESS_MAX];

    if(customersList != NULL
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX)
    {
        idAux = customers_userSelection("Ingrese el ID del Cliente a modificar: ",
            ERROR_MESSAGE, customersList, customersLength);

        if(idAux != ERROR)
        {
            indexAux = customers_getIndexById(customersList, customersLength, idAux);

            if(indexAux!= ERROR)
            {
                inputs_clearScreen();

                printf("=======================================================\n");
                printf("                MODIFICAR CLIENTE\n");
                printf("=======================================================\n");
                printf("    1 - Modificar el Nombre\n");
                printf("    2 - Modificar el Apellido\n");
                printf("    3 - Modificar el Sexo\n");
                printf("    4 - Modificar el Telefono\n");
                printf("    5 - Modificar la Direccion\n");
                printf("    6 - Volver al menu principal\n");
                printf("=======================================================\n");

                if(!inputs_getInt(&option, "Ingrese la opcion deseada: ", ERROR_MESSAGE, 1, 6))
                {
                    switch(option)
                    {
                        case 1:
                            if(!inputs_getString(nameAux, "Ingrese el nuevo Nombre: ",
                                                 ERROR_MESSAGE, 1, CUSTOMER_NAME_MAX))
                            {
                                strcpy(customersList[indexAux].name, nameAux);
                                printf("Nombre modificado con exito.\n");
                                returnValue = OK;
                            }
                            break;
                        case 2:
                            if(!inputs_getString(lastNameAux, "Ingrese el nuevo Apellido: ",
                                                 ERROR_MESSAGE, 1, CUSTOMER_NAME_MAX))
                            {
                                strcpy(customersList[indexAux].lastName, lastNameAux);
                                printf("Apellido modificado con exito.\n");
                                returnValue = OK;
                            }
                            break;
                        case 3:
                            do
                            {
                                if(!inputs_getChar(&sexAux, "Ingrese el nuevo Sexo [F] o [M]: ",
                                                   ERROR_MESSAGE, 'a', 'Z'))
                                {
                                    sexAux = toupper((char)sexAux);
                                }
                            }while(sexAux != 'F' && sexAux != 'M');

                            if(sexAux == 'F' || sexAux == 'M')
                            {
                                customersList[indexAux].sex = sexAux;
                                printf("Sexo modificado con exito.\n");
                                returnValue = OK;
                            }
                            break;
                        case 4:
                            if(!inputs_getString(phoneAux,
                                                 "Ingrese el nuevo Telefono [Formato: +54 11 1111-1111]: ",
                                                 ERROR_MESSAGE, 1, CUSTOMER_PHONE_MAX))
                            {
                                strcpy(customersList[indexAux].phone, phoneAux);
                                printf("Telefono modificado con exito.\n");
                                returnValue = OK;
                            }
                            break;
                        case 5:
                            if(!inputs_getString(addressAux, "Ingrese la nueva Direccion: ",
                                                 ERROR_MESSAGE, 1, CUSTOMER_ADDRESS_MAX))
                            {
                                strcpy(customersList[indexAux].address, addressAux);
                                printf("Direccion modificada con exito.\n");
                                returnValue = OK;
                            }
                            break;
                        case 6:
                            printf("Operacion cancelada.\n");
                            returnValue = OK;
                            break;
                    }
                }
            }
        }
    }

    return returnValue;
}

int customers_delete(sCustomer customersList[], int customersLength)
{
    int returnValue = ERROR;
    int id;
    int index;

    if(customersList != NULL
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX)
    {
        id = customers_userSelection("Ingrese el ID del Cliente a dar de baja: ",
            ERROR_MESSAGE, customersList, customersLength);

        if(id != ERROR)
        {
            index = customers_getIndexById(customersList, customersLength, id);

            if(index != ERROR)
            {
                inputs_clearScreen();
                printf("ATENCION! ESTA A PUNTO DE DAR DE BAJA AL SIGUIENTE CLIENTE:\n");
                customers_print(customersList[index]);

                if(inputs_userResponse("ESTA DE ACUERDO? [S] [N]: "))
                {
                    customersList[index].isEmpty = TRUE;
                    returnValue = OK;
                }
            }
        }
    }

    return returnValue;
}

int customers_sort(sCustomer customersList[], int customersLength, int order)
{
    int returnValue = ERROR;

    if(customersList != NULL
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX
       && (order == ASC || order == DESC))
    {
        for(int i= 0; i < customersLength-1 ; i++)
        {
            for(int j = i+1; j < customersLength; j++)
            {
                if(customers_isCustomer(customersList[i])
                   && customers_isCustomer(customersList[j]))
                {
                    if((customersList[i].sex > customersList[j].sex && order == ASC)
                       || (customersList[i].sex < customersList[j].sex && order == DESC))
                    {
                        if(customers_swap(&customersList[i], &customersList[j]) == OK)
                        {
                            returnValue = OK;
                        }
                    }
                    else
                    {
                        if(customersList[i].sex == customersList[j].sex)
                        {
                            if((strcmp(arrays_stringToCamelCase(customersList[i].lastName, CUSTOMER_NAME_MAX),
                                       arrays_stringToCamelCase(customersList[j].lastName, CUSTOMER_NAME_MAX)) > 0
                                && order == ASC)
                                || (strcmp(arrays_stringToCamelCase(customersList[i].lastName, CUSTOMER_NAME_MAX),
                                       arrays_stringToCamelCase(customersList[j].lastName, CUSTOMER_NAME_MAX)) < 0
                                && order == DESC))
                            {
                                if(customers_swap(&customersList[i], &customersList[j]) == OK)
                                {
                                    returnValue = OK;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return returnValue;
}

void customers_print(sCustomer customer)
{
    if(customers_isCustomer(customer))
    {
        printf("+=======+======================+======================+======+======================+======================+\n");
        printf("|   ID  |        NOMBRE        |       APELLIDO       | SEXO |       TELEFONO       |       DIRECCION      |\n");
        printf("+=======+======================+======================+======+======================+======================+\n");
        if(printCustomer(customer) == 0)
        {
            printf("Categoria vacia.\n");
        }
        printf("+-------+----------------------+----------------------+------+----------------------+----------------------+\n");
    }
}

int customers_printList(sCustomer customersList[], int customersLength)
{
    int itemsCounter = 0;
    int flag = 0;

    if(customersList != NULL
       && customersLength > 0 && customersLength <= CUSTOMERS_MAX)
    {
        for (int i = 0; i < customersLength; i++)
        {
            if(customers_isCustomer(customersList[i]))
            {
                itemsCounter++;

                if(itemsCounter == 1)
                {
                    printf("+=======+======================+======================+======+======================+======================+\n");
                    printf("|   ID  |        NOMBRE        |       APELLIDO       | SEXO |       TELEFONO       |       DIRECCION      |\n");
                    printf("+=======+======================+======================+======+======================+======================+\n");
                }

                if(printCustomer(customersList[i]) == 1)
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
        }

        if(flag == 1)
        {
            printf("+-------+----------------------+----------------------+------+----------------------+----------------------+\n");
        }
    }

    return itemsCounter;
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

static int printCustomer(sCustomer customer)
{
    int counter = 0;

    if(customers_isCustomer(customer))
    {
        printf("| %5d | %20s | %20s |   %c  | %20s | %20s |\n",
               customer.id, arrays_stringToCamelCase(customer.name, CUSTOMER_NAME_MAX),
               arrays_stringToCamelCase(customer.lastName, CUSTOMER_NAME_MAX),
               toupper((char)customer.sex), customer.phone,
               arrays_stringToCamelCase(customer.address, CUSTOMER_ADDRESS_MAX));
        counter = 1;
    }

    return counter;
}
