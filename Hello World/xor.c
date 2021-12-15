#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char ** argv){


    uint8_t x = 1;
    printf("Data in x: %d\n", x);

    x ^= x;

    printf("Data in x: %d\n", x);

    x ^= 1;

    printf("Data in x: %d\n", x);

    return 0;
}