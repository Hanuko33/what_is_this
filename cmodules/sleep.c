#include "sleep.h"
#include <stdio.h>
#include <unistd.h>
#include "../man.h"
void sleep_(const char *input)
{
    int sleeptime;
    if (sscanf((char *)input, "sleep %d", &sleeptime)==1)
    {
        sleeptime*=1000;
        usleep(sleeptime);
    }
    else
    {
        man_sleep();
    }
}
