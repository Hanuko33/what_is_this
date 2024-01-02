#include <stdio.h>
#include <stdlib.h>
#include "cmodules/print.h"
#include "man.h"

extern int compare(int size, const char *a, const char *b);

void man_sleep()
{
    printf("sleep\n usage: sleep [time]\n");
    printf(" time - milliseconds\n");
}

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
    print("print -p substract\n");
    print("print -p  usage: substract [index]\n");
    print("print -p  index - place in memory to decrement\n");
}

void man_man()
{
    print("print -p man\n usage: man [-h/-l] or [entry]\n entry - manual\n -h - print help\n -l - list all manuals\n");
}

void man(const char * input)
{
    int j=0;
    char * cmd = malloc(sizeof(char) * 10);

    for (int i = 0; i<10; i++)
    {
        cmd[i] = '\0';
    }

    for (int i = 4; input[i] != ' '; i++)
    {
        cmd[j] = input[i];
        j++;
    }

    if (input[5] == '\0')
    {
        man_man();
    }

    if (input[4] == '-')
    {
        if (input[5] == 'h')
        {
            man_man();
        }

        if (input[5] == 'l')
        {
            printf("man\n");
            printf("add\n");
            printf("print\n");
            printf("substract\n");
        }
    }


    if (compare(5, cmd, "print"))
        man_print();

    if (compare(3, cmd, "man"))
        man_man();
    if (compare(9, cmd, "substract"))
        man_substract();
    if (compare(3, cmd, "add"))
        man_add();

    free(cmd);
    cmd = NULL;
}
