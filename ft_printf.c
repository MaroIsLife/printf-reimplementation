/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 20:47:26 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/20 21:47:30 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int g_r;

void	normal_print(va_list args, const char *num, char c)
{
	if (num[i] == '%' && c == 'c')
		print_c(args, num);
	else if (num[i] == '%' && c == 'x')
		print_x(args, num);
	else if (num[i] == '%' && c == 'X')
		print_xx(args, num);
	else if (num[i] == '%' && c == 'u')
		print_u(args, num);
	else if (num[i] == '%' && c == 's')
		print_s(args, num);
	else if (num[i] == '%' && (c == 'd' || c == 'i'))
		print_d(args, num);
	else if (num[i] == '%' && c == 'p')
		print_p(args, num);
	else if (num[i] == '%' && c == '%')
		print_perc();
	else
		print_n(num, &i);
}

void	precision_print(va_list args, const char *num)
{
	int aa;
	int ab;

	aa = pcounter(num);
	ab = pcounter2(num);
	g_tes = 0;
	g_tes2 = 0;
	if (num[i] == '%' && num[aa] == '.')
		adprintspace(args, num);
	else if (num[i] == '%' && num[ab] == '*')
		dprintspace(args, num);
}

void	asterix_print(va_list args, const char *num)
{
	int n;
	int k;

	n = zcounter(num, i + 1);
	k = mcounter(num, i + 1);
	if (num[i] == '%' && (num[i + 1] == '*'))
		aprintspace(args, &i, num);
	else if (num[i] == '%' && (num[i + n] == '0' && num[i + n + 1] == '*'))
		aprintspace(args, &i, num);
	else if (num[i] == '%' && (num[i + 1] == '-' && num[i + k + 1] == '*'))
		aprintspace(args, &i, num);
}

void	ft_checkstring(const char *num, va_list args)
{
	int n;
	int a;
	int k;

	i = -1;
	while (num[++i] != '\0')
	{
		n = zcounter(num, i + 1);
		k = mcounter(num, i + 1);
		a = pcounter(num);
		if (num[i] == '%' && num[i + k + 1 + n] == '%')
			print_perc();
		else if (num[i] == '%' && num[a] == '.')
			precision_print(args, num);
		else if (num[i] == '%' && (num[i + 1] >= '1' && num[i + 1] <= '9'))
			printspace(args, &i, num);
		else if (num[i] == '%' && (num[i + k + n + 1] == '*'))
			asterix_print(args, num);
		else if (num[i] == '%' && (num[i + n] == '0'
					&& (num[i + n + 1] >= '1' && num[i + n + 1] <= '9')))
			printspace(args, &i, num);
		else if (num[i] == '%' && (num[i + k] == '-'
					&& (num[i + k + 1] >= '1' && num[i + k + 1] <= '9')))
			printspace(args, &i, num);
		else
			normal_print(args, num, num[i + k + 1 + n]);
	}
}

int		ft_printf(const char *num, ...)
{
	va_list args;

	g_r = 0;
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
