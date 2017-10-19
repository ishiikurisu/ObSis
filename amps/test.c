#include "stdio.h"
#include "stdlib.h"
#include "reader/sureader.h"
#include "reader/help.h"
#include "header/suheader.h"

int main(int argc, char const *argv[]) {
    const char test_file[] = "data/zonoise10.su";
    FILE* fp = fopen(test_file, "r");
    char* header;
    float* trace;
    int ns;
    long ntr;
    int i;

    printf("Let's conquer geophysics?\n");
    printf("File parameter: %s\n", test_file);

    for (i = 0; i < 3; ++i)
    {
        header = SUREADER_read_header(fp);
        printf("--- # Trace #%d\n", i+1);
        ns = SUREADER_get_number_samples(header);
        ntr = SUREADER_get_number_traces(header);
        printf("ns: %d\nntr: %ld\n", ns, ntr);
        SUREADER_draw_header(header);
        trace = SUREADER_read_trace(fp, header);
        free(header);
        free(trace);
    }

    fclose(fp);
    return 0;
}
