/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 22:28:20 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/20 22:41:09 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ncounter(const char *num, int i)
{
	int o;

	o = 0;
	while ((num[i] >= '1' && num[i] <= '9') || (num[i] == '0') || num[i] == '-')
	{
		o++;
		i++;
	}
	if (num[i] == '.' || num[i + 1] == '.')
	{
		return (o);
	}
	else
		return (0);
}

int		convcounter(const char *num, int z)
{
	int n;
	int a;

	a = z;
	n = 0;
	while (num[a] != 'd' && num[a] != 's' && num[a] != 'i' && num[a] != 'u'
			&& num[a] != 'p' && num[a] != 'x' && num[a] != 'X'
			&& num[a] != '%' && num[a] != 'c' && num[a] != 'i')
	{
		n++;
		a++;
	}
	return (n);
}

int		dotcounter(const char *num, int z)
{
	int n;
	int a;

	a = z;
	n = 0;
	while (num[a] != '.')
	{
		n++;
		a++;
	}
	return (n);
}

int		zcounter(const char *num, int i)
{
	int o;

	o = 0;
	while (num[i] == '0')
	{
		o++;
		i++;
	}
	if ((num[i] == 'c' || num[i] == 'd' || num[i] == 's' || num[i] == 'p'
				|| num[i] == 'u' || num[i] == 'x' || num[i] == 'X')
			|| (num[i] >= '1' && num[i] <= '9') || num[i] == '*'
			|| num[i] == '.' || num[i] == 'i' || num[i] == '%')
	{
		return (o);
	}
	else
		return (0);
}
