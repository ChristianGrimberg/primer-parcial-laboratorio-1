#include "customers.h"

static int isCustomer(sCustomer customer);
static sCustomer nullCustomer(void);
static int getNewId(void);
static int printCustomer(sCustomer customer);

static int getNewId(void)
{
    static int customerId = ID_INIT_GAME;
    customerId++;
    return customerId;
}
