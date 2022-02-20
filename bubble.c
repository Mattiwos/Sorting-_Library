#include "bubble.h"

#include "stats.h"

#include <stdbool.h>
void bubble_sort(uint32_t *A, uint32_t n) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (uint32_t i = 1; i < n; i++) {
            compared();
            if (A[i] < A[i - 1]) {
                uint32_t tmp = A[i - 1];
                A[i - 1] = A[i];
                A[i] = tmp;
                moved();
                moved();
                moved();
                swapped = true;
            }
        }
        n -= 1;
    }
}
