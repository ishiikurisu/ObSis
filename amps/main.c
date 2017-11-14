#include "stdio.h"
#include "reader/sureader.h"

int main(int argc, char const *argv[]) {
    SUREADER_su_to_bin(argv[1], argv[2]);
    return 0;
}
