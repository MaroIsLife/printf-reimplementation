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
    else if (num[n + 1] == 'X')
        c = c + printspace_X(args,h);
    else if (num[n + 1] == 'p')
        c = c + printspace_p(args,h);
    else if (num[n + 1] == 'u')
        c = c + printspace_u(args,h);


    return (c);
}

int dwhichspace(const char *num, va_list args,struct s_test st,int n)
{
    int c;

    c = 0;
   
    if (num[n + 1] == 'd')
        c = c + dprintspace_d(st,args);


    return (c);
}

int zwhichspace(const char *num,int n,va_list args,int h)
{
    int c;

    c = 0;
    if (num[n + 1] == 's')
        c = c + zprintspace_s(args,h);
    else if (num[n + 1] == 'd')
        c = c + zprintspace_d(args,h);
    else if (num[n + 1] == 'c')
        c = c + zprintspace_c(args,h);
    else if (num[n + 1] == 'x')
        c = c + zprintspace_x(args,h);
    else if (num[n + 1] == 'X')
        c = c + zprintspace_X(args,h);
    else if (num[n + 1] == 'p')
        c = c + zprintspace_p(args,h);
    else if (num[n + 1] == 'u')
        c = c + zprintspace_u(args,h);


    return (c);
}

int mwhichspace(const char *num,int n,va_list args,int h)
{
    int c;

    c = 0;
    if (num[n + 1] == 's')
        c = c + mprintspace_s(args,h);
    else if (num[n + 1] == 'd')
        c = c + mprintspace_d(args,h);
    else if (num[n + 1] == 'c')
        c = c + mprintspace_c(args,h);
    else if (num[n + 1] == 'x')
        c = c + mprintspace_x(args,h);
    else if (num[n + 1] == 'X')
        c = c + mprintspace_X(args,h);
    else if (num[n + 1] == 'p')
        c = c + mprintspace_p(args,h);
    else if (num[n + 1] == 'u')
        c = c + mprintspace_u(args,h);


    return (c);
}