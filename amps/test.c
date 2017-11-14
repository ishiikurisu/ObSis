#include "stdio.h"
#include "stdlib.h"
#include "reader/sureader.h"
#include "reader/tttreader.h"
#include "reader/help.h"

int main(int argc, char const *argv[]) {
    printf("--- # SU Files\n");
    su_t *su = SUREADER_load("./data/zonoise10.su");
    printf("%ld\n", sizeof(su));
    free(su);
    printf("--- # Time Transit Table\n");
    travel_t *ttt = TTTREADER_new();
    printf("%d %d %d\n", ttt->dx, ttt->dz, ttt->dt);
    free(ttt);
    printf("...\n");
    return 0;
}
