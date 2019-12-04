#include "printf.h"

int mprintspace_s(va_list args,int h)
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
    ft_putstr(s);
    while (o < c)
    {
        ft_putchar(' ');
        o++;
    }
    c = ft_strlen(s) + o;
    return (c);
}

int mprintspace_d(va_list args,int h)
{
    int o;
    int s;
    int c;


    s = va_arg(args,int);
    c = count(s);
    c = h - c;
    if (s < 0)
    o = 1;
    else
    o = 0;
    ft_putnbr(s);
    while (o < c)
    {
        ft_putchar(' ');
        o++;
    }
    c = o + count(s);
    return (c);
}

int mprintspace_c(va_list args,int h)
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
    ft_putchar(s);
    while(o < c)
    {
        ft_putchar(' ');
        o++;
    }
    c = 1 + o;
    return (c);
}

int mprintspace_u(va_list args,int h)
{
    int o;
    unsigned int s;
    int c;


    s = va_arg(args,unsigned int);
    c = count(s);
    c = h - c;
    o = 0;
    ft_putnbr(s);
    while (o < c)
    {
        ft_putchar(' ');
        o++;
    }
    c = o + count(s);
    return (c);
}

int mprintspace_x(va_list args,int h)
{
    int o;
    int s;
    int c;
    int k;
    
    s = va_arg(args,int);
    c = count(s) - 1;
    c = h - c;
    o = 0;
    k = ft_hexa(s);
    while (o < c)
    {
        ft_putchar(' ');
        o++;
    }
    c = o + k;
    return (c);
}

int mprintspace_X(va_list args,int h)
{
    int o;
    int s;
    int c;
    int k; 
    
    s = va_arg(args,int);
    c = count(s) - 1;
    c = h - c;
    o = 0;
    k = ft_heXa(s);
    while (o < c)
    {
        ft_putchar(' ');
        o++;
    }
    c = o + k;
    return (c);
}

int mprintspace_p(va_list args,int h)
{
    int o;
    unsigned long s;
    int c;
    char k; 
    
    s = va_arg(args,unsigned long);
    if (s == 0)
    c = 3;
    else
    c = 11;
    c = h - c;
    o = 0;
    k = ft_adr(s);
    while (o < c)
    {
        ft_putchar(' ');
        o++;
    }
    ft_putstr("0x");
    c = o + k + 2;
    return (c);
}