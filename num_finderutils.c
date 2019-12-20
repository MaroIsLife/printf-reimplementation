/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_finderutils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 21:54:11 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/20 21:55:00 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				arg_checker_one(const char *num, int n, va_list args)
{
	int h1;

	h1 = 0;
	if (num[n] == '*' && num[n + 2] == '*')
		h1 = va_arg(args, int);
	else if (num[n] == '*' && num[n + 2] != '*')
		h1 = va_arg(args, int);
	else if (num[n] != '*' && num[n + 2] == '*')
		h1 = numb_counter1(num);
	else if (num[n] != '*' && num[n + 2] != '*')
		h1 = numb_counter1(num);
	return (h1);
}

int				arg_checker_two(const char *num, int n, va_list args)
{
	int h2;

	h2 = 0;
	if (num[n] == '*' && num[n + 2] == '*')
		h2 = va_arg(args, int);
	else if (num[n] == '*' && num[n + 2] != '*')
		h2 = numb_counter2(num);
	else if (num[n] != '*' && num[n + 2] == '*')
		h2 = va_arg(args, int);
	else if (num[n] != '*' && num[n + 2] != '*')
		h2 = numb_counter2(num);
	return (h2);
}

t_container		if_zero_negative(t_container st, int n, const char *num)
{
	if (st.h2 < 0 && num[n - 1] == '0')
	{
		if (st.h1 >= 0)
		{
			st.h2 = st.h1;
			g_tes = 1;
			st.h1 = 0;
			return (st);
		}
	}
	return (st);
}

int				numb_counter1(const char *num)
{
	t_container	st2;
	int			z;
	int			b;
	int			n;

	z = g_i + 1;
	n = g_i + dotcounter(num, z);
	if (num[z] == '.')
		n = 0;
	st2.s1 = ft_substr(num, z, n);
	b = g_i + ncounter(num, z) + 1;
	n = g_i + convcounter(num, b);
	st2.s2 = ft_substr(num, b, n);
	st2.h1 = ft_atoi(st2.s1);
	st2.h2 = ft_atoi(st2.s2);
	free(st2.s1);
	free(st2.s2);
	return (st2.h1);
}

int				numb_counter2(const char *num)
{
	t_container	st2;
	int			z;
	int			b;
	int			n;

	z = g_i + 1;
	n = g_i + dotcounter(num, z);
	st2.s1 = ft_substr(num, z, n);
	b = g_i + ncounter(num, z) + 1;
	n = g_i + convcounter(num, b);
	st2.s2 = ft_substr(num, b, n);
	st2.h1 = ft_atoi(st2.s1);
	st2.h2 = ft_atoi(st2.s2);
	free(st2.s1);
	free(st2.s2);
	return (st2.h2);
}
