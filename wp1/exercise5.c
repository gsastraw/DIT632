#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100      // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers

// ------ Function declarations ----------

// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab) {
    // Provides us with a random seed to create random numbers with. time(NULL) is an arbitrary number that lets us do this.
    srand(time(NULL));
    
    // Loop through the entire tab array and populate it with random numbers from 0-20.
    for (int i = 0; i < MAX; i++) {
        tab[i] = rand() % MAXNUMBER;
    }
}

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq) {
    int value;
    /* 
    Loop through the entire frequency array and set all values to an initial value of 0, because we haven't encountered them yet 
    in our table array containing all values.
    */
    for (int i = 0; i < MAXNUMBER; i++) {
        freq[i] = 0;
    }
    /*
    Loop through the entire table array. Each index in this frequency array corresponds to a unique number in the table. Each value in the 
    frequency array corresponds to how many times this number appears. 

    When a number is encountered within the table array, the corresponding value contained within the index corresponding to this number is 
    incremented. 
    */
    for (int i = 0; i < MAX; i++) {
        value = tab[i];
        freq[value]++;
    }
}

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq) {
    // Loop through the entire frequency array
    for (int number = 0; number < MAXNUMBER; number++) {
        /* 
        If the number within this frequency array is not 0, print out the frequency as Xs. We intentionally skip all the numbers
        that don't exist within the program. 
        */ 
        if (freq[number] != 0) {
            printf("%d   ", number);
            for (int i = 0; i < freq[number]; i++) {
                printf("x");
            }
            printf("\n");
        }
    }
}

// ------ Function definitions ----------
/* 
Comparator function that compares between two elements to sort array. We declare this function with two parameters:
    @a and b = const void because we do not want to modify this at all, and because we want to pass in a pointer to the 
               variables contained within this pointer address. Additionally, we want to be able to pass this in to qsort() which
               takes in a comparator function that requires const void* in parameters.
    
    We then convert a and b to integers and return the value.
*/
int comparator (const void* a, const void* b) {
    return (*(int*) a - *(int*) b);
}

// ------ Main --------------------------
// The main entry point for the program
//

// If you choose to go for the optional part
// Please modify it accordingly
int main(void) {
  int table[MAX], n;
  int frequency[MAXNUMBER];
  create_random(table);
  // Sort through the array from least to greatest
  qsort(table, MAX, sizeof(int), comparator);
  count_frequency(table, frequency);
  draw_histogram(frequency);
  // Success code 
  return 0;
}