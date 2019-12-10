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
    ft_putnbr(s);

    return (0);
}
