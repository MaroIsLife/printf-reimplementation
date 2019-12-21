/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 22:18:34 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/21 01:56:57 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_s(va_list args, const char *num)
{
	char	*s;
	int		c;
	int		k;

	s = va_arg(args, char *);
	if (s == NULL)
		c = ft_putstr("(null)");
	else
		c = ft_putstr(s);
	k = g_i;
	g_i = g_i + 1 + mcounter2(num, k + 1) + zcounter2(num, k + 1);
	return (0);
}

int		print_d(va_list args, const char *num)
{
	int s;
	int c;
	int k;

	k = g_i;
	s = va_arg(args, int);
	c = ft_putnbr(s);
	g_i = g_i + 1 + mcounter2(num, k + 1) + zcounter2(num, k + 1);
	return (0);
}

int		print_c(va_list args, const char *num)
{
	int s;
	int c;
	int k;

	k = g_i;
	s = va_arg(args, int);
	ft_putchar(s);
	c = 1;
	g_i = g_i + 1 + mcounter2(num, k + 1) + zcounter2(num, k + 1);
	return (0);
}

int		print_u(va_list args, const char *num)
{
	unsigned int	s;
	int				c;
	int				k;

	k = g_i;
	s = va_arg(args, unsigned int);
	c = ft_putunsigned(s);
	g_i = g_i + 1 + mcounter2(num, k + 1) + zcounter2(num, k + 1);
	return (c);
}

int		print_x(va_list args, const char *num)
{
	int				c;
	unsigned int	a;
	unsigned int	b;
	char			*buff;
	char			*af;

	af = "0123456789abcdef";
	c = 0;
	if (!(buff = calloc(20, 1)))
		return (0);
	a = va_arg(args, unsigned int);
	if (a == 0)
		buff[0] = '0';
	while (a != 0)
	{
		b = a % 16;
		buff[c] = af[b];
		a = a / 16;
		c++;
	}
	c = ft_putstr(ft_strrev(buff));
	free(buff);
	a = g_i;
	g_i = g_i + 1 + mcounter2(num, a + 1) + zcounter2(num, a + 1);
	return (c);
}
