#include "stdio.h"
#include "stdlib.h"
#include "./middleware.h"

void MIDDLE_debug(su_t* su, travel_t* ttt)
{
    printf("%ld %ld\n", sizeof(su), sizeof(ttt));
}

travel_t* MIDDLE_generate_middle_cube(su_t* su, travel_t* ttt)
{
    travel_t *cube = TTTREADER_alloc(ttt->nx, ttt->nz, ttt->ntr);

    // TODO Pick amplitudes, please???

    return cube;
}
