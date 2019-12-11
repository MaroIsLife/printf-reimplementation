#include "printf.h"

int g_r;

int aprintspace(va_list args,int *i,const char *num)
{
    int h;
    int n;
    int z;

    z = *i + 1;
    h = va_arg(args,int);
    n = *i + convcounter(num,z);
    if (h < 0)
    {
        *i = *i + mcounter2(num,z) + acounter(num,z) + 1;
        h = mwhichspace(num,n,args,h);
    }
    else if (num[z] == '0')
    {
        *i = *i + zcounter2(num,z) + acounter(num,z) + 1;
        h = zwhichspace(num,n,args,h);
    }
    else if (num[z] == '-')
    {
         *i = *i + mcounter2(num,z) + acounter(num,z) + 1;
        h = mwhichspace(num,n,args,h);
    }
    else
    {
        *i = *i + acounter(num,z) + 1;
        h = whichspace(num,n,args,h);
    }
    return (h);
}

int printspace(va_list args,int *i,const char *num)
{
    int h;
    int n;
    char *s;
    int z;

    z = *i + 1;
    n = *i + convcounter(num,z); // ADDED *i + CHECK OTHER
    s = ft_substr(num,z,n);
    h = ft_atoi(s);
    if (num[z] == '0')
    {
        *i = *i + zcounter2(num,z) + count(h) + 1;
        h = zwhichspace(num,n,args,h);
    }
    else if (num[z] == '-')
    {
        *i = *i + mcounter2(num,z) + count(h) + 1;
        h = mwhichspace(num,n,args,h);
    }
    else
    {
        //*i = *i + count(h) + 1;
        *i = *i + n + 1;
        h = whichspace(num,n,args,h);
    }
    return (h);
}

int dprintspace(va_list args,int *i,const char *num)
{
    int h;
    int n;
    int z;
    int b;
    char *s1;
    char *s2;
    int h2;
    struct s_test st;

    z = *i + 1;
    n = *i + dotcounter(num,z);
    st.s1 = ft_substr(num,z,n);
    b = ncounter(num,z) + 1;
    n = *i + convcounter(num,b);
    st.s2 = ft_substr(num,b,n);
    st.h1 = ft_atoi(st.s1);
    st.h2 = ft_atoi(st.s2);
    n = *i + dotcounter(num,z) + convcounter(num,b);

    dwhichspace(num,args,st,n);
    
    z = convcounter(num,z);
    *i = *i + z + 1;

    return (0);
}


int ft_checkstring(const char *num, va_list args)
{
    int i;
    int c;
    int n;
    int b;
    int k;

    i = -1;

    while (num[++i] != '\0')
    {
        n = zcounter(num,i + 1);
        k = mcounter(num,i + 1);
        b = ncounter(num,i + 1);
        if (num[i] == '%' && num[i + k + 1 + n] == 's')
            c = c + print_s(args,&i,num);
        else if (num[i] == '%' && num[i + k + 1 + n] == 'd')
            c = c + print_d(args,&i,num);
        else if (num[i] == '%' && num[i + 1] == '.')
            dprintspace(args,&i,num);
        else if (num[i] == '%' && (num[i + 1] >= '1' && num[i + 1] <= '9') && num[i + b + 1] == '.')
            dprintspace(args,&i,num);
        else if (num[i] == '%' && (num[i + 1] >= '1' && num[i + 1] <= '9'))
            c = c + printspace(args,&i,num);
        else if (num[i] == '%' && (num[i + 1] == '*'))
            c = c + aprintspace(args,&i,num);
        else if (num[i] == '%' && (num[i + n] == '0' && num[i + n + 1] == '*'))
            c = c + aprintspace(args,&i,num);
        else if (num[i] == '%' && (num[i + 1] == '0' && (num[i + n + 1] >= '1' && num[i + n + 1] <= '9')))
            c = c + printspace(args,&i,num);
        else if (num[i] == '%' && (num[i + 1] == '-' && num[i + k + 1] == '*'))
            c = c + aprintspace(args,&i,num);
        else if (num[i] == '%' && (num[i + 1] == '-' && (num[i + k + 1] >= '1' && num[i + k + 1] <= '9')))
            c = c + printspace(args,&i,num);
        else if (num[i] == '%' && num[i + k + 1 + n] == 'c')
            c = c + print_c(args,&i,num);
        else if (num[i] == '%' && num[i + k + 1 + n] == 'x')
            c = c + print_x(args,&i,num);
        else if (num[i] == '%' && num[i + k + 1 + n] == 'X')
            c = c + print_X(args,&i ,num);
        else if (num[i] == '%' && num[i + k + 1 + n] == 'u')
            c = c + print_u(args,&i,num);
        else if (num[i] == '%' && num[i + k + 1 + n] == 'p')
                print_p(args,&i,num);
        else if (num[i] == '%' && num[i + 1] == '%')
                print_perc(&i);
        else
            print_n(num,&i);
    }
    return (c);

}

int ft_printf(const char *num, ...)
{
    va_list args;
    int c;
    g_r = 0;

    va_start(args,num);
    c = ft_checkstring(num,args);
    va_end(args);
    return (g_r);
}

int	main()
{
   //Precision D with Negative Argument.
   // Work Precision S NULL.
   char *s = "Haa";

   //Right = 0;
    //Left = Space
    int a;

   printf("%4.d\n",-123);



	

	return (0);
}