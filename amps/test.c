#include "stdio.h"
#include "stdlib.h"
#include "reader/sureader.h"
#include "reader/help.h"


int main(int argc, char const *argv[]) {
    const char test_file[] = "data/zonoise10.su";
    char* header = SUREADER_read_trace_header(test_file);
    int number_samples = SUREADER_get_number_samples(header);
    char* trace = SUREADER_read_raw_trace(test_file);

    printf("Let's conquer geophysics?\n");
    print_bits_in_char(header[114]);
    print_bits_in_char(header[115]);
    print_bits_in_int(number_samples);
    printf("File parameter: %s\n", test_file);
    printf("--- # First tracer\n");
    printf("header:\n");
    SUREADER_draw_header(header);
    printf("number of samples: %u\n", number_samples);

    free(header);
    return 0;
}
