#include "functPointer.h"

MyVars_t myVars [MAX_NUMBER_FUNCTIONS] =
{
    {
        .var_1 = 10,
        .var_2 = 5,
        .fp = &add,
    },
    {
        .var_1 = 10,
        .var_2 = 3,
        .fp = sub,
    }
};

int main (void)
{
    printf ("Il risultato di %d + %d \n\r", myVars[ADD_FUNCTION].var_1, myVars[ADD_FUNCTION].var_2);
    myVars[ADD_FUNCTION].result = (int16_t) myVars[ADD_FUNCTION].fp (myVars[ADD_FUNCTION].var_1, myVars[ADD_FUNCTION].var_2);
    printf ("= %d \n",  myVars[ADD_FUNCTION].result); 

    printf ("Il risultato di %d - %d \n\r\", myVars[SUB_FUNCTION].var_1, myVars[SUB_FUNCTION].var_2);
    myVars[SUB_FUNCTION].result = (int16_t) myVars[SUB_FUNCTION].fp (myVars[SUB_FUNCTION].var_1, myVars[SUB_FUNCTION].var_2);
    printf ("= %d \n",  myVars[SUB_FUNCTION].result); 

    return 0;
}

/* */
int16_t add(uint8_t a, uint8_t b)
{
    return (a + b);
}

/* */
int16_t sub(uint8_t a, uint8_t b)
{
    return (a - b);
}