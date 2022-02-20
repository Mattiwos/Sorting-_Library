#include "quick.h"

#include "queue.h"
#include "stack.h"
#include "stats.h"

#include <stdio.h>

uint32_t max_stack_size = 0;
uint32_t max_queue_size = 0;

int64_t partition(uint32_t *A, int64_t lo, int64_t hi) {
    int64_t index = lo + ((hi - lo) / 2);
    uint32_t pivot = A[index]; //middle of array
    //printf("Index: %ld, lo: %u, hi: %u, pivot:%ld \n",index,lo,hi,pivot);
    int64_t i = lo - 1;
    int64_t j = hi + 1;
    while (i < j) {
        i += 1;
        while (compare(A[i] < pivot)) {
            i += 1;
        }
        j -= 1;
        while (compare(A[j] > pivot)) {
            j -= 1;
        }
        if (i < j) {
            int64_t tmp = A[i];
            moved();
            A[i] = A[j];
            moved();
            A[j] = tmp;
            moved();
        }
    }
    return j;
}
void quick_sort_stack(uint32_t *A, uint32_t n) {
    int64_t lo = 0;
    int64_t hi = n - 1;
    //create stack
    Stack *s = stack_create(n);
    stack_push(s, lo);
    stack_push(s, hi);
    max_stack_size = stack_size(s);
    while (stack_size(s) != 0) {
        //printf("Size %d \n",stack_size(s));
        stack_pop(s, &hi);
        stack_pop(s, &lo);

        int64_t p = partition(A, lo, hi);
        if (p + 1 < hi) {
            stack_push(s, p + 1);
            stack_push(s, hi);
        }
        if (lo < p) {
            stack_push(s, lo);
            stack_push(s, p);
        }
        if (max_stack_size < stack_size(s)) {
            max_stack_size = stack_size(s);
        }
    }

    count_stack(max_stack_size);
    stack_delete(&s);
    return;
}

void quick_sort_queue(uint32_t *A, uint32_t n) {
    int64_t lo = 0;
    int64_t hi = n - 1;
    //create stack
    Queue *q = queue_create(n);
    enqueue(q, lo);
    enqueue(q, hi);
    max_queue_size = queue_size(q);
    while (queue_size(q) != 0) {
        dequeue(q, &lo);
        dequeue(q, &hi);
        int64_t p = partition(A, lo, hi);
        if (hi > p + 1) {
            enqueue(q, p + 1);
            enqueue(q, hi);
        }
        if (lo < p) {
            enqueue(q, lo);
            enqueue(q, p);
        }
        if (max_queue_size < queue_size(q)) {
            max_queue_size = queue_size(q);
        }
    }
    count_queue(max_queue_size);
    queue_delete(&q);
    return;
}
