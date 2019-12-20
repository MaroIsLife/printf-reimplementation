/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zdprintspaces2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 00:01:56 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/21 00:02:09 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	zdprintspace_xx(t_container st, va_list args)
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
		ft_hexxa(s);
	space_unsignedprinter(c);
}

int		zdprintspace_p(t_container st, va_list args)
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
	ft_putstr("0x");
	if (s != 0)
		ft_adr(s);
	while (o < c)
	{
		ft_putchar(' ');
		o++;
	}
	return (0);
}

int		zdprintspace_pp(t_container st)
{
	int c;
	int b;
	int o;

	b = 1;
	c = st.h1 - 1;
	o = 0;
	ft_putchar('%');
	while (o < c)
	{
		ft_putchar(' ');
		o++;
	}
	return (0);
}
