#include "printf.h"

int ft_checkstring(const char *num, va_list args)
{
    int i;
    int c;

    i = -1;

    while (num[++i] != '\0')
    {
        if (num[i] == '%' && num[i + 1] == 's')
            c = c + print_s(args,&i);
        else if (num[i] == '%' && num[i + 1] == 'd')
            c = c + print_d(args,&i);
        else if (num[i] == '%' && num[i + 1] == 'c')
            c = c + print_c(args,&i);
        else if (num[i] == '%' && num[i + 1] == 'x')
            c = c + print_x(args,&i);
        else if (num[i] == '%' && num[i + 1] == 'X')
            c = c + print_X(args,&i);
        else if (num[i] == '%' && num[i + 1] == 'u')
            c = c + print_u(args,&i);
        else if (num[i] == '%' && num[i + 1] == 'p')
            c = c + print_u(args,&i);
        else if (num[i] == '%' && num[i + 1] == '%')
            c = c + print_perc(&i);

    }
    return (c);

}

int ft_printf(const char *num, ...)
{
    va_list args;
    int c;

    va_start(args,num);
    c = ft_checkstring(num,args);
    va_end(args);
    return (c);
}

int main()
{
    ft_printf("Hello %s","maro");

    return(0);
}