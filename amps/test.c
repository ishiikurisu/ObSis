#include "stdio.h"
#include "reader/sureader.h"

int main(int argc, char const *argv[]) {
    const char test_file[] = "data/zonoise10.su";
    printf("Let's conquer geophysics?\n");
    printf("First the answer of life: %d\n", life());
    printf("File parameter: %s\n", test_file);
    printf("First tracer header:\n%s\n", SUREADER_read_trace_header(test_file));
    return 0;
}
