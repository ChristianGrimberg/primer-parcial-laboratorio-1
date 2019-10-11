#include "rents.h"

static int isCustomer(sRental rental);
static sCustomer nullRental(void);
static int getNewId(void);
static int printRental(sRental rental);

static int getNewId(void)
{
    static int rentalId = ID_INIT_RENTAL;
    rentalId++;
    return rentalId;
}
