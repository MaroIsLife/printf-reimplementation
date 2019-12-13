#include "printf.h"

int dprintspace_d(struct s_test st,va_list args)
{
    int s;
    int c;
    int b;
    int o;

    s = va_arg(args,int);
    c = count(s);
    b = st.h2 - c;
    if (st.h2 == 0)
    {
        if (s == 0)
        c = st.h1;
        else
        c = st.h1 - count(s);
    }
    else if (st.h2 > count(s))
        c = st.h1 - st.h2;
    else
        c = st.h1 - count(s);
    if (s == 0)
        b = b + 1;
    if (s < 0)
        o = 1;
    else
    o = 0; 
    while (o < c)
    {
        ft_putchar(' ');
        o++;
    }
    if (s < 0)
    ft_putchar('-');
    o = 0;
    while (o < b)
    {
        ft_putchar('0');
        o++;
    }
    if (s != 0)
    zft_putnbr(s);
    return (0);
}


int dprintspace_s(struct s_test st,va_list args)
{
    char *s;
    int c;
    int b;
    int o;

    s = va_arg(args,char *);
    if (s == NULL)
    s = "(null)";
    b = ft_strlen(s);
    if (st.h2 >= b)
        c = st.h1 - b;
    else
        c = st.h1 - st.h2;
    
    o = 0;
    while (o < c)
    {
        ft_putchar(' ');
        o++;
    }
    b = st.h2;
    wordputter(b,s);
    return (0);
}

int dprintspace_u(struct s_test st,va_list args)
{

    unsigned int s;
    int c;
    int b;
    int o;

    s = va_arg(args,unsigned int);
    c = unsignedcount(s);
    b = st.h2 - c;
    if (st.h2 == 0)
    {
        if (s == 0)
        c = st.h1;
        else
        c = st.h1 - unsignedcount(s);
    }
    else if (st.h2 > unsignedcount(s))
        c = st.h1 - st.h2;
    else
        c = st.h1 - unsignedcount(s);
    if (s == 0)
        b = b + 1;
    o = 0; 
    while (o < c)
    {
        ft_putchar(' ');
        o++;
    }
    o = 0;
    while (o < b)
    {
        ft_putchar('0');
        o++;
    }
    if (s != 0)
    ft_putunsigned(s);
    return (0);
}
int dprintspace_c(struct s_test st,va_list args)
{
    int s;
    int c;
    int b;
    int o;

    s = va_arg(args,int);
    
    b = 1;
  
    c = st.h1 - 1;
    
    o = 0;
    while (o < c)
    {
        ft_putchar(' ');
        o++;
    }
    ft_putchar(s);
    return (0);
}

int dprintspace_x(struct s_test st,va_list args)
{
    unsigned int s;
    int c;
    int b;
    int o;

    s = va_arg(args,unsigned int);
    c = ct_hexa(s);
    b = st.h2 - c;
    if (st.h2 == 0)
    {
        if (s == 0)
        c = st.h1;
        else
        c = st.h1 - ct_hexa(s);
    }
    else if (st.h2 > ct_hexa(s))
        c = st.h1 - st.h2;
    else
        c = st.h1 - ct_hexa(s);
    if (s == 0)
        b = b + 1;
    o = 0; 
    while (o < c)
    {
        ft_putchar(' ');
        o++;
    }
    o = 0;
    while (o < b)
    {
        ft_putchar('0');
        o++;
    }
    if (s != 0)
    ft_hexa(s);
    return (0);
}

int dprintspace_X(struct s_test st,va_list args)
{
    unsigned int s;
    int c;
    int b;
    int o;

    s = va_arg(args,unsigned int);
    c = ct_hexa(s);
    b = st.h2 - c;
    if (st.h2 == 0)
    {
        if (s == 0)
        c = st.h1;
        else
        c = st.h1 - ct_hexa(s);
    }
    else if (st.h2 > ct_hexa(s))
        c = st.h1 - st.h2;
    else
        c = st.h1 - ct_hexa(s);
    if (s == 0)
        b = b + 1;
    o = 0; 
    while (o < c)
    {
        ft_putchar(' ');
        o++;
    }
    o = 0;
    while (o < b)
    {
        ft_putchar('0');
        o++;
    }
    if (s != 0)
    ft_heXa(s);
    return (0);
}

int dprintspace_p(struct s_test st,va_list args)
{
    unsigned long s;
    int c;
    int o;

    s = va_arg(args,unsigned long);
    if (s == 0)
    c = ct_adr(s) + 1;
    else
    c = ct_adr(s) + 2;
    c = st.h1 - c;
    o = 0; 
    while (o < c)
    {
        ft_putchar(' ');
        o++;
    }
    ft_putstr("0x"); 
    if (s != 0)
        ft_adr(s);
    return (0);
}