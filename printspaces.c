#include "printf.h"

int printspace_s(va_list args,int h)
{
    int o;
    char *s;
    int c;


    s = va_arg(args,char *);
    if (s == NULL)
        c = 6;
    else
    c = ft_strlen(s);
    c = h - c;
    if (s < 0)
    o = 1;
    else
    o = 0;
    while (o < c)
    {
        ft_putchar(' ');
        o++;
    }
    if (s != NULL)
    c = o + ft_putstr(s);
    else
    c = ft_putstr("(null)");
    return (c);
}

int printspace_d(va_list args,int h)
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
    while (o < c)
    {
        ft_putchar(' ');
        o++;
    }
    c = o + ft_putnbr(s);
    return (c);
}

int printspace_c(va_list args,int h)
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
        ft_putchar(' ');
        o++;
    }
    ft_putchar(s);
    c = 1 + o;
    return (c);
}

int printspace_u(va_list args,int h)
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
        ft_putchar(' ');
        o++;
    }
    c = ft_putunsigned(s);
    return (c);
}

int printspace_x(va_list args,int h)
{
    int o;
    unsigned int s;
    int k;
    int c;
    
    s = va_arg(args,unsigned int);
    k = s;
    if (k < 0)
    c = 8;
    else
    c = ct_hexa(s);
    c = h - c;
    o = 0;
    while (o < c)
    {
        ft_putchar(' ');
        o++;
    }
    c = o + ft_hexa(s);
    return (c);
}

int printspace_X(va_list args,int h)
{
    int o;
    unsigned int s;
    int c;
    int k;
    
    s = va_arg(args,unsigned int);
     k = s;
    if (k < 0)
    c = 8;
    else
    c = ct_hexa(s);
    c = h - c;
    o = 0;
    while (o < c)
    {
        ft_putchar(' ');
        o++;
    }
    c = o + ft_heXa(s);
    return (c);
}

int printspace_p(va_list args,int h)
{
    int o;
    unsigned long s;
    int c;
    
    s = va_arg(args,unsigned long);
    if (s == 0)
    c = 3;
    else
    c = count(s) + 1;
    c = h - c;
    o = 0;
    while (o < c)
    {
        ft_putchar(' ');
        o++;
    }
    ft_putstr("0x");
    c = o + ft_adr(s) + 2;
    return (c);
}
