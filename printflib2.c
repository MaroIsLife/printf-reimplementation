#include "printf.h"

int print_X(va_list args, int *i ,const char *num)
{
    int c;
    int a;
    char *buff;
    char *af; 
    
    af = "0123456789ABCDEF"; 
    c = 0;
    buff = calloc(20,1);
    a = va_arg(args,int);
    while (a != 0)
    {
        a = a / 16;
        buff[c] = af[a % 16];
        c++;
    }
    c = ft_putstr(ft_strrev(buff));
    free(buff);
    a = *i;
    *i = *i + 1 + mcounter2(num,a + 1) + zcounter2(num,a + 1);;
    return (c);
}

int print_p(va_list args, int *i ,const char *num)
{
    int c;
    unsigned long a;
    unsigned long b;
    char *buff;
    char *af; 
    
    af = "0123456789abcdef"; 
    c = 0;
    buff = calloc(20,1);
    a = va_arg(args,unsigned long);
    if (a == 0)
    buff[0] = '0';
    while (a != 0)
    {
        b = a % 16;
        buff[c] = af[b];
        a = a / 16;
        c++;
    }
    c = ft_putstr("0x");
    c = c + ft_putstr(ft_strrev(buff));
    free(buff);
    a = *i;
    *i = *i + 1 + mcounter2(num,a + 1) + zcounter2(num,a + 1);;
    return (c);
}

int print_perc(int *i)
{
    int c;

    ft_putchar('%');
    c = 1;
    *i = *i + 1;

    return (c);
}

int print_n(const char *num,int *i)
{
    int c;

    ft_putchar(num[*i]);
    c = 1;
    return (c);
}