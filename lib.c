/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 22:44:27 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/20 22:51:34 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_hexa(unsigned int s)
{
	int		c;
	char	*buff;
	char	*af;

	af = "0123456789abcdef";
	c = 0;
	buff = calloc(20, 1);
	if (s == 0)
		buff[0] = '0';
	while (s != 0)
	{
		buff[c] = af[s % 16];
		s = s / 16;
		c++;
	}
	c = ft_putstr(ft_strrev(buff));
	free(buff);
	return (c);
}

int		ct_hexa(unsigned int s)
{
	int		c;
	char	*buff;
	char	*af;

	af = "0123456789abcdef";
	c = 0;
	buff = calloc(20, 1);
	if (s == 0)
		buff[0] = '0';
	while (s != 0)
	{
		buff[c] = af[s % 16];
		s = s / 16;
		c++;
	}
	c = ft_strlen(buff);
	free(buff);
	return (c);
}

int		ct_adr(unsigned long s)
{
	unsigned long	c;
	char			*buff;
	char			*af;

	af = "0123456789abcdef";
	c = 0;
	buff = calloc(20, 1);
	if (s == 0)
		buff[0] = '0';
	while (s != 0)
	{
		buff[c] = af[s % 16];
		s = s / 16;
		c++;
	}
	c = ft_strlen(buff);
	free(buff);
	return (c);
}

int		ft_hexxa(unsigned int s)
{
	int		c;
	char	*buff;
	char	*af;

	af = "0123456789ABCDEF";
	c = 0;
	buff = calloc(20, 1);
	if (s == 0)
		buff[0] = '0';
	while (s != 0)
	{
		buff[c] = af[s % 16];
		s = s / 16;
		c++;
	}
	c = ft_putstr(ft_strrev(buff));
	free(buff);
	return (c);
}

int		ft_adr(unsigned long s)
{
	int		c;
	int		b;
	char	*buff;
	char	*af;

	af = "0123456789abcdef";
	c = 0;
	buff = calloc(20, 1);
	if (s == 0)
		buff[0] = '0';
	while (s != 0)
	{
		b = s % 16;
		buff[c] = af[b];
		s = s / 16;
		c++;
	}
	c = ft_putstr(ft_strrev(buff));
	free(buff);
	return (c);
}
