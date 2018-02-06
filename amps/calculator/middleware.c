#include "stdio.h"
#include "stdlib.h"
#include "./middleware.h"

void MIDDLE_debug(su_t* su, travel_t* ttt)
{
    printf("%ld %ld\n", sizeof(su), sizeof(ttt));
}

void MIDDLE_sample_draw(const char* output)
{
    FILE* fp = fopen(output, "wb");
    float fs = 1.0/200.0;
    float x = -2;
    float x2;
    int n = 4000;
    int i;

    for (i = 0; i < n; i++, x += fs)
    {
        x2 = x*x;
        fwrite(&x, sizeof(float), 1, fp);
        fwrite(&x2, sizeof(float), 1, fp);
    }

    fclose(fp);
}
