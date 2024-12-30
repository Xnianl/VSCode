#include <stdio.h>
#include <stdint.h>
#include "test.h"

MyVars_t myVars [3];
uint8_t a;
uint8_t *p_a;

int main (void)
{
    printf ("hello world!!! \r\n");
    uint32_t pippo;
    myVars->luca_1 = 3;
    myVars->pippo_2 =2;
    printf("%d, %d \r\n", myVars->luca_1, myVars->pippo_2);

    p_a = &a;
    *p_a = 8;
    printf("%d, %d", a, *p_a);

    return 0;
} 