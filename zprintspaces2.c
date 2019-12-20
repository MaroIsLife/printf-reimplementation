/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zprintspaces2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 00:09:25 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/21 00:09:26 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		zprintspace_xx(va_list args, int h)
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
	c = o + ft_hexxa(s);
	return (c);
}

int		zprintspace_p(va_list args, int h)
{
	int				o;
	unsigned long	s;
	int				c;

	s = va_arg(args, unsigned long);
	if (s == 0)
		c = ct_adr(s) + 2;
	else
		c = ct_adr(s) + 2;
	c = h - c;
	o = 0;
	while (o < c)
	{
		ft_putchar('0');
		o++;
	}
	ft_putstr("0x");
	c = o + ft_adr(s) + 2;
	return (c);
}

int		zprintspace_pp(int h)
{
	int o;
	int c;

	c = 1;
	c = h - c;
	o = 0;
	while (o < c)
	{
		ft_putchar('0');
		o++;
	}
	ft_putchar('%');
	c = 1 + o;
	return (c);
}
