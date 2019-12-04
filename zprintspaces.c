#include "printf.h"

int zprintspace_s(va_list args,int h)
{
    int o;
    char *s;
    int c;


    s = va_arg(args,char *);
    c = ft_strlen(s);
    c = h - c;
    if (s < 0)
    o = 1;
    else
    o = 0;
    while (o < c)
    {
        ft_putchar('0');
        o++;
    }
    c = o + ft_putstr(s);
    return (c);
}

int zprintspace_d(va_list args,int h)
{
    int o;
    int s;
    int c;


    s = va_arg(args,int);
    c = count(s);
    c = h - c;
    if (s < 0)
    {
        o = 1;
        ft_putchar('-');
    }
    else
    o = 0;
    while (o < c)
    {
        ft_putchar('0');
        o++;
    }
    c = o + zft_putnbr(s);
    return (c);
}

int zprintspace_c(va_list args,int h)
{
    int o;
    int s;
    int c;


    s = va_arg(args,int);
    c = 1;
    c = h - c;
    if (s < 0)
    o = 1;
    else
    o = 0;
    while(o < c)
    {
        ft_putchar('0');
        o++;
    }
    ft_putchar(s);
    c = 1 + o;
    return (c);
}

int zprintspace_u(va_list args,int h)
{
    int o;
    unsigned int s;
    int c;


    s = va_arg(args,unsigned int);
    c = count(s);
    c = h - c;
    o = 0;
    while (o < c)
    {
        ft_putchar('0');
        o++;
    }
    c = o + ft_putnbr(s);
    return (c);
}

int zprintspace_x(va_list args,int h)
{
    int o;
    int s;
    int c;
    
    s = va_arg(args,int);
    c = count(s) - 1;
    c = h - c;
    o = 0;
    while (o < c)
    {
        ft_putchar('0');
        o++;
    }
    c = o + ft_hexa(s);
    return (c);
}

int zprintspace_X(va_list args,int h)
{
    int o;
    int s;
    int c;
    
    s = va_arg(args,int);
    c = count(s) - 1;
    c = h - c;
    o = 0;
    while (o < c)
    {
        ft_putchar('0');
        o++;
    }
    c = o + ft_heXa(s);
    return (c);
}

int zprintspace_p(va_list args,int h)
{
    int o;
    unsigned long s;
    int c;
    
    s = va_arg(args,unsigned long);
    if (s == 0)
    c = 3;
    else
    c = 11;
    c = h - c;
    o = 0;
    while (o < c)
    {
        ft_putchar('0');
        o++;
    }
    ft_putstr("0x");
    c = o + ft_adr(s) + 2;
    return (c);
}