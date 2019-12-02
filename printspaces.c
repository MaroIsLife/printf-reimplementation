#include "printf.h"

int printspace_s(va_list args,int h)
{
    int o;
    char *s;
    int c;
    int n;


    s = va_arg(args,char *);
    c = ft_strlen(s);
    while (c < h)
    {
        ft_putchar(' ');
        o++;
        c++;
    }
    c = o + ft_putstr(s);
    return (c);
}

int printspace_d(va_list args,int h)
{
    int o;
    int s;
    int c;
    int n;


    s = va_arg(args,int);
    c = count(s);
    while (c < h)
    {
        ft_putchar(' ');
        o++;
        c++;
    }
    c = o + ft_putnbr(s);
    return (c);
}

int printspace_c(va_list args,int h)
{
    int o;
    int s;
    int c;
    int n;


    s = va_arg(args,int);
    c = 1
    while (c < h)
    {
        ft_putchar(' ');
        o++;
        c++;
    }
    c = o + ft_putchar(s);
    return (c);
}

int printspace_c(va_list args,int h)
{
    int o;
    unsigned int s;
    int c;
    int n;


    s = va_arg(args,unsigned int);
    c = count(s);
    while (c < h)
    {
        ft_putchar(' ');
        o++;
        c++;
    }
    c = o + ft_putnbr(s);
    return (c);
}
