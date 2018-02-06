#include "stdio.h"
#include "stdlib.h"
#include "reader/sureader.h"
#include "reader/tttreader.h"
#include "reader/help.h"
#include "calculator/middleware.h"

int main(int argc, char const *argv[]) {
    printf("--- # SU Files\n");
    su_t *su = SUREADER_load("./data/zonoise10.su");
    printf("%ld\n", sizeof(su));
    printf("--- # Time Transit Table\n");
    travel_t *ttt = TTTREADER_read("../../table.bin", 700, 250, su->ntr);
    printf("#ttt->table = %ld (%ld)\n", sizeof(ttt->table), 700*250*su->ntr);
    printf("--- # Hyperbole preview\n");
    char* template = "data/sample%d.bin";
    char* outlet = (char*) malloc(sizeof(char) * 20);
    int x = 0;
    for (x = 0; x < ttt->nx; x += 100)
    {
        sprintf(outlet, template, x);
        MIDDLE_draw_trace_from_table(ttt, x, outlet);
    }
    // DO NOT FORGET TO DRAW IT
    printf("...\n");
    SUREADER_free(su);
    TTTREADER_free(ttt);
    return 0;
}
