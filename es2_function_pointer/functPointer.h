#include <stdio.h>
#include <stdint.h>


typedef struct 
{
    uint8_t var_1;
    uint8_t (*fp)(uint8_t a);
} MyVars_t;

extern MyVars_t myVars ;

uint8_t my_function(uint8_t a);
