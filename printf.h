/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 00:30:37 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/21 01:35:57 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int				g_r;
int				g_i;
int				g_k;
int				g_n;
int				g_a;
int				g_tes;
int				g_tes2;
typedef struct	s_test{
	int		h1;
	int		h2;
	char	*s1;
	char	*s2;
}				t_container;
int				ft_printf(const char *num, ...);
void			aprintspace(va_list args, int *i, const char *num);
void			printspace(va_list args, int *i, const char *num);
void			dprintspace(va_list args, const char *num);
void			adprintspace(va_list args, const char *num);
int				arg_checker_one(const char *num, int n, va_list args);
int				arg_checker_two(const char *num, int n, va_list args);
t_container		if_zero_negative(t_container st, int n, const char *num);
int				numb_counter1(const char *num);
int				numb_counter2(const char *num);
void			ft_putchar(char c);
int				ft_putstr(char *c);
int				ft_strlen(const char *c);
int				ft_putunsigned(unsigned int n);
int				ft_putnbr(int n);
int				zft_putnbr(int n);
int				count(int n);
int				unsignedcount(unsigned int n);
char			*ft_strrev(char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t n, size_t size);
char			*ft_substr(const char *s, int start, size_t len);
int				ft_atoi(const char *str);
int				wordputter(int b, char *s);
int				ncounter(const char *num, int i);
int				mcounter(const char *num, int i);
int				mcounter2(const char *num, int i);
int				zcounter(const char *num, int i);
int				zcounter2(const char *num, int i);
int				convcounter(const char *num, int z);
int				acounter(const char *num, int i);
int				dotcounter(const char *num, int z);
int				pcounter(const char *num);
int				acounter2(const char *num);
int				pcounter2(const char *num);
void			zero_printer_d(int s, int b, t_container st);
void			space_printer_d(int s, int c);
void			unsigned_printer(unsigned int s, int c, int b);
void			zero_unsignedprinter(unsigned int s, int b);
void			space_unsignedprinter(int c);
void			dprintspace_d(t_container st, va_list args);
int				dprintspace_s(t_container st, va_list args);
int				dprintspace_c(t_container st, va_list args);
void			dprintspace_u(t_container st, va_list args);
int				dprintspace_x(t_container st, va_list args);
int				dprintspace_xx(t_container st, va_list args);
int				dprintspace_p(t_container st, va_list args);
int				dprintspace_pp(t_container st);
void			zdprintspace_d(t_container st, va_list args);
int				zdprintspace_s(t_container st, va_list args);
int				zdprintspace_c(t_container st, va_list args);
void			zdprintspace_u(t_container st, va_list args);
void			zdprintspace_x(t_container st, va_list args);
void			zdprintspace_xx(t_container st, va_list args);
int				zdprintspace_p(t_container st, va_list args);
int				zdprintspace_pp(t_container st);
int				printspace_s(va_list args, int h);
int				printspace_x(va_list args, int h);
int				printspace_d(va_list args, int h);
int				printspace_c(va_list args, int h);
int				printspace_p(va_list args, int h);
int				printspace_pp(int h);
int				printspace_u(va_list args, int h);
int				printspace_xx(va_list args, int h);
int				zprintspace_s(va_list args, int h);
int				zprintspace_x(va_list args, int h);
int				zprintspace_d(va_list args, int h);
int				zprintspace_c(va_list args, int h);
int				zprintspace_p(va_list args, int h);
int				zprintspace_pp(int h);
int				zprintspace_u(va_list args, int h);
int				zprintspace_xx(va_list args, int h);
void			mprintspace_s(va_list args, int h);
void			mprintspace_x(va_list args, int h);
void			mprintspace_d(va_list args, int h);
void			mprintspace_c(va_list args, int h);
void			mprintspace_p(va_list args, int h);
void			mprintspace_pp(int h);
void			mprintspace_u(va_list args, int h);
void			mprintspace_xx(va_list args, int h);
int				whichspace(const char *num, int n, va_list args, int h);
int				zwhichspace(const char *num, int n, va_list args, int h);
int				mwhichspace(const char *num, int n, va_list args, int h);
int				dwhichspace(const char *num, va_list args,
		t_container st, int n);
int				zdwhichspace(const char *num, va_list args,
		t_container st, int n);
int				ft_hexa(unsigned int s);
int				ct_hexa(unsigned int s);
int				ft_hexxa(unsigned int s);
int				ft_adr(unsigned long s);
int				ct_adr(unsigned long s);
int				print_s(va_list args, const char *num);
int				print_d(va_list args, const char *num);
int				print_x(va_list args, const char *num);
int				print_xx(va_list args, const char *num);
int				print_p(va_list args, const char *num);
int				print_u(va_list args, const char *num);
int				print_c(va_list args, const char *num);
int				print_perc(void);
int				print_n(const char *num, int *i);

#endif
