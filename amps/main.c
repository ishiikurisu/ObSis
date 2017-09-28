#include "stdio.h"
#include "reader/sureader.h"

int main(int argc, char const *argv[]) {
    printf("Let's conquer geophysics?\n");
    printf("First the answer of life: %d\n", life());
    printf("File parameter: %s\n", argv[1]);
    printf("First tracer header:\n%s\n", SUREADER_read_trace_header(argv[1]));
    return 0;
}
