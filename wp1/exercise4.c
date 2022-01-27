#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

void print_help()
{
    printf("Usage: dec2bin.exe <decimal number>\n");
    printf("Input must be under 19 digits.\n");
    //print how many digits is needed for long -> upper limit
}

void print_bits(char target)
{
    //8 bits of a byte instead of bytes of long int
}

int main(int argc, char **argv)
{
    int cursor = 0;
    char *eptr, output[64];
    long int converted;
    unsigned char bytes[8];

    if (argc != 2)
    {
        print_help();
        return -1;
    }

    if ((argv[1][0] == '-') && (argv[1][1] == 'h' || argv[1][1] == 'H'))
    {
        print_help();
        return -1;
    }

    //count characters within string
    while (argv[1][cursor] > 0)
    {
        //logs how many digits
        cursor++;
    }

    //19 digits + terminator
    if (cursor > 20)
    {
        printf("Warning: input has too many digits.\n");
        print_help();
        return -1;
    }

    //convert input parameter to long
    converted = strtol(argv[1], &eptr, 10);

    printf("%ld decimal\n", converted);

    //deal one byte at a time, convert long into an array of bytes

    //convert long int decimal to binary
    //masks bits we are looking at to get binary conversion
    //bitwise and compares bits of operands against each other and computing a result
    bytes[7] = (int)((converted & 0xFF));
    bytes[6] = (int)((converted >> 8) & 0xFF);
    bytes[5] = (int)((converted >> 16) & 0xFF);
    bytes[4] = (int)((converted >> 24) & 0xFF);
    bytes[3] = (int)((converted >> 32) & 0xFF);
    bytes[2] = (int)((converted >> 40) & 0xFF);
    bytes[1] = (int)((converted >> 48) & 0xFF);
    bytes[0] = (int)((converted >> 56) & 0xFF);

    //function that takes byte and prints bits

    //64 byte string

    return 0;
}
