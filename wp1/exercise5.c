#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100      // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers

// ------ Function declarations ----------

// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab) {
    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        tab[i] = rand() % MAXNUMBER;
    }
}

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq) {
    for (int i = 0; i < MAX; i++) {
        for (int j = i + 1; j < MAX; j++) {
            
        }
    }
}

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq) {

}

// ------ Function definitions ----------
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
  qsort(table, MAX, sizeof(int), comparator);
  count_frequency(table, frequency);
}