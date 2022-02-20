#include "stats.h"

#include <stdio.h>

static uint64_t moves = 0;
static uint64_t compares = 0;
static uint32_t max_stack = 0;
static uint32_t max_queue = 0;

uint64_t get_moves() {
    return moves;
}
uint64_t get_compares() {
    return compares;
}

void set_zero_moves() {
    moves = 0;
    return;
}
void set_zero_compares() {
    compares = 0;
    return;
}
void stats_zeros() {
    set_zero_compares();
    set_zero_moves();
    max_queue = 0;
    max_stack = 0;
    return;
}

void moved() {
    moves += 1;
    return;
}
void compared() {
    compares += 1;
    return;
}
uint32_t compare(uint32_t x) {
    compares += 1;
    return x;
}
void count_stack(uint32_t x) {
    max_stack = x;
    return;
}
void count_queue(uint32_t x) {
    max_queue = x;
    return;
}
void print_stack_size() {
    printf("Max Stack: %u\n", max_stack);
    return;
}
void print_queue_size() {
    printf("Max Queue: %u\n", max_queue);
    return;
}

void print_stats(uint32_t e) {
    printf("%u elements, %lu moves, %lu compares\n", e, moves, compares);
    return;
}
