#ifndef __STATS_H__
#define __STATS_H__

#include <stdint.h>

uint64_t get_moves();
uint64_t get_compares();

void set_zero_moves();
void set_zero_compares();
void stats_zeros();
void moved();
void compared();
uint32_t compare(uint32_t x);
void count_stack(uint32_t x);
void count_queue(uint32_t x);
void print_stack_size();
void print_queue_size();

void print_stats(uint32_t e);
#endif
