#include "stdio.h"
#include "./middleware.h"

void MIDDLE_debug(su_t* su, travel_t* ttt)
{
    printf("%d %d\n", sizeof(su), sizeof(ttt));
}
