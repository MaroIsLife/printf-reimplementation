#include "printf.h"

//int whichspace()

int convcounter(const char *num,int z)
{   int n;
    int a;
    a = z;
    n = 0;
    while (num[a] != 'd' && num[a] != 's' && num[a] != 'i' && num[a] != 'u' && num[a] != 'p' && num[a] != 'x' && num[a] != 'X' && num[a] != '%' && num[a] != 'c')
    {
        n++;
        a++;
    }
    return (n);
    
}

int ncounter(const char *num,int z)
{   
    int a;
    a = 0;
    while (num[z] >= '1' && num[z] <= '9')
    {
        z++;
        a++;
    }
    return (a);
}

int printspace_s(va_list args,int h)
{
    int o;
    char *s;
    int c;
    int n;


    s = va_arg(args,char *);
    c = ft_strlen(s);
    while (c < h)
    {
        ft_putchar(' ');
        o++;
        c++;
    }
    c = o + ft_putstr(s);
    return (c);
}


int whichspace(const char *num,int n,va_list args,int h)
{
    int c;

    c = 0;
    if (num[n + 1] == 's')
    {
        c = c + printspace_s(args,h);
    }

    return (c);
}

int printspace(va_list args,int *i,const char *num)
{
    int h;
    int n;
    char *s;
    int z;

    z = *i + 1;
    n = convcounter(num,z);
    s = ft_substr(num,z,n);
    h = ft_atoi(s);

    h = whichspace(num,n,args,h);

    *i = *i + ncounter(num,z) + 1;

    return (h);
}

int ft_checkstring(const char *num, va_list args)
{
    int i;
    int c;
    int n;

    i = -1;

    while (num[++i] != '\0')
    {
        if (num[i] == '%' && num[i + 1] == 's')
            c = c + print_s(args,&i);
        else if (num[i] == '%' && num[i + 1] == 'd')
            c = c + print_d(args,&i);
        else if (num[i] == '%' && (num[i + 1] >= '1' && num[i + 1] <= '9'))
            c = c + printspace(args,&i,num);
        else if (num[i] == '%' && num[i + 1] == 'c')
            c = c + print_c(args,&i);
        else if (num[i] == '%' && num[i + 1] == 'x')
            c = c + print_x(args,&i);
        else if (num[i] == '%' && num[i + 1] == 'X')
            c = c + print_X(args,&i);
        else if (num[i] == '%' && num[i + 1] == 'u')
            c = c + print_u(args,&i);
        else if (num[i] == '%' && num[i + 1] == 'p')
            c = c + print_p(args,&i);
        else if (num[i] == '%' && num[i + 1] == '%')
            c = c + print_perc(&i);
        else
        c = c + print_n(num,&i);
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

    char *s = "Hello";
    int a;

    a = ft_printf("%7s\n",s);
    ft_printf("%d",a);

    return(0);
}