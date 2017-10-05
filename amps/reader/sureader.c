#include "stdio.h"
#include "stdlib.h"
#include "./sureader.h"

int SUREADER_get_number_samples(char* header)
{
    return (header[115] << (8*sizeof(char))) + header[114];
}

char* SUREADER_read_header(FILE* fp)
{
    char* header;
    char c;
    int i;

    header = (char*) malloc(sizeof(char) * 240);
    for (i = 0; i < 240; ++i)
    {
        fscanf(fp, "%c", &c);
        header[i] = c;
    }

    return header;
}

char* SUREADER_read_trace(FILE* fp, char* header)
{
    char *trace;
    int ns;
    int i;
    char c;

    ns = SUREADER_get_number_samples(header);
    trace = (char*) malloc(sizeof(char) * (ns+1));
    for (i = 0; i < ns; ++i)
    {
        fscanf(fp, "%c", &c);
        trace[i] = c;
    }

    return trace;
}

void SUREADER_draw_something(char* thing, int length)
{
    int i;
    for (i = 0; i < length; ++i)
    {
        printf("%d. %d\t", i+1, thing[i]);
    }
    printf("\n");
}

void SUREADER_draw_header(char* header)
{
    SUREADER_draw_something(header, 240);
}
