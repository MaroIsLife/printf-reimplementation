/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 22:43:20 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/20 22:43:21 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		zcounter2(const char *num, int i)
{
	int o;

	o = 0;
	while (num[i] == '0')
	{
		o++;
		i++;
	}
	return (o);
}

int		mcounter(const char *num, int i)
{
	int o;

	o = 0;
	while (num[i] == '-')
	{
		o++;
		i++;
	}
	if ((num[i] == 'c' || num[i] == 'd' || num[i] == 's' || num[i] == 'p'
				|| num[i] == 'u' || num[i] == 'x' || num[i] == 'X') ||
			(num[i] >= '1' && num[i] <= '9') || num[i] == '*'
			|| num[i] == '.' || num[i] == 'i')
	{
		return (o);
	}
	else
		return (0);
}

int		mcounter2(const char *num, int i)
{
	int o;

	o = 0;
	while (num[i] == '-')
	{
		o++;
		i++;
	}
	return (o);
}
