#include <stdio.h>
#include <stdint.h>

/** constant **/
/** NUMBER OF FUNCTIONS **/
#define MAX_NUMBER_FUNCTIONS    2
#define ADD_FUNCTION            0
#define SUB_FUNCTION            1

/** tpedef definitations **/
typedef struct 
{
    uint8_t var_1;
    uint8_t var_2;
    int16_t result;
    int16_t (*fp)(uint8_t a, uint8_t b);
} MyVars_t;

extern MyVars_t myVars [MAX_NUMBER_FUNCTIONS];

/** declarations **/
int16_t add(uint8_t a, uint8_t b);
int16_t sub(uint8_t a, uint8_t b);