#include "stdio.h"
#include "stdlib.h"
#include "./tttreader.h"

travel_t* TTTREADER_new()
{
    travel_t *ttt;

    ttt = (travel_t*) malloc(sizeof(travel_t));
    ttt->dx = 0;
    ttt->dz = 0;
    ttt->dt = 0;
    ttt->table = NULL;

    return ttt;
}

travel_t* TTTREADER_read(const char filename[])
{
    // TODO Implement me!
    return NULL;
}
