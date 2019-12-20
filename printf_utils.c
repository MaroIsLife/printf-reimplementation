/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 00:13:59 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/21 00:16:22 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_strlen(const char *c)
{
	int i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_r = g_r + 1;
}

int		ft_putstr(char *c)
{
	int i;

	i = 0;
	while (c[i] != '\0')
	{
		ft_putchar(c[i]);
		i++;
	}
	return (i);
}

int		count(int n)
{
	int i;

	i = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int		unsignedcount(unsigned int n)
{
	unsigned int i;

	i = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
