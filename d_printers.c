/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_printers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 23:20:19 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/20 23:53:42 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	space_printer_d(int s, int c)
{
	int o;

	if (s < 0)
		o = 1;
	else
		o = 0;
	while (o < c)
	{
		ft_putchar(' ');
		o++;
	}
}

void	zero_printer_d(int s, int b, t_container st)
{
	int o;

	if (s < 0)
		ft_putchar('-');
	if (s == 0)
	{
		o = 1;
		b = b + 1;
	}
	else
		o = 0;
	if (g_tes == 1)
	{
		if (s < 0)
			o = 1;
		else if (s == 0)
			st.h2 = 1;
	}
	while (o < b)
	{
		ft_putchar('0');
		o++;
	}
}

void	zero_unsignedprinter(unsigned int s, int b)
{
	int o;

	if (s == 0)
		b = b + 1;
	if (s == 0)
		o = 1;
	else
		o = 0;
	while (o < b)
	{
		ft_putchar('0');
		o++;
	}
}

void	space_unsignedprinter(int c)
{
	int o;

	o = 0;
	while (o < c)
	{
		ft_putchar(' ');
		o++;
	}
}

void	unsigned_printer(unsigned int s, int c, int b)
{
	int o;

	if (s == 0)
		b = b + 1;
	o = 0;
	while (o < c)
	{
		ft_putchar(' ');
		o++;
	}
	if (s == 0)
		o = 1;
	else
		o = 0;
	while (o < b)
	{
		ft_putchar('0');
		o++;
	}
}
