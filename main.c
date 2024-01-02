#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "cmodules/print.h"
#include "cmodules/sleep.h"
#include "cmodules/stack.h"
#include "man.h"

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

void script_handler(FILE *file)
{
    while (1)
    {
        char command[8192];
        fgets(command, sizeof(command), file);
        if (compare(3, command, "add"))
            add(command);
        if (compare(5, command, "sleep"))
            sleep_(command);
        if (compare(5, command, "print"))
            print(command);
        if (compare(4, command, "exit"))
            return;
        if (compare(3, command, "man"))
            man(command);
        if (compare(5, command, "reset"))
            reset();
        if (compare(9, command, "substract"))
            substract(command);
        if (compare(3, command, "run"))
        {
            FILE *file2;
            char filename[128] = "bin/";
            int j = 4;
            for (int i = 4; command[i] != '\n'; i++)
            {
                filename[j] = command[i];
                j++;
            }    
            file2 = fopen(filename, "r");
            if (file2 == NULL)
            {
                    printf("Unable to open!\n"); return;
            }
            script_handler(file2);
            fclose(file2);
        } 
    }
}

void keyboard_handler()
{
    fgets(input, sizeof(char) * 8192, stdin);
    if (compare(4, input, "exit"))
        exit(0);
    
    if (compare(5, input, "print"))
        print(input);
    if (compare(5, input, "sleep"))
        sleep_(input);
    
    if (compare(3, input, "add"))
        add(input);

    if (compare(5, input, "reset"))
        reset();

    if (compare(3, input, "man"))
        man(input);
    if (compare(9, input, "substract"))
        substract(input);
    if (compare(3, input, "run"))
    {
        FILE *file;
        char filename[128] = "bin/";
        int j = 4;
        for (int i = 4; input[i] != '\n'; i++)
        {
            filename[j] = input[i];
            j++;
        }    
        file = fopen(filename, "r");
        if (file == NULL)
        {
            printf("Unable to open!\n"); return;
        }
        script_handler(file);
        fclose(file);
    }
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
        
