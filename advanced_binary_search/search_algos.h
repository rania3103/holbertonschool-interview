#ifndef ADVANCED_BINARY_SEARCH
#define ADVANCED_BINARY_SEARCH
#include <stdlib.h>
#include <stdio.h>
void print_values_searched(int *array, size_t left, size_t right);
int rec_advanced_binary(int *array, size_t left, size_t right, int value);
int advanced_binary(int *array, size_t size, int value);
#endif
