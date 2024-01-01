#include "print.h"

extern void print_stack();

void print(const char * input)
{
        if (input[6] == '-')
        {
            if (input[7] == 's')
            {
                print_stack();
            }
            else if (input[7] == 'h')
            {
                printf("print\n usage: print -[h/s/p] ...\n");
                printf(" h - help message\n s - print stack\n p - print + endl\n");
            }
            else if (input[7] == 'p')
            {
                for (int i = 9; input[i] != '\0'; i++)
                {
                    printf("%c", input[i]);
                }
            }
            else 
            {
                printf("print\n usage: print -[h/s/p] ...\n");
                printf(" h - help message\n s - print stack\n p - print + endl\n");
            }
        } 
        else
        {
                printf("print\n usage: print -[h/s/p] ...\n");
                printf(" h - help message\n s - print stack\n p - print + endl\n");
        }
}
