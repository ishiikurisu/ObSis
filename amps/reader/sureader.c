#include "stdio.h"
#include "stdlib.h"
#include "./sureader.h"

int SUREADER_get_number_samples(char* header)
{
    return ((header[114] << 8) | header[115]);
}

long SUREADER_get_number_traces(char* header)
{
    return ~((((long) header[204]) << 24) | (((long) header[205]) << 16) | (((long) header[206]) << 8) | ((long) header[207]));
}

char* SUREADER_read_header(FILE* fp)
{
    char* header;

    header = (char*) malloc(sizeof(char) * 240);
    fread(header, sizeof(char), 240, fp);

    return header;
}

float* SUREADER_read_trace(FILE* fp, char* header)
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
