#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void convertHexToBinary(int* arr, long value) {
    int compare;
    for (int bytes = 7; bytes >= 0; bytes--) {
        compare = value >> bytes;
        arr[bytes] = compare & 1 ? 1 : 0;
    }
}

// Credit taken from https://stackoverflow.com/questions/12700497/how-to-concatenate-two-integers-in-c#:~:text=char%20str%5B100%5D%3B%20int,the%20number%20with%20strtol()%20.
unsigned concatenateNumbers(unsigned x, unsigned y) {
    unsigned pow = 10;
    while (y >= pow) {
        pow *= 10;
    }
    return x * pow + y;
}

int convertBinaryToDec(long value) {
    int i = 0, decimal = 0;
    while (value != 0) {
        int digit = value % 10;
        decimal += digit * pow(2, i);
        value /= 10;
        i++;
    }
    return decimal;
}

int main(int argc, char* argv[]) {
    int result[8];
    if (argc != 2) {
        printf("ERROR: No arguments given!");
        return 1; 
    }
    
    long hexToNumber = strtol(argv[1], NULL, 16);
    convertHexToBinary(result, hexToNumber);

    int engine_on = 0;
    int gear_pos = 0;
    int key_pos = 0;
    int brake1 = 0;
    int brake2 = 0;

    if (result[7] == 1) {
        engine_on++;
    }

    int firstConcat = convertBinaryToDec(concatenateNumbers(result[6], result[5]));
    int secondConcat = convertBinaryToDec(concatenateNumbers(firstConcat, result[4]));
    gear_pos = secondConcat;

    key_pos = convertBinaryToDec(concatenateNumbers(result[3], result[2]));
    // printf("%d", convertBinaryToDec(concatenateNumbers(result[5], result[4])));

    if (result[1] == 1) {
        brake1++;
    }

    if (result[0] == 1) {
        brake2++;
    }

    printf("Name\t\tValue\n");
    printf("----------------------------\n");
    printf("engine_on\t\t%d\n", engine_on);
    printf("gear_pos\t\t%d\n", gear_pos);
    printf("key_pos\t\t\t%d\n", key_pos);
    printf("brake1\t\t\t%d\n", brake1);
    printf("brake2\t\t\t%d\n", brake2);
}