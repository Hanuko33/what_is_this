#ifndef ADD_H
#define ADD_H

#define STACKSIZE 1024

#include <stdio.h>
#include <stdlib.h>

void add(const char *input);
void substract(const char *input);
extern int stack[STACKSIZE];

#endif
