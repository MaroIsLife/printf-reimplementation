/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_finders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 21:55:38 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/20 21:56:33 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	aprintspace(va_list args, int *i, const char *num)
{
	int h;
	int n;
	int z;

	z = *i + 1;
	h = va_arg(args, int);
	n = *i + convcounter(num, z);
	if (h < 0)
	{
		*i = *i + mwhichspace(num, n, args, h) + mcounter2(num, z);
		*i = *i + acounter(num, z) + zcounter2(num, z) + 1;
	}
	else if (num[z] == '0')
	{
		*i = *i + zwhichspace(num, n, args, h) + zcounter2(num, z);
		*i = *i + acounter(num, z) + mcounter2(num, z) + 1;
	}
	else if (num[z] == '-')
	{
		*i = *i + mwhichspace(num, n, args, h) + mcounter2(num, z);
		*i = *i + acounter(num, z) + zcounter2(num, z) + 1;
	}
	else
		*i = *i + whichspace(num, n, args, h) + acounter(num, z) + 1;
}

void	printspace(va_list args, int *i, const char *num)
{
	int		h;
	int		n;
	char	*s;
	int		z;

	z = *i + 1;
	n = *i + convcounter(num, z);
	s = ft_substr(num, z, n);
	h = ft_atoi(s);
	free(s);
	if (num[z] == '0')
	{
		*i = *i + zwhichspace(num, n, args, h) + zcounter2(num, z);
		*i = *i + count(h) + 1;
	}
	else if (num[z] == '-')
	{
		*i = *i + mwhichspace(num, n, args, h) + mcounter2(num, z);
		*i = *i + count(h) + 1;
	}
	else
		*i = *i + whichspace(num, n, args, h) + count(h) + 1;
}

void	dprintspace(va_list args, const char *num)
{
	int			n;
	int			z;
	int			b;
	t_container	st;

	st.h1 = numb_counter1(num);
	st.h2 = numb_counter2(num);
	z = g_i + 1;
	b = g_i + ncounter(num, z) + 1;
	n = g_i + dotcounter(num, z) + convcounter(num, b);
	if (st.h2 < 0 && num[n - 1] == '0' && st.h1 >= 0)
	{
		st.h2 = st.h1;
		st.h1 = 0;
		g_tes = 1;
	}
	if (num[z] == '-')
		zdwhichspace(num, args, st, n);
	else
	{
		if (num[z] == '0')
			g_tes2 = 1;
		dwhichspace(num, args, st, n);
	}
	g_i = g_i + convcounter(num, z) + 1;
}

void	adprintspace(va_list args, const char *num)
{
	int			n;
	int			z;
	t_container st;

	z = g_i + 1;
	n = g_i + dotcounter(num, g_i + 1);
	st.h1 = arg_checker_one(num, n, args);
	st.h2 = arg_checker_two(num, n, args);
	st = if_zero_negative(st, n, num);
	n = g_i + convcounter(num, g_i + 1);
	if (st.h1 < 0)
	{
		st.h1 = st.h1 * -1;
		zdwhichspace(num, args, st, n);
	}
	else if (num[z] == '-')
		zdwhichspace(num, args, st, n);
	else
	{
		if (num[z] == '0')
			g_tes2 = 1;
		dwhichspace(num, args, st, n);
	}
	z = convcounter(num, g_i + 1);
	g_i = g_i + z + 1;
}
