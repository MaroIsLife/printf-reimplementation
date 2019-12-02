#include "printf.h"

int printspace_s(va_list args,int h)
{
    int o;
    char *s;
    int c;
    int n;


    s = va_arg(args,char *);
    c = ft_strlen(s);
    o = 0;
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
    o = 0;
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
    c = 1;
    o = 0;
    while(c < h)
    {
        ft_putchar(' ');
        o++;
        c++;
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
    int n;


    s = va_arg(args,unsigned int);
    c = count(s);
    o = 0;
    while (c < h)
    {
        ft_putchar(' ');
        o++;
        c++;
    }
    c = o + ft_putnbr(s);
    return (c);
}

int printspace_x(va_list args,int h)
{
    int o;
    int s;
    int c;
    int n;
    char *buff;
    char *af; 
    
    s = va_arg(args,int);
    c = count(s) - 1;
    o = 0;
    while (c < h)
    {
        ft_putchar(' ');
        o++;
        c++;
    }
    c = o + ft_hexa(s);
    return (c);
}

int printspace_X(va_list args,int h)
{
    int o;
    int s;
    int c;
    int n;
    char *buff;
    char *af; 
    
    s = va_arg(args,int);
    c = count(s) - 1;
    o = 0;
    while (c < h)
    {
        ft_putchar(' ');
        o++;
        c++;
    }
    c = o + ft_heXa(s);
    return (c);
}

int printspace_p(va_list args,int h)
{
    int o;
    int s;
    int c;
    int n;
    char *buff;
    char *af; 
    
    s = va_arg(args,int);
    c = count(s) - 1;
    o = 0;
    while (c < h)
    {
        ft_putchar(' ');
        o++;
        c++;
    }
    ft_putstr("0x")
    c = o + ft_hexa(s);
    return (c);
}
