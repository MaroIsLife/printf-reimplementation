#include "printf.h"

int ft_strlen(const char *c)
{
    int i;

    i = 0;
    while (c[i] != '\0')
        i++;
    return (i);
} 

void ft_putchar(char c)
{
    write(1,&c,1);
}

int ft_putstr(char *c)
{
    int i;

    i = 0;
    while (c[i] != '\0')
    {
        ft_putchar(c[i]);
        i++;
    }
    return (i);
}

int     count(int n)
{
    int i;

    i = 1;
    while (n / 10 != 0)
    {
        n = n / 10;
        i++;
    }
    return (i);
}

int    ft_putnbr(int n)
{
    unsigned int i;
    int c;

    c = count(n);
    if (n < 0)
    {
        ft_putchar('-'); // CAUTION
        i = (unsigned int)(n * -1);
    }
    else
    {
        i = n;
    }
    if (i >= 10)
    {
        ft_putnbr(i / 10);
        ft_putchar(i % 10 + '0');
    }
    else
    {
        ft_putchar(i + '0');
    }
    return (c);
}

int    ft_putunsigned(unsigned int n)
{
    unsigned int i;
    int c;

    c = count(n);
    
    i = n;
    if (i >= 10)
    {
        ft_putnbr(i / 10);
        ft_putchar(i % 10 + '0');
    }
    else
    {
        ft_putchar(i + '0');
    }
    return (c);
}


char    *ft_strrev(char *str)
{
    int     l;
    int     a;
    int     b;
    char    swap;

    l = 0;
    while (str[l] != '\0')
    {
        l++;
    }
    a = l - 1;
    b = 0;
    while (b < a)
    {
        swap = str[b];
        str[b] = str[a];
        str[a] = swap;
        b++;
        a--;
    }
    return (str);
}

void    ft_bzero(void *s, size_t n)
{
    size_t          i;
    unsigned char   *s1;

    i = 0;
    s1 = (unsigned char*)s;
    while (i < n)
    {
        s1[i] = 0;
        i++;
    }
}

void            *ft_calloc(size_t n, size_t size)
{
    void *i;

    i = malloc(n * size);
    if (i == NULL)
        return (0);
    else
    {
        ft_bzero(i, n * size);
        return (i);
    }
}

char    *ft_substr(const char *s, int start, size_t len)
{
    size_t      i;
    char        *s1;
    size_t      size;
    size_t      c;

    if (s == 0)
        return (0);
    if (start > ft_strlen(s))
        len = 0;
    i = 0;
    size = len + 1;
    s1 = malloc(size * sizeof(char));
    if (s1 == NULL)
        return (NULL);
    c = start;
    while (s[i] != '\0' && i < len)
    {
        s1[i] = s[c];
        i++;
        c++;
    }
    s1[i] = '\0';
    return (s1);
}

int     ft_atoi(const char *str)
{
    int             s;
    unsigned long   r;
    unsigned int    i;

    s = 1;
    r = 0;
    i = 0;
    while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57)
    {
        r = r * 10 + str[i] - '0';
        i++;
    }
    if (r > __LONG_MAX__)
        return ((s > 0) ? -1 : 0);
    return (r * s);
}

