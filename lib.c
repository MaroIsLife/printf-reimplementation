#include "printf.h"
int ft_hexa(int s)
{
    int c;
    char *buff;
    char *af; 
    
    af = "0123456789abcdef"; 
    c = 0;
    buff = calloc(20,1);
    while (s != 0)
    {
        buff[c] = af[s % 16];
        s = s / 16;
        c++;
    }
    c = ft_putstr(ft_strrev(buff));
    free(buff);
    return (c);
}
int ft_heXa(int s)
{
    int c;
    char *buff;
    char *af; 
    
    af = "0123456789ABCDEF"; 
    c = 0;
    buff = calloc(20,1);
    while (s != 0)
    {
        buff[c] = af[s % 16];
        s = s / 16;
        c++;
    }
    c = ft_putstr(ft_strrev(buff));
    free(buff);
    return (c);
}

int ft_adr(unsigned long s)
{
    int c;
    char *buff;
    char *af; 
    
    af = "0123456789abcdef"; 
    c = 0;
    buff = calloc(20,1);
    if (s == 0)
    buff[0] = '0';
    while (s != 0)
    {
        buff[c] = af[s % 16];
        s = s / 16;
        c++;
    }
    c = ft_putstr(ft_strrev(buff));
    free(buff);
    return (c);
}