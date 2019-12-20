/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dprintspaces2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 23:50:12 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/20 23:50:21 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		dprintspace_xx(t_container st, va_list args)
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
		ft_hexxa(s);
	return (0);
}

int		dprintspace_p(t_container st, va_list args)
{
	unsigned long	s;
	int				c;
	int				o;

	s = va_arg(args, unsigned long);
	if (s == 0)
		c = ct_adr(s) + 1;
	else
		c = ct_adr(s) + 2;
	c = st.h1 - c;
	o = 0;
	while (o < c)
	{
		ft_putchar(' ');
		o++;
	}
	ft_putstr("0x");
	if (s != 0)
		ft_adr(s);
	return (0);
}

int		dprintspace_pp(t_container st)
{
	char	s;
	int		c;
	int		o;

	if (g_tes == 1)
		c = st.h2 - 1;
	else
		c = st.h1 - 1;
	if (g_tes2 == 1)
		s = '0';
	else
		s = ' ';
	o = 0;
	while (o < c)
	{
		ft_putchar(s);
		o++;
	}
	ft_putchar('%');
	return (0);
}
