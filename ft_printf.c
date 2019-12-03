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
int ncounter(const char *num,int z)
{   
    int a;
    int m;
    a = 0;
    while (num[z + 1] >= '1' && num[z + 1] <= '9')
    {
        z++;
        a++;
    }
    return (a);
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

int mcounter2(const char *num,int i)
{
    int o;
    o = 0;
    while (num[i] != 'd' && num[i] != 's' && num[i] != 'i' && num[i] != 'u' && num[i] != 'p' && num[i] != 'x' && num[i] != 'X' && num[i] != '%' && num[i] != 'c')
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
    while (num[i + 1] == '*' || num[i + 2] == '*')
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
        *i = *i + zcounter(num,z) + count(h) + 1;
        h = zwhichspace(num,n,args,h);
    }
    else if (num[z] == '-')
    {
        *i = *i + mcounter(num,z) + count(h) + 1;
        h = mwhichspace(num,n,args,h);
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
        *i = *i + zcounter(num,z) + count(h) + acounter(num,z) + 1;
        h = zwhichspace(num,n,args,h);
    }
    else if (num[z] == '-')
    {
         *i = *i + mcounter(num,z) + count(h) + acounter(num,z) + 1;
        h = mwhichspace(num,n,args,h);
    }
    else
    {
        *i = *i + count(h) + 2;
        h = whichspace(num,n,args,h);
    }
    return (h);
}

int ft_checkstring(const char *num, va_list args)
{
    int i;
    int c;
    int n;
    int k;

    i = -1;

    while (num[++i] != '\0')
    {
        n = zcounter(num,i + 1); // Add != 'd'
        k = mcounter(num,i + 1);
        if (num[i] == '%' && num[i + 1] == 's')
            c = c + print_s(args,&i);
        else if (num[i] == '%' && num[i + 1] == 'd')
            c = c + print_d(args,&i);
        else if (num[i] == '%' && (num[i + 1] >= '1' && num[i + 1] <= '9'))
            c = c + printspace(args,&i,num);
        else if (num[i] == '%' && (num[i + 1 + n] == '*'))
            c = c + aprintspace(args,&i,num);
        else if (num[i] == '%' && (num[i + 1 + n] == '0' && num[i + 2 + n] == '*'))
            c = c + aprintspace(args,&i,num);
        else if (num[i] == '%' && (num[i + n] == '0'))
            c = c + printspace(args,&i,num);
        else if (num[i] == '%' && (num[i + 1 + n] == '-' && num[i + 2 + n] == '*'))
            c = c + aprintspace(args,&i,num);
        else if (num[i] == '%' && (num[i + k] == '-'))
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

 
    a = ft_printf("%04dh\n",-11);
    printf("%d",a);

    return(0);
}