#include "printf.h"

int ncounter(const char *num,int i)
{
    int o;
    o = 0;
    while ((num[i] >= '1' && num[i] <= '9') || (num[i] == '0') || num[i] == '-')
    {
        o++;
        i++;      
    }
    if (num[i] == '.' || num[i + 1] == '.')
    {
        return (o);
    } 
    else
        return (0);
}

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

int dotcounter(const char *num,int z)
{   int n;
    int a;
    a = z;
    n = 0;
    while (num[a] != '.')
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
    if ((num[i] == 'c' || num[i] == 'd' || num[i] == 's' || num[i] == 'p' || num[i] == 'u' || num[i] == 'x' || num[i] == 'X') || (num[i] >= '1' && num[i] <= '9') || num[i] == '*' || num[i] == '.')
    {
        return (o);
    } 
    else
        return(0);
}
int zcounter2(const char *num,int i)
{
    int o;
    o = 0;
    while (num[i] == '0')
    {
        o++;
        i++;
    }
    /*if (num[i] == 'c' || num[i] == 'd' || num[i] == 's' || num[i] == 'p' || num[i] == 'u' || num[i] == 'x' || num[i] == 'X')
    {
        return (0);
    }*/ 
    //else
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
    if ((num[i] == 'c' || num[i] == 'd' || num[i] == 's' || num[i] == 'p' || num[i] == 'u' || num[i] == 'x' || num[i] == 'X') || (num[i] >= '1' && num[i] <= '9') || num[i] == '*' || num[i] == '.')
    {
        return (o);
    } 
    else
        return (0);
}
int mcounter2(const char *num,int i)
{
    int o;
    o = 0;
    while (num[i] == '-')
    {
        o++;
        i++;
    }
    /*if (num[i] == 'c' || num[i] == 'd' || num[i] == 's' || num[i] == 'p' || num[i] == 'u' || num[i] == 'x' || num[i] == 'X')
    {
        return (0);
    }*/ 
    //else
    return (o);
}
int mcounter3(const char *num,int i)
{
    int o;
    o = 0;
    while (num[i] == '-')
    {
        if (num[i] == 'c' || num[i] == 'd' || num[i] == 's' || num[i] == 'p' || num[i] == 'u' || num[i] == 'x' || num[i] == 'X')
    {
        return (0);
    }
        o++;
        i++;
    }
    return (o);
}



int acounter(const char *num,int i)
{
    int o;
    int m;
    int z;
    z = zcounter(num,i);
    m = mcounter2(num,i);

    o = 0;
    if (num[i + z + m] == '*' || num[i + z + m + 2] == '*')
    {
        o++;
        i++;
    }
    return (o);

}


int pcounter(const char *num)
{
    int a;
    a = i;
    while (num[i] == '%' && num[a] != '.' && num[a] != '\0')
        a++;
    //if (a == '.')
    return (a);
    //else 
    //return (0);
}

int pcounter2(const char *num)
{
    int a;
    a = i;
    while (num[i] == '%' && num[a] != '*' && num[a] != '\0')
        a++;
    //if (a == '.')
    return (a);
    //else 
    //return (0);
}

int acounter2(const char *num)
{
    int a;
    a = i;
    while (num[i] == '%' && num[a] != '*' && num[a] != '\0')
    {
        a++;
    }
    return (a);
}