#ifndef SLIDE_LINE
#define SLIDE_LINE

#include <stdlib.h>
#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1
void slide_right(int *line, size_t size);
void slide_left(int *line, size_t size);
int slide_line(int *line, size_t size, int direction);

#endif
