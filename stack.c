//From assigment Document 3
#include "stack.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Stack {
    uint32_t top;
    uint32_t capacity;
    int64_t *items;
} Stack;

Stack *stack_create(uint32_t capacity) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    if (s) {
        s->top = 0;
        s->capacity = capacity;
        s->items = (int64_t *) calloc(capacity, sizeof(int64_t));
        if (!s->items) {
            free(s);
            s = NULL;
        }
    }
    return s;
}

void stack_delete(Stack **s) {
    assert(*s);
    if ((*s)->items) {
        free((*s)->items);
        free((*s));
        *s = NULL;
    }
    return;
}
bool stack_full(Stack *s) {
    assert(s);
    if (s->top - 1 == s->capacity) {
        return true;
    }
    return false;
}

bool stack_empty(Stack *s) {
    assert(s);
    if (s->top == 0) {
        return true;
    }
    return false;
}

uint32_t stack_size(Stack *s) {
    return s->top;
}

bool stack_push(Stack *s, int64_t x) {
    assert(s);
    if (!stack_full(s)) {
        s->items[s->top] = x;
        s->top += 1;
        return true;
    }
    return false;
}

bool stack_pop(Stack *s, int64_t *x) {
    if (s && !stack_empty(s)) {
        s->top -= 1;
        *x = s->items[s->top];
        return true;
    }
    return false;
}

void stack_print(Stack *s) {
    for (uint32_t i = 0; i < s->top; i++) {
        printf("%ld \t", s->items[i]);
    }
    printf("\n");
}
