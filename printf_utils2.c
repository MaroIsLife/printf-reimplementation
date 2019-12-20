/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 00:16:54 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/21 00:20:12 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_putnbr(int n)
{
	unsigned int	i;
	int				c;

	c = count(n);
	if (n < 0)
	{
		ft_putchar('-');
		i = (unsigned int)(n * -1);
	}
	else
	{
		i = n;
	}
	if (i >= 10)
	{
		ft_putnbr(i / 10);
		ft_putchar(i % 10 + '0');
	}
	else
		ft_putchar(i + '0');
	return (c);
}

int		zft_putnbr(int n)
{
	unsigned int	i;
	int				c;

	c = count(n);
	if (n < 0)
	{
		i = (unsigned int)(n * -1);
	}
	else
	{
		i = n;
	}
	if (i >= 10)
	{
		zft_putnbr(i / 10);
		ft_putchar(i % 10 + '0');
	}
	else
		ft_putchar(i + '0');
	return (c);
}

int		ft_putunsigned(unsigned int n)
{
	unsigned int	i;
	int				c;

	c = count(n);
	i = n;
	if (i >= 10)
	{
		ft_putnbr(i / 10);
		ft_putchar(i % 10 + '0');
	}
	else
		ft_putchar(i + '0');
	return (c);
}

char	*ft_strrev(char *str)
{
	int		l;
	int		a;
	int		b;
	char	swap;

	l = 0;
	while (str[l] != '\0')
	{
		l++;
	}
	a = l - 1;
	b = 0;
	while (b < a)
	{
		swap = str[b];
		str[b] = str[a];
		str[a] = swap;
		b++;
		a--;
	}
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	i = 0;
	s1 = (unsigned char*)s;
	while (i < n)
	{
		s1[i] = 0;
		i++;
	}
}
