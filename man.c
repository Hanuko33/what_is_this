#include <stdio.h>
#include "cmodules/print.h"
#include "man.h"

void man_print()
{
    printf("print\n usage: print -[h/s/p] ...\n");
    printf(" h - help message\n s - print stack\n p - print + endl\n");
}

void man_add()
{
    print("print -p add\n");
    print("print -p  usage: add [index]\n");
    print("print -p  index - place in memory to increment\n");
}

void man_substract()
{
    print("print -o substract\n");
    print("print -o  usage: substract [index]\n");
    print("print -o  index - place in memory to decrement\n");
}
