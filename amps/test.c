#include "stdio.h"
#include "stdlib.h"
#include "reader/sureader.h"
#include "reader/help.h"

int main(int argc, char const *argv[]) {
    const char test_file[] = "data/zonoise10.su";
    const char output_file[] = "data/zonoise10.bin";
    SUREADER_su_to_bin(test_file, output_file);
    return 0;
}
