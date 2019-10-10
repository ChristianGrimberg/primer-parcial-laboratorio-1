#include "games.h"

int main()
{
    char phone[PHONE_MAX];

    if(!inputs_getPhone(phone, "Ingrese un telefono: ", "Error: ", 1, PHONE_MAX))
    {
        printf("Numero ingresado: %s\n", phone);
    }
    return 0;
}
