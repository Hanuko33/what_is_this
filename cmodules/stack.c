#include "stack.h"
#include "../man.h"

int stack[STACKSIZE];

void substract(const char *input)
{
        int x;

        if (sscanf(input, "substract %d", &x))
        {
            if (x < STACKSIZE)
            {
                stack[x]--;
            }   
            else
            {
                printf("ERROR: index: %d limit: %d\n", x, STACKSIZE);
            }
        }
        else
        {
            man_substract();
        }
}

void add(const char *input)
{
        int x;

        if (sscanf(input, "add %d", &x))
        {
            if (x < STACKSIZE)
            {
                stack[x]++;
            }   
            else
            {
                printf("ERROR: index: %d limit: %d\n", x, STACKSIZE);
            }
        }
        else
        {
            man_add();
        }
}
