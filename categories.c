#include "categories.h"

static int isCategory(sCategory category);
static sCategory nullCategory(void);
static int getNewId(void);
static int printCaegory(sCategory category);

static int isCategory(sCategory category)
{
    int returnValue = 0;

    return returnValue;
}

static int getNewId(void)
{
    static int categoryId = ID_INIT_CATEGORY;
    categoryId++;
    return categoryId;
}

