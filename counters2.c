/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 22:41:16 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/20 22:41:18 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		mcounter3(const char *num, int i)
{
	int o;

	o = 0;
	while (num[i] == '-')
	{
		if (num[i] == 'c' || num[i] == 'd' || num[i] == 's' || num[i] == 'p'
				|| num[i] == 'u' || num[i] == 'x' || num[i] == 'X'
				|| num[i] == 'i')
		{
			return (0);
		}
		o++;
		i++;
	}
	return (o);
}

int		acounter(const char *num, int i)
{
	int o;
	int m;
	int z;

	z = zcounter(num, i);
	m = mcounter2(num, i);
	o = 0;
	if (num[i + z + m] == '*' || num[i + z + m + 2] == '*')
	{
		o++;
		i++;
	}
	return (o);
}

int		pcounter(const char *num)
{
	int a;

	a = g_i;
	while (num[g_i] == '%' && num[a] != '.' && num[a] != 'd' && num[a] != 's'
			&& num[a] != 'i' && num[a] != 'u' && num[a] != 'p' && num[a] != 'x'
			&& num[a] != 'X' && num[a] != 'c' && num[a] != 'i'
			&& num[a + 1] != '%')
		a++;
	return (a);
}

int		pcounter2(const char *num)
{
	int a;

	a = g_i;
	while (num[g_i] == '%' && num[a] != '*' && num[a] != '\0')
		a++;
	return (a);
}

int		acounter2(const char *num)
{
	int a;

	a = g_i;
	while (num[g_i] == '%' && num[a] != '*' && num[a] != '\0')
	{
		a++;
	}
	return (a);
}
