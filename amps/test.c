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
    travel_t *ttt = TTTREADER_read("data/table.bin", 700, 250, su->ntr);
    printf("#ttt->table = %ld (%ld)\n", sizeof(ttt->table), 700*250*su->ntr);
    printf("...\n");
    TTTREADER_free(ttt);
    return 0;
}
