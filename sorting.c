#include "bubble.h"
#include "quick.h"
#include "set.h"
#include "shell.h"
#include "stack.h"
#include "stats.h"

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //for getop()

#define OPTIONS "absqQr:n:p:"

typedef enum SORTS { BUBBLE_SORT, SHELL_SORT, QUICK_SORT_STACK, QUICK_SORT_QUEUE } SORTS;

int main(int argc, char **argv) {
    int32_t opt = 0;
    uint64_t seed = 13371453;
    uint32_t elements = 100; //array of size
    uint64_t size = 100; //number of elements to print`

    Set s = set_empty(); //creates an empty set

    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'r':
            seed = atoi(optarg); //convert char value to val
            break;
        case 'p': size = atoi(optarg); break;
        case 'n': elements = atoi(optarg); break;
        case 'a':
            s = set_insert(s, BUBBLE_SORT); //add all sorting to the set
            s = set_insert(s, SHELL_SORT);
            s = set_insert(s, QUICK_SORT_STACK);
            s = set_insert(s, QUICK_SORT_QUEUE);
            break;
        case 'b': s = set_insert(s, BUBBLE_SORT); break;
        case 's': s = set_insert(s, SHELL_SORT); break;
        case 'q': s = set_insert(s, QUICK_SORT_STACK); break;
        case 'Q': s = set_insert(s, QUICK_SORT_QUEUE); break;
        }
    }

    uint32_t *A
        = (uint32_t *) calloc(elements, sizeof(uint32_t)); //creates an array and fills them in 0
    //inspired by Mary during TA tutoring
    for (uint32_t i = BUBBLE_SORT; i <= QUICK_SORT_QUEUE;
         i++) { //looks through all the possible sorts
        if (set_member(s, i) == false) { //check if the sort is in the set if not skips the loop
            continue;
        }
        srandom(seed); //set the seed back to orginal in order to get same random numbers.
        for (uint32_t x = 0; x < elements; x++) {
            A[x] = random(); //sets all the arrays to random values
        }
        stats_zeros(); //resets the data
        switch (i) {
        case BUBBLE_SORT:
            printf("Bubble Sort\n");
            bubble_sort(A, elements);
            print_stats(elements); //prints data
            break;
        case SHELL_SORT:
            printf("Shell Sort\n");
            shell_sort(A, elements);
            print_stats(elements);
            break;
        case QUICK_SORT_STACK:
            printf("Quick Sort (Stack)\n");
            quick_sort_stack(A, elements);
            print_stats(elements);
            print_stack_size();
            break;
        case QUICK_SORT_QUEUE:
            printf("Quick Sort (Queue)\n");
            quick_sort_queue(A, elements);
            print_stats(elements);
            print_queue_size();
            break;
        }
        //if the size is greater than the actual size of the array it will just print everything and
        //nothing more
        //else it will use the size given
        for (uint32_t x = 0; x < (size > elements ? elements : size); x++) {
            if (x && x % 5 == 0) { //every 5 elements creates a new line
                printf("\n");
            }
            printf("%13" PRIu32, A[x]); //prints elements in the array in width of 13
        }
        if (size != 0 && set_member(s, i + 1) != 0) { //if there are anymore dont print a new line
            printf("\n");
        }
    }
    if (size != 0) {
        printf("\n");
    }
    free(A); //deletes the space allocated for the array
    return 0;
}
