/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mprintspaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 23:15:49 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/20 23:18:07 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	mprintspace_s(va_list args, int h)
{
	int		o;
	char	*s;
	int		c;

	s = va_arg(args, char *);
	if (s == NULL)
		c = 6;
	else
		c = ft_strlen(s);
	if (h < 0)
		h = h * -1;
	c = h - c;
	if (s < 0)
		o = 1;
	else
		o = 0;
	if (s != NULL)
		ft_putstr(s);
	else
		ft_putstr("(null)");
	while (o < c)
	{
		ft_putchar(' ');
		o++;
	}
}

void	mprintspace_d(va_list args, int h)
{
	int o;
	int s;
	int c;

	s = va_arg(args, int);
	c = count(s);
	if (h < 0)
		h = h * -1;
	c = h - c;
	if (s < 0)
		o = 1;
	else
		o = 0;
	ft_putnbr(s);
	while (o < c)
	{
		ft_putchar(' ');
		o++;
	}
}

void	mprintspace_c(va_list args, int h)
{
	int o;
	int s;
	int c;

	s = va_arg(args, int);
	if (h < 0)
		h = h * -1;
	c = 1;
	c = h - c;
	if (s < 0)
		o = 1;
	else
		o = 0;
	ft_putchar(s);
	while (o < c)
	{
		ft_putchar(' ');
		o++;
	}
}

void	mprintspace_u(va_list args, int h)
{
	int				o;
	unsigned int	s;
	int				c;

	s = va_arg(args, unsigned int);
	c = unsignedcount(s);
	if (h < 0)
		h = h * -1;
	c = h - c;
	o = 0;
	ft_putunsigned(s);
	while (o < c)
	{
		ft_putchar(' ');
		o++;
	}
}

void	mprintspace_x(va_list args, int h)
{
	int				o;
	unsigned int	s;
	int				c;
	int				k;

	s = va_arg(args, unsigned int);
	c = count(s) - 1;
	if (h < 0)
		h = h * -1;
	c = h - c;
	o = 0;
	k = ft_hexa(s);
	while (o < c)
	{
		ft_putchar(' ');
		o++;
	}
}
