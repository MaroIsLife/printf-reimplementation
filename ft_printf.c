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
        *i = *i + count(h) + 1;
        h = whichspace(num,n,args,h);
    }
    return (h);
}

int dprintspace(va_list args,int *i,const char *num)
{
    int h;
    int n;
    int z;
    char *s1;
    char *s2;
    int h1;
    int h2;

    z = *i + 1;
    n = *i + dotcounter(num,z);
    s1 = ft_substr(num,z,n);
    n = *i + convcounter(num,z + 2);
    s2 = ft_substr(num,z + 2,n);
    h1 = atoi(s1);
    h2 = atoi(s2);

    *i = *i + count(h1) + count (h2) + 2;

    return (0);
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
        n = zcounter(num,i + 1);
        k = mcounter(num,i + 1);
        if (num[i] == '%' && num[i + k + 1 + n] == 's')
            c = c + print_s(args,&i,num);
        else if (num[i] == '%' && num[i + k + 1 + n] == 'd')
            c = c + print_d(args,&i,num);
        else if (num[i] == '%' && (num[i + 1] >= '1' && num[i + 1] <= '9') && num[i + 2] == '.')
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
            c = c + print_p(args,&i,num);
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
    g_r = 0;

    va_start(args,num);
    c = ft_checkstring(num,args);
    va_end(args);
    return (g_r);
}

int	main()
{
    // try * with normal width
    // NEgative argument in %*x or Printspaces
   char *s = "Haa";
   ft_printf("%012x",-102);

   


    //ft_printf("--%---4dh\n",'G');

	

	return (0);
}
  // try Yahya testes with 0*/
