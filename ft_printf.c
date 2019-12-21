/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 20:47:26 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/21 01:35:38 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	normal_print(va_list args, const char *num, char c)
{
	if (num[g_i] == '%' && c == 'c')
		print_c(args, num);
	else if (num[g_i] == '%' && c == 'x')
		print_x(args, num);
	else if (num[g_i] == '%' && c == 'X')
		print_xx(args, num);
	else if (num[g_i] == '%' && c == 'u')
		print_u(args, num);
	else if (num[g_i] == '%' && c == 's')
		print_s(args, num);
	else if (num[g_i] == '%' && (c == 'd' || c == 'i'))
		print_d(args, num);
	else if (num[g_i] == '%' && c == 'p')
		print_p(args, num);
	else if (num[g_i] == '%' && c == '%')
		print_perc();
	else
		print_n(num, &g_i);
}

void	precision_print(va_list args, const char *num)
{
	int aa;
	int ab;

	aa = pcounter(num);
	ab = pcounter2(num);
	g_tes = 0;
	g_tes2 = 0;
	if (num[g_i] == '%' && num[aa] == '.')
		adprintspace(args, num);
	else if (num[g_i] == '%' && num[ab] == '*')
		dprintspace(args, num);
}

void	asterix_print(va_list args, const char *num)
{
	int n;
	int k;

	n = zcounter(num, g_i + 1);
	k = mcounter(num, g_i + 1);
	if (num[g_i] == '%' && (num[g_i + 1] == '*'))
		aprintspace(args, &g_i, num);
	else if (num[g_i] == '%' && (num[g_i + n] == '0'
				&& num[g_i + n + 1] == '*'))
		aprintspace(args, &g_i, num);
	else if (num[g_i] == '%' && (num[g_i + 1] == '-'
				&& num[g_i + k + 1] == '*'))
		aprintspace(args, &g_i, num);
}

void	ft_checkstring(const char *num, va_list args)
{
	while (num[++g_i] != '\0')
	{
		maincounter(num);
		if (num[g_i] == '%' && num[g_i + g_k + 1 + g_n] == '%')
			print_perc();
		else if (num[g_i] == '%' && num[g_a] == '.')
			precision_print(args, num);
		else if (num[g_i] == '%' && (num[g_i + 1] >= '1'
					&& num[g_i + 1] <= '9'))
			printspace(args, &g_i, num);
		else if (num[g_i] == '%' && (num[g_i + g_k + g_n + 1] == '*'))
			asterix_print(args, num);
		else if (num[g_i] == '%' && (num[g_i + g_n] == '0'
					&& (num[g_i + g_n + 1] >= '1'
						&& num[g_i + g_n + 1] <= '9')))
			printspace(args, &g_i, num);
		else if (num[g_i] == '%' && (num[g_i + g_k] == '-'
					&& (num[g_i + g_k + 1] >= '1'
						&& num[g_i + g_k + 1] <= '9')))
			printspace(args, &g_i, num);
		else
			normal_print(args, num, num[g_i + g_k + 1 + g_n]);
	}
}

int		ft_printf(const char *num, ...)
{
	va_list args;

	g_a = 0;
	g_i = -1;
	g_r = 0;
	g_k = 0;
	g_n = 0;
	va_start(args, num);
	ft_checkstring(num, args);
	va_end(args);
	return (g_r);
}

/*int	main()
  {

//DONT FORGET MALLOC PROTECTION !!!!!!!!!!

//Right = 0;
//Left = Space


//printf("%0-04.3%"); This
int a;
a = ft_printf("%*.c\n",-42,0);
printf("%d", a);


//Ela kan arguemnt lowla negative 0 is not working
return (0);
}*/
