/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zdprintspaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 23:54:32 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/21 00:01:00 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	zdprintspace_d(t_container st, va_list args)
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
	zero_printer_d(s, b, st);
	if (s == 0 && st.h2 == 0)
		;
	else
		zft_putnbr(s);
	space_printer_d(s, c);
}

int		zdprintspace_s(t_container st, va_list args)
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
	b = st.h2;
	wordputter(b, s);
	while (o < c)
	{
		ft_putchar(' ');
		o++;
	}
	return (0);
}

void	zdprintspace_u(t_container st, va_list args)
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
	zero_unsignedprinter(s, b);
	if (s == 0 && st.h2 == 0)
		;
	else
		ft_putunsigned(s);
	space_unsignedprinter(c);
}

int		zdprintspace_c(t_container st, va_list args)
{
	int s;
	int c;
	int b;
	int o;

	s = va_arg(args, int);
	b = 1;
	c = st.h1 - 1;
	o = 0;
	ft_putchar(s);
	while (o < c)
	{
		ft_putchar(' ');
		o++;
	}
	return (0);
}

void	zdprintspace_x(t_container st, va_list args)
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
	zero_unsignedprinter(s, b);
	if (s == 0 && st.h2 == 0)
		;
	else
		ft_hexa(s);
	space_unsignedprinter(c);
}
