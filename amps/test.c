#include "stdio.h"
#include "stdlib.h"
#include "reader/sureader.h"
#include "reader/help.h"

int main(int argc, char const *argv[]) {
    const char test_file[] = "data/zonoise10.su";
    FILE* fp = fopen(test_file, "r");
    trace_t *header;
    int ns;
    long ntr;
    int i;
    long limit = 1;

    printf("Let's conquer geophysics?\n");
    printf("File parameter: %s\n", test_file);

    for (i = 0; i < limit; ++i)
    {
        header = SUREADER_read_header(fp);
        ns = SUREADER_get_number_samples(header);
        ntr = SUREADER_get_number_traces(header);
        limit = (limit != ntr)? ntr : limit;
        printf("# Header %d\nns: %d\nntr: %ld\n", i+1, ns, ntr);
        SUREADER_read_trace(fp, header);
        free(header);
    }

    fclose(fp);
    return 0;
}
