#include "printf.h"

int whichspace(const char *num,int n,va_list args,int h)
{
    int c;

    c = 0;
    if (num[n + 1] == 's')
        c = c + printspace_s(args,h);
    else if (num[n + 1] == 'd')
        c = c + printspace_d(args,h);
    else if (num[n + 1] == 'c')
        c = c + printspace_c(args,h);
    else if (num[n + 1] == 'x')
        c = c + printspace_x(args,h);
    else if (num[n + 1] == 's')
        c = c + printspace_s(args,h);
    else if (num[n + 1] == 's')
        c = c + printspace_s(args,h);
    else if (num[n + 1] == 's')
        c = c + printspace_s(args,h);
    else if (num[n + 1] == 's')
        c = c + printspace_s(args,h);
    else if (num[n + 1] == 's')
        c = c + printspace_s(args,h);

    return (c);
}