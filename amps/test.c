#include "stdio.h"
#include "stdlib.h"
#include "reader/sureader.h"
#include "reader/tttreader.h"
#include "reader/help.h"
// #include "calculator/middle.h"

int main(int argc, char const *argv[]) {
    printf("--- # SU Files\n");
    su_t *su = SUREADER_load("./data/zonoise10.su");
    printf("%ld\n", sizeof(su));
    printf("--- # Time Transit Table\n");
    travel_t *ttt = TTTREADER_read("data/table.bin", 700, 250, su->ntr);
    printf("#ttt->table = %ld (%ld)\n", sizeof(ttt->table), 700*250*su->ntr);
    // printf("--- # Middleware cube\n");
    // float*** cube = MIDDLE_generate_cube(su, ttt);
    // printf("#cube->table = %ld\n", sizeof(cube));
    // printf("...\n");
    SUREADER_free(su);
    TTTREADER_free(ttt);
    return 0;
}
