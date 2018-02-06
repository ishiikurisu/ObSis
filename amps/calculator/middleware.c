#include "stdio.h"
#include "stdlib.h"
#include "./middleware.h"

void MIDDLE_debug(su_t* su, travel_t* ttt)
{
    printf("%ld %ld\n", sizeof(su), sizeof(ttt));
}

void MIDDLE_draw_trace_from_table(travel_t* ttt, int X, const char* filename)
{
    FILE* fp = fopen(filename, "wb");
    float Z = ttt->nz;
    float T = ttt->ntr;
    int z, t;

    fwrite(&T, sizeof(float), 1, fp);
    fwrite(&Z, sizeof(float), 1, fp);

    for (z = 0; z < ttt->nz; ++z)
    {
        for (t = 0; t < ttt->ntr; ++t)
        {
            fwrite(&ttt->table[t][X][z], sizeof(float), 1, fp);
        }
    }

    fclose(fp);
}
