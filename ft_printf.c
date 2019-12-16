#include "printf.h"

int g_r;

int aprintspace(va_list args, int *i, const char *num)
{
    int h;
    int n;
    int z;

    z = *i + 1;
    h = va_arg(args,int);
    n = *i + convcounter(num,z);
    if (h < 0)
    {
        *i = *i + mcounter2(num,z) + acounter(num,z) + zcounter2(num,z) + 1;
        h = mwhichspace(num,n,args,h);
    }
    else if (num[z] == '0')
    {
        *i = *i + zcounter2(num,z) + acounter(num,z) + mcounter2(num,z) + 1;
        h = zwhichspace(num,n,args,h);
    }
    else if (num[z] == '-')
    {
         *i = *i + mcounter2(num,z) + acounter(num,z) + zcounter2(num,z) + 1;
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
    n = *i + convcounter(num,z);
    s = ft_substr(num,z,n);
    h = ft_atoi(s);
    free(s);
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

int numb_counter1(const char *num)
{ 
    struct s_test st2;
    int z;
    int b;
    int n;

    z = i + 1;
    n = i + dotcounter(num,z);
    st2.s1 = ft_substr(num,z,n);
    b = i + ncounter(num,z) + 1;
    n = i + convcounter(num,b);
    st2.s2 = ft_substr(num,b,n);
    st2.h1 = ft_atoi(st2.s1);
    st2.h2 = ft_atoi(st2.s2);
    free(st2.s1);
    free(st2.s2);

    return(st2.h1);
}

int numb_counter2(const char *num)
{ 
    struct s_test st2;
    int z;
    int b;
    int n;

    z = i + 1;
    n = i + dotcounter(num,z);
    st2.s1 = ft_substr(num,z,n);
    b = i + ncounter(num,z) + 1;
    n = i + convcounter(num,b);
    st2.s2 = ft_substr(num,b,n);
    st2.h1 = ft_atoi(st2.s1);
    st2.h2 = ft_atoi(st2.s2);
    free(st2.s1);
    free(st2.s2);

    return(st2.h2);
}

int dprintspace(va_list args,const char *num)
{
    int n;
    int z;
    int b;
    struct s_test st;
 
    z = i + 1;
    n = i + dotcounter(num,z);
    st.s1 = ft_substr(num,z,n);
    b = i + ncounter(num,z) + 1;
    n = i + convcounter(num,b);
    st.s2 = ft_substr(num,b,n);
    st.h1 = ft_atoi(st.s1);
    st.h2 = ft_atoi(st.s2);
    free(st.s1);
    free(st.s2);
    n = i + dotcounter(num,z) + convcounter(num,b);

    if (num[z] == '-')
        zdwhichspace(num,args,st,n);
    else
    dwhichspace(num,args,st,n);

    z = convcounter(num,z);
    i = i + z + 1;

    return (0);
}

int adprintspace(va_list args,const char *num)
{
    int n;
    int z;
    struct s_test st;
    
    z = i + 1;
    n = i + dotcounter(num,z);
    if (num[n] == '*' && num[n + 2] == '*')
    {
        st.h1 = va_arg(args,int);
        st.h2 = va_arg(args,int);
    }
    else if (num[n] == '*' && num[n + 2] != '*')
    {
        st.h1 = va_arg(args,int);
        st.h2 = numb_counter2(num);

    }
    else if (num[n] != '*' && num[n + 2] == '*')
    {
        st.h1 = numb_counter1(num);
        st.h2 = va_arg(args,int);
    }
    else if (num[n] != '*' && num[n + 2] != '*')
    {
        st.h1 = numb_counter1(num);
        st.h2 = numb_counter2(num);
    }
    if (st.h2 < 0 && num[n - 1] == '0')
    {
        if (st.h1 >= 0)
        {
            st.h2 = st.h1;
            st.h1 = 0;
        }
    }
    n = i + convcounter(num,z);

    if (st.h1 < 0)
    {
        st.h1 = st.h1 * -1;
        zdwhichspace(num,args,st,n);
    }
    /*else if (st.h2 < 0)
    {
        st.h2 = st.h2 * -1;
        zdwhichspace(num,args,st,n);
    }*/
    else if (num[z] == '-')
        zdwhichspace(num,args,st,n);
    else
    dwhichspace(num,args,st,n);

    z = convcounter(num,z);
    i = i + z + 1;

    return (0);

}

void  mehdiconv(va_list args,const char *num, char c)
{
     if (num[i] == '%' && c == 'c')
        print_c(args,num);
    else if (num[i] == '%' && c == 'x')
        print_x(args,num);
    else if (num[i] == '%' && c == 'X')
        print_X(args,num);
    else if (num[i] == '%' && c == 'u')
         print_u(args,num);
    else if (num[i] == '%' && c == 's')
        print_s(args,num);
    else if (num[i] == '%' && c == 'd')
        print_d(args,num);
    else if (num[i] == '%' && c == 'p')
            print_p(args,num);
    else if (num[i] == '%' && c == '%')
            print_perc(i);
    else
         print_n(num,&i);
    
}

void mehdiconv2(va_list args,const char *num)
{
    int n;
    int k;
    int b;
    int a;
        
        n = zcounter(num,i + 1);
        k = mcounter(num,i + 1);
        b = ncounter(num,i + 1);
        a = acounter2(num);


        if (num[i] == '%' && ((num[i + a] == '*' && num[i + a + 1] == '.') || (num[i + a] == '*' && num[i + a - 1] == '.')))
            adprintspace(args,num);
       else if (num[i] == '%' && num[i + n + k + 1] >= '1' && num[i + n + k + 1] <= '9' && num[i + k + b] == '.')
            adprintspace(args,num);
        else if ((num[i] == '%' && num[i + n + 1] == '.') || (num[i] == '%' && num[i + 1] == '0' && (num[i + 2] >= '1' && num[i + 2] <= '9') && num[i + 3] == '.'))
            dprintspace(args,num);
        else if (num[i] == '%' && (num[i + n + 1] >= '1' && num[i + n + 1] <= '9') && num[i + b + 1] == '.')
            dprintspace(args,num);
        else if (num[i] == '%' && num[i + n + 1] == '-' && num[i + b + 1] == '.')
            dprintspace(args,num);
         else if (num[i] == '%' && num[i + n + k] == '-' && (num[i + n + k + 1] >= '1' && num[i + n + k + 1] <= '9') && num[i + b + 1] == '.')
            dprintspace(args,num);

}


int ft_checkstring(const char *num, va_list args)
{
    int n;
    int b;
    int a;
    int k;


    i = -1;

    while (num[++i] != '\0')
    {
        n = zcounter(num,i + 1); // If n Is still useful cause 0 is already checked in Ncounter.
        k = mcounter(num,i + 1);
        b = ncounter(num,i + 1);
        a = pcounter(num);
        


        if (num[i] == '%' && num[a] == '.')
            mehdiconv2(args,num);     
        else if (num[i] == '%' && (num[i + 1] >= '1' && num[i + 1] <= '9'))
            printspace(args,&i,num);
        else if (num[i] == '%' && (num[i + 1] == '*'))
            aprintspace(args,&i,num);
        else if (num[i] == '%' && (num[i + n] == '0' && num[i + n + 1] == '*'))
            aprintspace(args,&i,num);
        else if (num[i] == '%' && (num[i + 1] == '0' && (num[i + n + 1] >= '1' && num[i + n + 1] <= '9')))
            printspace(args,&i,num);
        else if (num[i] == '%' && (num[i + 1] == '-' && num[i + k + 1] == '*'))
            aprintspace(args,&i,num);
        else if (num[i] == '%' && (num[i + 1] == '-' && (num[i + k + 1] >= '1' && num[i + k + 1] <= '9')))
                printspace(args,&i,num);
        else 
            mehdiconv(args, num, num[i + k + 1 + n]);
    }
    return (0);

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
   //Precisions with other convertions 

   //Right = 0;
    //Left = Space

    //ft_printf("%0*dh\n",-15,1); // FIX THIS



    //ft_printf("%.*d",-5,0);
    //THIS VS THIS
    //printf("%0*.*d\n",15,-5,1);
      //  printf("%*.*d\n",15,-5,1);

        ft_printf("%0*.*dh\n",4,-15,1);

        //Ela kan arguemnt lowla negative 0 is not working

       // printf("%0*.*d\n",-15,-5,1);

	return (0);
}