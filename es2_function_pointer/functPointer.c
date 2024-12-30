#include <stdio.h>
#include <stdint.h>
#include "functPointer.h"

MyVars_t myVars =
{
    .var_1 = 10,
    .fp = my_function,
};

int main (void)
{
    printf ("Il valore di var_1 è %d \r\n", myVars.var_1);

    myVars.var_1 = myVars.fp (myVars.var_1);    
    printf ("Il quadrato di var_1 è %d \r\n", myVars.var_1);
    return 0;
}

uint8_t my_function(uint8_t a)
{
    return (a * a);
}