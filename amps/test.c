#include "stdio.h"
#include "stdlib.h"
#include "reader/sureader.h"
#include "reader/help.h"

int main(int argc, char const *argv[]) {
    const char test_file[] = "data/zonoise10.su";
    FILE* fp = fopen(test_file, "r");
    char* header;
    float* trace;
    int i;

    printf("Let's conquer geophysics?\n");
    printf("File parameter: %s\n", test_file);

    for (i = 0; i < 3; ++i)
    {
        header = SUREADER_read_header(fp);
        printf("--- # Trace #%d\n", i+1);
        SUREADER_draw_something(header, 240);
        trace = SUREADER_read_trace(fp, header);
        free(header);
        free(trace);
    }

    fclose(fp);
    return 0;
}
