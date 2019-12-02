#include "printf.h"

int whichspace(const char *num,int n,va_list args,int h)
{
    int c;

    c = 0;
    if (num[n + 1] == 's')
    {
        c = c + printspace_s(args,h);
    }

    return (c);
}