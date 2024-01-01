#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "cmodules/print.h"
#include "cmodules/stack.h"
#include "cmodules/run.h"

#define MAXFILES 256

char * input;

void print_stack()
{
    for (int i = 0; i < STACKSIZE; i++)
    {
        printf("%d " , stack[i]);
    }
    printf("\n");
}

int compare(int size, const char *a, const char *b)
{
    for (int i = 0; i < size; i++)
    {
        if (!(a[i]==b[i]))
        return 0;
    }
    return 1;
}

void reset()
{
    for (int i = 0; i < STACKSIZE; i++)
    {
        stack[i] = 0;
    } 
}

void keyboard_handler()
{
    fgets(input, sizeof(char) * 8192, stdin);
    if (compare(4, input, "exit"))
        exit(0);
    
    if (compare(5, input, "print"))
        print(input);
    
    if (compare(3, input, "add"))
        add(input);

    if (compare(5, input, "reset"))
        reset();

    if (compare(9, input, "substract"))
        substract(input);
    if (compare(3, input, "run"))
        run(input);
}



int main()
{
    input = malloc(sizeof(char) * 8192);
    reset();

    for (;;)
    {
        printf("> ");
        fflush(stdout);    
        keyboard_handler();
    }
   

    free(input);
    return 0;
}
        
