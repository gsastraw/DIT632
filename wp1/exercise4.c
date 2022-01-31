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
    //takes in char
    //print bits of character
    //no char turn
    //call function 8 times for 8 bytes long
    //target
    //8 bits of a byte instead of bytes of long int
    int i;
    unsigned char bits[9];

    for (i = 0; i < 8; i++)
    {
        //store output into an array (backwards)
        //string to chars corresponding to string rep of bits of byte

        char c = '0';
        //assess if 0 or 1, if true
        if ((target >> i) & 1)
        {
            //c will be changed from 0 to 1 because the bit is set
            //this will only happen if it is 1, otherwise it remains 0
            c = '1';
        }

        //c is assigned to array in order to avoid ending up with ASCII 0 or 1, which are characters
        //you can't see. 0 is a string terminator and may misinterpret as end of string.
        bits[7 - i] = c;
    }

    //set to 0 in order to terminate string
    bits[8] = 0;

    //prints out string
    printf("%s", bits);
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

    //declared as unsigned because the purpose is to elicit the max instead of subtracting from the value
    unsigned char char_max = 0;
    unsigned short short_max = 0;
    unsigned int int_max = 0;
    unsigned long long_max = 0;

    //elicits the maximum value from each variable as they reset to the upper bound prior to 0
    char_max--;
    short_max--;
    int_max--;
    long_max--;

    //j is the bytes to print or the number of bytes interested in
    int j = 0;
    if (converted < char_max)
    {
        j = 1;
    }
    else if (converted < short_max)
    {
        j = 2;
    }
    else if (converted < int_max)
    {
        j = 4;
    }
    else if (converted < long_max)
    {
        j = 8;
    }

    //takes all of the bytes and subtracts what is needed
    //defines where to start printing
    int offset = 8 - j;

    //function that takes byte and prints bits
    for (int i = 0; i < j; i++)
    {
        //print bits in a byte
        //takes the number of bytes needed and adds how many iterations are happening
        //starts from the left/ position of interest
        print_bits(bytes[offset + i]);
    }

    //64 byte string

    return 0;
}
