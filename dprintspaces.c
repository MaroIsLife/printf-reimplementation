/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dprintspaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 23:39:57 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/20 23:40:00 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	dprintspace_d(t_container st, va_list args)
{
	int s;
	int c;
	int b;

	s = va_arg(args, int);
	c = count(s);
	b = st.h2 - c;
	if (st.h2 == 0)
	{
		if (s == 0)
			c = st.h1;
		else
			c = st.h1 - count(s);
	}
	else if (st.h2 > count(s))
		c = st.h1 - st.h2;
	else
		c = st.h1 - count(s);
	space_printer_d(s, c);
	zero_printer_d(s, b, st);
	if (s == 0 && st.h2 == 0)
		;
	else
		zft_putnbr(s);
}

int		dprintspace_s(t_container st, va_list args)
{
	char	*s;
	int		c;
	int		b;
	int		o;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";
	if (st.h2 < 0)
		st.h2 = ft_strlen(s);
	b = ft_strlen(s);
	if (st.h2 >= b)
		c = st.h1 - b;
	else
		c = st.h1 - st.h2;
	o = 0;
	while (o < c)
	{
		ft_putchar(' ');
		o++;
	}
	b = st.h2;
	wordputter(b, s);
	return (0);
}

void	dprintspace_u(t_container st, va_list args)
{
	unsigned int	s;
	int				c;
	int				b;

	s = va_arg(args, unsigned int);
	c = unsignedcount(s);
	b = st.h2 - c;
	if (st.h2 == 0)
	{
		if (s == 0)
			c = st.h1;
		else
			c = st.h1 - unsignedcount(s);
	}
	else if (st.h2 > unsignedcount(s))
		c = st.h1 - st.h2;
	else
		c = st.h1 - unsignedcount(s);
	unsigned_printer(s, c, b);
	if (s == 0 && st.h2 == 0)
		;
	else
		ft_putunsigned(s);
}

int		dprintspace_c(t_container st, va_list args)
{
	int s;
	int c;
	int b;
	int o;

	s = va_arg(args, int);
	b = 1;
	c = st.h1 - 1;
	o = 0;
	while (o < c)
	{
		ft_putchar(' ');
		o++;
	}
	ft_putchar(s);
	return (0);
}

int		dprintspace_x(t_container st, va_list args)
{
	unsigned int	s;
	int				c;
	int				b;

	s = va_arg(args, unsigned int);
	c = ct_hexa(s);
	b = st.h2 - c;
	if (st.h2 == 0)
	{
		if (s == 0)
			c = st.h1;
		else
			c = st.h1 - ct_hexa(s);
	}
	else if (st.h2 > ct_hexa(s))
		c = st.h1 - st.h2;
	else
		c = st.h1 - ct_hexa(s);
	unsigned_printer(s, c, b);
	if (s == 0 && st.h2 == 0)
		return (0);
	else
		ft_hexa(s);
	return (0);
}
