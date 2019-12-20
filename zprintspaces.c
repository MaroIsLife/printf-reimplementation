/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zprintspaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 00:03:39 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/21 00:08:33 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		zprintspace_s(va_list args, int h)
{
	int		o;
	char	*s;
	int		c;

	s = va_arg(args, char *);
	c = ft_strlen(s);
	c = h - c;
	if (s < 0)
		o = 1;
	else
		o = 0;
	while (o < c)
	{
		ft_putchar('0');
		o++;
	}
	c = o + ft_putstr(s);
	return (c);
}

int		zprintspace_d(va_list args, int h)
{
	int o;
	int s;
	int c;

	s = va_arg(args, int);
	c = count(s);
	c = h - c;
	if (s < 0)
	{
		o = 1;
		ft_putchar('-');
	}
	else
		o = 0;
	while (o < c)
	{
		ft_putchar('0');
		o++;
	}
	c = o + zft_putnbr(s);
	return (c);
}

int		zprintspace_c(va_list args, int h)
{
	int o;
	int s;
	int c;

	s = va_arg(args, int);
	c = 1;
	c = h - c;
	if (s < 0)
		o = 1;
	else
		o = 0;
	while (o < c)
	{
		ft_putchar('0');
		o++;
	}
	ft_putchar(s);
	c = 1 + o;
	return (c);
}

int		zprintspace_u(va_list args, int h)
{
	int				o;
	unsigned int	s;
	int				c;

	s = va_arg(args, unsigned int);
	c = unsignedcount(s);
	c = h - c;
	o = 0;
	while (o < c)
	{
		ft_putchar('0');
		o++;
	}
	c = o + ft_putunsigned(s);
	return (c);
}

int		zprintspace_x(va_list args, int h)
{
	int				o;
	unsigned int	s;
	int				c;
	int				k;

	s = va_arg(args, int);
	k = s;
	if (k < 0)
		c = 8;
	else
		c = ct_hexa(s);
	c = h - c;
	o = 0;
	while (o < c)
	{
		ft_putchar('0');
		o++;
	}
	c = o + ft_hexa(s);
	return (c);
}
