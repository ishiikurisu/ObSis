#include "stdio.h"
#include "stdlib.h"
#include "./middleware.h"

void MIDDLE_debug(su_t* su, travel_t* ttt)
{
    printf("%ld %ld\n", sizeof(su), sizeof(ttt));
}

void MIDDLE_draw_trace_from_table(travel_t* ttt, int x, int z, const char* filename)
{
    FILE* fp = fopen(filename, "w");
    int t = 0;

    for (t = 0; t < ttt->ntr; ++t)
    {
        fprintf(fp, "%.5f %.5f \n", ttt->table[t][x][z]);
    }

    fclose(fp);
}
