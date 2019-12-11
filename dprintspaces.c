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
        c = st.h1 - count(s);
    else
    c = st.h1 - st.h2;
    if (s < 0)
    {
        o = 1;
    }
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
    zft_putnbr(s);

    return (0);
}

int wordputter(int b,char *s)
{
    int o;

    o = 0;
    while (o < b)
    {
        ft_putchar(s[o]);
        o++;
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
    if (st.h2 >= ft_strlen(s))
        c = st.h1 - ft_strlen(s);
    else
        c = st.h1 - st.h2;
    
    o = 0;
    while (o < c)
    {
        ft_putchar(' ');
        o++;
    }
    b = st.h2;
    if (s != NULL)
    wordputter(b,s);
    else 
    ft_putstr("(null)");
    return (0);
}