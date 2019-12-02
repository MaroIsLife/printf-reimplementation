#ifndef PRINTF_H
# define PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


void     ft_putchar(char c);
int     ft_putstr(char *c);
int     ft_strlen(const char *c);
int     ft_putunsigned(unsigned int n);
int     ft_putnbr(int n);
int     count(int n);
char    *ft_strrev(char *str);
void    ft_bzero(void *s, size_t n);
void    *ft_calloc(size_t n, size_t size);
char    *ft_substr(const char *s, int start, size_t len);
int     ft_atoi(const char *str);



int printspace_s(va_list args,int h);
int printspace_x(va_list args,int h);
int printspace_d(va_list args,int h);
int printspace_c(va_list args,int h);
int printspace_u(va_list args,int h);




int whichspace(const char *num,int n,va_list args,int h);

int ft_hexa(int s);
int ft_heXa(int s);





int     print_s(va_list args, int *i);
int     print_d(va_list args, int *i);
int     print_x(va_list args, int *i);
int     print_X(va_list args, int *i);
int     print_p(va_list args, int *i);
int     print_u(va_list args, int *i);
int     print_c(va_list args, int *i);
int     print_perc(int *i);
int     print_n(const char *num,int *i);





#endif