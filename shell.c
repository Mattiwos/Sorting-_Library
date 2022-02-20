#include "shell.h"

#include "gaps.h"
#include "stats.h"

void shell_sort(uint32_t *A, uint32_t n) {
    for (uint32_t i = 0; i < GAPS; i++) { //i = gap
        for (uint32_t y = gaps[i]; y < n; y++) {
            uint32_t j = y; //gap
            uint32_t tmp = A[y]; //value at gap in array
            while (j >= gaps[i] && compare(tmp < A[j - gaps[i]])) { //starts at the arry[0]
                A[j] = A[j - gaps[i]];
                moved();
                moved(); //swapped
                moved();
                j -= gaps[i];
            }
            A[j] = tmp;
        }
    }
}
