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
    FILE* inlet = fopen(input, "rb");
    FILE* outlet = fopen(output, "wb");
    trace_t *header;
    int ns;
    long ntr;
    int i;
    float* trace;
    float fns;
    float fntr;

    // Reading first header
    header = SUREADER_read_header(inlet);
    ns = SUREADER_get_number_samples(header);
    ntr = SUREADER_get_number_traces(header);
    trace = SUREADER_read_trace(inlet, header);
    fns = (float) ns;
    fntr = (float) ntr;
    fwrite(&fntr, sizeof(float), 1, outlet);
    fwrite(&fns, sizeof(float), 1, outlet);
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

su_t* SUREADER_new()
{
    su_t* su = (su_t*) malloc(sizeof(su_t));

    su->ns = 0;
    su->ntr = 0;
    su->traces = NULL;

    return su;
}

su_t* SUREADER_add_trace(su_t* su, float* trace)
{
    long i;

    if ((su->ntr > 0) && (su->traces == NULL))
    {
        su->traces = (float**) malloc(su->ntr * sizeof(float*));
        for (i = 0; i < su->ntr; ++i)
            su->traces[i] = NULL;
    }

    for (i = 0; su->traces[i] != NULL; ++i);
    su->traces[i] = trace;

    return su;
}

su_t* SUREADER_load(const char* input)
{
    FILE* inlet = fopen(input, "r");
    su_t* su = SUREADER_new();
    trace_t* header;
    float* trace;
    int ns;
    long ntr;
    int i;

    // Reading first header
    header = SUREADER_read_header(inlet);
    ns = SUREADER_get_number_samples(header);
    ntr = SUREADER_get_number_traces(header);
    trace = SUREADER_read_trace(inlet, header);
    su->ns = ns;
    su->ntr = ntr;
    SUREADER_add_trace(su, trace);
    free(header);

    // Reading following headers
    for (i = 1; i < ntr; ++i)
    {
        header = SUREADER_read_header(inlet);
        ns = SUREADER_get_number_samples(header);
        trace = SUREADER_read_trace(inlet, header);
        SUREADER_add_trace(su, trace);
        free(header);
    }

    fclose(inlet);
    return su;
}

void SUREADER_free(su_t* su)
{
    free(su->traces);
    free(su);
}
