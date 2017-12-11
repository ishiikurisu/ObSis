#include "stdio.h"
#include "stdlib.h"
#include "./tttreader.h"
#include <su.h>
#include <cwp.h>

travel_t* TTTREADER_new()
{
    travel_t *ttt;

    ttt = (travel_t*) malloc(sizeof(travel_t));
    ttt->nx = 0;
    ttt->nz = 0;
    ttt->ntr = 0;
    ttt->table = NULL;

    return ttt;
}

travel_t* TTTREADER_alloc(int nx, int nz, long ntr)
{
    travel_t *ttt = TTTREADER_new();

    ttt->nx = nx;
    ttt->nz = nz;
    ttt->ntr = ntr;
    ttt->table = alloc3float(nz, nx, ntr);
    if (!ttt->table) {
        printf("NO MORE MEMORY!\n");
        abort();
    }

    return ttt;
}

travel_t* TTTREADER_read(const char filename[], int nx, int nz, long ntr)
{
    FILE* fp = fopen(filename, "r");
    travel_t* ttt = TTTREADER_alloc(nx, nz, ntr);
    long n, i, j, k;

    if (fp == NULL) {
        printf("No file!\n");
        abort();
    }

    // Loading table to memory
    n = fread(ttt->table[0][0], sizeof(float), nx*nz*ntr, fp);
    if (n != nx*nz*ntr) {
        printf("NO MORE MEMORY!\n");
        abort();
    }

    // Taking the return travel time into consideration
    for (k = 0; k < nz; k++)
        for (j = 0; j < nx; j++)
            for (i = 0; i < ntr; i++)
                ttt->table[i][j][k] *= 2;

    fclose(fp);
    return ttt;
}

void TTTREADER_free(travel_t *ttt)
{
    free3((void***) ttt->table);
    free(ttt);
}
