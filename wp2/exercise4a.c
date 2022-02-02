#include <stdlib.h>
#include <stdio.h>

typedef unsigned char byte; 

int main(int argc, char* argv[]) {
    char *buffer;
    size_t bufferSize = 8;
    size_t characters;
    unsigned char value = 0;

    if (argc != 6) {
        printf("ERROR: You need only five arguments.");
        return 1;
    }

    if (!(atoi(argv[1]) >= 0 && atoi(argv[1]) <= 1)) {
        printf("ERROR: Your first argument is not in the range of 0-1!");
        return 1;
    }

    if (!(atoi(argv[2]) >= 0 && atoi(argv[2]) <= 4)) {
        printf("ERROR: Your second argument is not in the range of 0-4!");
        return 1;
    }

    if (!(atoi(argv[3]) >= 0 && atoi(argv[3]) <= 2)) {
        printf("ERROR: Your third argument is not in the range of 0-2!");
        return 1;
    }

    if (!(atoi(argv[4]) >= 0 && atoi(argv[4]) <= 1)) {
        printf("ERROR: Your fourth argument is not in the range of 0-1!");
        return 1;
    }

    if (!(atoi(argv[5]) >= 0 && atoi(argv[5]) <= 1)) {
        printf("ERROR: Your fifth argument is not in the range of 0-1!");
        return 1;
    }

    value += atoi(argv[1]) << 7;
    value += atoi(argv[2]) << 4;
    value += atoi(argv[3]) << 2;
    value += atoi(argv[4]) << 1;
    value += atoi(argv[5]);

    printf("%02X\n", value);

    return 0;
}
