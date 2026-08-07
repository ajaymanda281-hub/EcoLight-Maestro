#include "types.h"

void delayus(unsigned int us)
{
    unsigned int i, j;
    for(i = 0; i < us; i++)
        for(j = 0; j < 10; j++);
}

void delayms(unsigned int ms)
{
    while(ms--)
    {
        delayus(1000);
    }
}