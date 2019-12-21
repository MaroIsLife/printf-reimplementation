/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mprintspaces2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 23:19:02 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/21 02:30:02 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	mprintspace_xx(va_list args, int h)
{
	int				o;
	unsigned int	s;
	int				c;
	int				k;

	s = va_arg(args, unsigned int);
	k = s;
	if (k < 0)
		c = 8;
	else
		c = ct_hexa(s);
	if (h < 0)
		h = h * -1;
	c = h - c;
	o = 0;
	k = ft_hexxa(s);
	while (o < c)
	{
		ft_putchar(' ');
		o++;
	}
}

void	mprintspace_p(va_list args, int h)
{
	int				o;
	unsigned long	s;
	int				c;
	char			k;

	s = va_arg(args, unsigned long);
	if (s == 0)
		c = ct_adr(s) + 2;
	else
		c = ct_adr(s) + 2;
	if (h < 0)
		h = h * -1;
	c = h - c;
	o = 0;
	ft_putstr("0x");
	k = ft_adr(s);
	while (o < c)
	{
		ft_putchar(' ');
		o++;
	}
}

void	mprintspace_pp(int h)
{
	int o;
	int c;

	if (h < 0)
		h = h * -1;
	c = 1;
	c = h - c;
	o = 0;
	ft_putchar('%');
	while (o < c)
	{
		ft_putchar(' ');
		o++;
	}
}
