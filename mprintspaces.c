#include "printf.h"

int mprintspace_s(va_list args,int h)
{
    int o;
    char *s;
    int c;


    s = va_arg(args,char *);
    if (s == NULL)
        c = 6;
    else
    c = ft_strlen(s);
    if (h < 0)
    h = h * - 1;
    c = h - c;
    if (s < 0)
    o = 1;
    else
    o = 0;
    if (s != NULL)
    ft_putstr(s);
    else
    ft_putstr("(null)");
    while (o < c)
    {
        ft_putchar(' ');
        o++;
    }
    return (c);
}

int mprintspace_d(va_list args,int h)
{
    int o;
    int s;
    int c;


    s = va_arg(args,int);
    c = count(s);
    if (h < 0)
    h = h * - 1;
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
    if (h < 0)
    h = h * - 1;
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
    ft_putunsigned(s);
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
    unsigned int s;
    int c;
    int k;
    
    s = va_arg(args,unsigned int);
    c = count(s) - 1;
    if (h < 0)
    h = h * - 1;
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
    unsigned int s;
    int c;
    int k; 
    
    s = va_arg(args,unsigned int);
    c = count(s) - 1;
    if (h < 0)
    h = h * - 1;
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
    c = count(s) + 1;
    if (h < 0)
    h = h * - 1;
    c = h - c;
    o = 0;
    ft_putstr("0x");
    k = ft_adr(s);
    while (o < c)
    {
        ft_putchar(' ');
        o++;
    }
    c = o + k + 2;
    return (c);
}

int mprintspace_pp(int h)
{
    int o;
    int c;


    if (h < 0)
    h = h * - 1;
    c = 1;
    c = h - c;
    o = 0;
    ft_putchar('%');
    while(o < c)
    {
        ft_putchar(' ');
        o++;
    }
    c = 1 + o;
    return (c);
}