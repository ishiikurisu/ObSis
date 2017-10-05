#include "stdio.h"
#include "stdlib.h"
#include "./sureader.h"

int life()
{
    return 42;
}

char* SUREADER_read_trace_header(const char* filename)
{
    char* header = (char*) malloc(sizeof(char) * 241);
    FILE* fp = fopen(filename, "r");
    int i = 0;
    unsigned char c;

    printf("---\n");
    for (i = 0; i < 240; ++i)
    {
        fscanf(fp, "%c", &c);
        printf("%d. %d \t", i+1, c);
        header[i] = c;
    }
    printf("\n...\n");
    header[i] = '\0';

    fclose(fp);
    return header;
}
