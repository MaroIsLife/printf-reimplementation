#include "printf.h"

int print_s(va_list args, int *i)
{
    char *s;
    int c;

    s = va_arg(args,char *);
    c = ft_putstr(s);
    *i = *i + 1;
    return (c);
}

int print_d(va_list args, int *i)
{
    int s;
    int c;

    s = va_arg(args,int);
    c = ft_putnbr(s);
    *i = *i + 1;
    return (c);
}

int print_c(va_list args, int *i)
{
    int s;
    int c;

    s = va_arg(args,int);
    ft_putchar(s);
    c = 1;
    *i = *i + 1;
    return (c);
}

int print_u(va_list args, int *i)
{
    unsigned int s;
    int c;

    s = va_arg(args,unsigned int);
    c = ft_putunsigned(s);
    *i = *i + 1;
    return (c);
}

int print_x(va_list args, int *i)
{
    int c;
    int a;
    char *buff;
    char *af; 
    
    af = "0123456789abcdef"; 
    c = 0;
    buff = calloc(20,1);
    a = va_arg(args,int);
    while (a != 0)
    {
        buff[c] = af[a % 16];
        a = a / 16;
        c++;
    }
    c = ft_putstr(ft_strrev(buff));
    free(buff);
    *i = *i + 1;
    return (c);
}
