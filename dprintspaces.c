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
    else
    c = st.h1 - st.h2;
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
    //if (s == 0 && st.h2 == 0)
    //ft_putchar(' ');
    //else
    if (s != 0)
    zft_putnbr(s);
    return (0);
}

int wordputter(int b,char *s)
{
    int o;
    int a;

    a = ft_strlen(s);
    o = 0; 
    if (a == 0)
    return (o);
    else
    {
        while (o < b && s[o] != '\0')
        {
            ft_putchar(s[o]);
            o++;
        }
    }
    return (o);
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