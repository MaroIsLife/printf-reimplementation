#ifndef PRINTF_H
# define PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int g_r;
int i;
int g_off;
int g_tes;
int g_tes2;


struct s_test {
    int h1;
    int h2;
    char *s1;
    char *s2;

};

int ft_printf(const char *num, ...);

void     ft_putchar(char c);
int     ft_putstr(char *c);
int     ft_strlen(const char *c);
int     ft_putunsigned(unsigned int n);
int     ft_putnbr(int n);
int     zft_putnbr(int n);
int     count(int n);
int     unsignedcount(unsigned int n);
char    *ft_strrev(char *str);
void    ft_bzero(void *s, size_t n);
void    *ft_calloc(size_t n, size_t size);
char    *ft_substr(const char *s, int start, size_t len);
int     ft_atoi(const char *str);
int     wordputter(int b,char *s);

int ct_adr(unsigned long s);

int ncounter(const char *num,int i);
int mcounter(const char *num,int i);
int mcounter2(const char *num,int i);
int zcounter(const char *num,int i);
int zcounter2(const char *num,int i);
int convcounter(const char *num,int z);
int acounter(const char *num,int i);
int dotcounter(const char *num,int z);
int pcounter(const char *num);
int acounter2(const char *num);



int dprintspace_d(struct s_test st,va_list args);
int dprintspace_s(struct s_test st,va_list args);
int dprintspace_c(struct s_test st,va_list args);
int dprintspace_u(struct s_test st,va_list args);
int dprintspace_x(struct s_test st,va_list args);
int dprintspace_X(struct s_test st,va_list args);
int dprintspace_p(struct s_test st,va_list args);
int dprintspace_pp(struct s_test st);


int zdprintspace_d(struct s_test st,va_list args);
int zdprintspace_s(struct s_test st,va_list args);
int zdprintspace_c(struct s_test st,va_list args);
int zdprintspace_u(struct s_test st,va_list args);
int zdprintspace_x(struct s_test st,va_list args);
int zdprintspace_X(struct s_test st,va_list args);
int zdprintspace_p(struct s_test st,va_list args);
int zdprintspace_pp(struct s_test st);





int printspace_s(va_list args,int h);
int printspace_x(va_list args,int h);
int printspace_d(va_list args,int h);
int printspace_c(va_list args,int h);
int printspace_p(va_list args,int h);
int printspace_pp(int h);
int printspace_u(va_list args,int h);
int printspace_X(va_list args,int h);


int zprintspace_s(va_list args,int h);
int zprintspace_x(va_list args,int h);
int zprintspace_d(va_list args,int h);
int zprintspace_c(va_list args,int h);
int zprintspace_p(va_list args,int h);
int zprintspace_pp(int h);
int zprintspace_u(va_list args,int h);
int zprintspace_X(va_list args,int h);

int mprintspace_s(va_list args,int h);
int mprintspace_x(va_list args,int h);
int mprintspace_d(va_list args,int h);
int mprintspace_c(va_list args,int h);
int mprintspace_p(va_list args,int h);
int mprintspace_pp(int h);
int mprintspace_u(va_list args,int h);
int mprintspace_X(va_list args,int h);


int whichspace(const char *num,int n,va_list args,int h);
int zwhichspace(const char *num,int n,va_list args,int h);
int mwhichspace(const char *num,int n,va_list args,int h);
int dwhichspace(const char *num, va_list args,struct s_test st,int n);
int zdwhichspace(const char *num, va_list args,struct s_test st,int n);


int ft_hexa(unsigned int s);
int ct_hexa(unsigned int s);
int ft_heXa(unsigned int s);
int ft_adr(unsigned long s);



int     print_s(va_list args,const char *num);
int     print_d(va_list args,const char *num);
int     print_x(va_list args,const char *num);
int     print_X(va_list args,const char *num);
int     print_p(va_list args,const char *num);
int     print_u(va_list args,const char *num);
int     print_c(va_list args,const char *num);
int     print_perc();
int     print_n(const char *num,int *i);





#endif
