#include "stdio.h"
#include "stdlib.h"
#include "./sureader.h"

int life()
{
    return 42;
}

FILE* skip(FILE* fp, int how_much)
{
    int i = 0;
    char c;
    for (i = 0; i < how_much; ++i)
    {
        fscanf(fp, "%c", &c);
    }
    return fp;
}

char* SUREADER_read_trace_header(const char* filename)
{
    char* header = (char*) malloc(sizeof(char) * 241);
    FILE* fp = fopen(filename, "r");
    int i = 0;
    unsigned char c;

    for (i = 0; i < 240; ++i)
    {
        fscanf(fp, "%c", &c);
        header[i] = c;
    }
    header[i] = '\0';

    fclose(fp);
    return header;
}

int SUREADER_get_number_samples(char* header)
{
    return (header[115] << (8*sizeof(char))) + header[114];
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


char* SUREADER_read_raw_trace(const char* filename)
{
    char* header;
    int ns;
    char* trace;
    FILE* fp;
    int i;
    char c;

    header = SUREADER_read_trace_header(filename);
    ns = SUREADER_get_number_samples(header);
    trace = (char*) malloc(sizeof(char) * ns);
    fp = fopen(filename, "r");
    fp = skip(fp, 240);

    for (i = 0; i < ns; ++i)
    {
        fscanf(fp, "%c", &c);
        trace[i] = c;
    }

    free(header);
    return trace;
}
