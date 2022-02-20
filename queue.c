//From assigment Document 3
#include "queue.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    uint32_t head;
    uint32_t tail;
    uint32_t size;
    uint32_t capacity;
    int64_t *items;
} Queue;

Queue *queue_create(uint32_t capacity) {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    if (q) {
        q->head = 0;
        q->tail = 0;
        q->size = 0;
        q->capacity = capacity;
        q->items = (int64_t *) calloc(capacity, sizeof(int64_t));
        if (!q->items) {
            free(q);
            q = NULL;
        }
    }
    return q;
}

void queue_delete(Queue **q) {
    if (*q && (*q)->items) {
        free((*q)->items);
        free((*q));
        *q = NULL;
    }
    return;
}

bool queue_empty(Queue *q) {
    assert(q);
    if (((q->head + 1) % q->capacity) == q->tail) {
        return true;
    }
    return false;
}

bool queue_full(Queue *q) {
    assert(q);
    if (((q->head - q->tail) == q->capacity)) {
        return true;
    }
    return false;
}

uint32_t queue_size(Queue *q) {
    return q->size;
}

bool enqueue(Queue *q, int64_t x) {
    assert(q);
    if (!queue_full(q)) {
        q->items[q->head] = x;
        q->head = ((q->head + 1) % q->capacity);
        q->size += 1;
        return true;
    }
    return false;
}

bool dequeue(Queue *q, int64_t *x) {
    assert(q);
    if (!queue_empty(q)) {
        *x = q->items[q->tail];
        q->tail = ((q->tail + 1) % q->capacity);
        q->size -= 1;
        return true;
    }
    return false;
}

void queue_print(Queue *q) {
    if (q) {
        for (uint32_t i = 0; i < q->size; i++) {
            printf("%u", ((q->tail + i) % q->capacity));
        }
    }
    return;
}
