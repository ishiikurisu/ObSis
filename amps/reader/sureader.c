#include "stdio.h"
#include "stdlib.h"
#include "./sureader.h"
#include "./header/suheader.h"

int SUREADER_get_number_samples(trace_t* header)
{
    return header->ns;
}

long SUREADER_get_number_traces(trace_t* header)
{
    return header->ntr;
}

trace_t* SUREADER_read_header(FILE* fp)
{
    trace_t* header = (trace_t*) malloc(sizeof(trace_t));

    fread(header, 240, 1, fp);

    return header;
}

float* SUREADER_read_trace(FILE* fp, trace_t* header)
{
    float *trace;
    int ns;

    ns = SUREADER_get_number_samples(header);
    trace = (float*) malloc(sizeof(float) * ns);
    fread(trace, sizeof(float), ns, fp);

    return trace;
}

void SUREADER_draw_something(char* thing, int length)
{
    int i;
    for (i = 0; i < length; ++i)
    {
        printf("%d. %hhu\t", i+1, thing[i]);
    }
    printf("\n");
}

void SUREADER_draw_header(char* header)
{
    SUREADER_draw_something(header, 240);
}

void SUREADER_su_to_bin(const char* input, const char* output)
{
    FILE* inlet = fopen(input, "r");
    FILE* outlet = fopen(output, "w");
    trace_t *header;
    int ns;
    long ntr;
    int i;
    float* trace;

    // Reading first header
    header = SUREADER_read_header(inlet);
    ns = SUREADER_get_number_samples(header);
    ntr = SUREADER_get_number_traces(header);
    trace = SUREADER_read_trace(inlet, header);
    fprintf(outlet, "%f", (float) ntr);
    fprintf(outlet, "%f", (float) ns);
    fwrite(trace, sizeof(float), ns, outlet);
    free(header);
    free(trace);

    // Reading following headers
    for (i = 1; i < ntr; ++i)
    {
        header = SUREADER_read_header(inlet);
        ns = SUREADER_get_number_samples(header);
        trace = SUREADER_read_trace(inlet, header);
        fwrite(trace, sizeof(float), ns, outlet);
        free(header);
        free(trace);
    }

    fclose(inlet);
    fclose(outlet);
}
