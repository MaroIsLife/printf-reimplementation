/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflib2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 22:24:02 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/21 01:56:48 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_xx(va_list args, const char *num)
{
	int				c;
	unsigned int	a;
	unsigned int	b;
	char			*buff;
	char			*af;

	af = "0123456789ABCDEF";
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

int		print_p(va_list args, const char *num)
{
	int				c;
	unsigned long	a;
	unsigned long	b;
	char			*buff;
	char			*af;

	af = "0123456789abcdef";
	c = 0;
	if (!(buff = calloc(20, 1)))
		return (0);
	a = va_arg(args, unsigned long);
	if (a == 0)
		buff[0] = '0';
	while (a != 0)
	{
		b = a % 16;
		buff[c] = af[b];
		a = a / 16;
		c++;
	}
	c = ft_putstr("0x");
	c = c + ft_putstr(ft_strrev(buff));
	free(buff);
	g_i = g_i + 1 + mcounter2(num, g_i + 1) + zcounter2(num, g_i + 1);
	return (c);
}

int		print_perc(const char *num)
{
	int c;

	ft_putchar('%');
	c = 1;
	g_i = g_i + 1 + mcounter2(num, g_i + 1) + zcounter2(num, g_i + 1);
	return (c);
}

int		print_n(const char *num, int *i)
{
	int c;

	ft_putchar(num[*i]);
	c = 1;
	return (c);
}
