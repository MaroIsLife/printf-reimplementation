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
    while (num[z + 1] >= '1' && num[z + 1] <= '9')
    {
        z++;
        a++;
    }
    return (a);
}

int zcounter(const char *num,int i)
{
    int o;
    o = 0;
    while (num[i] == '0')
    {
        o++;
        i++;
    }
    return (o);

}

int mcounter(const char *num,int i)
{
    int o;
    o = 0;
    while (num[i] == '-')
    {
        o++;
        i++;
    }
    return (o);

}

int acounter(const char *num,int i)
{
    int o;
    o = 0;
    while (num[i] == '*')
    {
        o++;
        i++;
    }
    return (o);

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
    if (num[z] == '0')
    {
        h = zwhichspace(num,n,args,h);
        *i = *i + zcounter(num,z) + ncounter(num,z) + 1;
    }
    else if (num[z] == '-')
    {
        h = mwhichspace(num,n,args,h);
        *i = *i + mcounter(num,z) + ncounter(num,z) + 1;
    }
    else
    {
        h = whichspace(num,n,args,h);
        *i = *i + ncounter(num,z) + 2;
    }
    return (h);
}
int aprintspace(va_list args,int *i,const char *num)
{
    int h;
    int n;
    char *s;
    int z;

    z = *i + 1;
    h = va_arg(args,int);
    n = convcounter(num,z);
    if (num[z] == '0')
    {
        h = zwhichspace(num,n,args,h);
        *i = *i + zcounter(num,z) + ncounter(num,z) + 1;
    }
    else if (num[z] == '-')
    {
        h = mwhichspace(num,n,args,h);
        *i = *i + mcounter(num,z) + ncounter(num,z) + acounter(num,z) + 1;
    }
    else
    {
        h = whichspace(num,n,args,h);
        *i = *i + ncounter(num,z) + 2;
    }
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
        n = zcounter(num,i);
        if (num[i] == '%' && num[i + 1] == 's')
            c = c + print_s(args,&i);
        else if (num[i] == '%' && num[i + 1] == 'd')
            c = c + print_d(args,&i);
        else if (num[i] == '%' && (num[i + 1] >= '1' && num[i + 1] <= '9'))
            c = c + printspace(args,&i,num);
        else if (num[i] == '%' && (num[i + 1 + n] == '*'))
            c = c + aprintspace(args,&i,num);
        else if (num[i] == '%' && (num[i + 1 + n] == '-' && num[i + 2 + n] == '*'))
            c = c + aprintspace(args,&i,num);
        else if (num[i] == '%' && (num[i + 1 + n] == '-'))
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

    char *s = "H";
    int a;

 
    a = ft_printf("%-*d\n",4,11);
    printf("%d",a);

    return(0);
}