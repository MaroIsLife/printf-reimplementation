/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 00:20:18 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/21 00:22:12 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	*ft_calloc(size_t n, size_t size)
{
	void *i;

	i = malloc(n * size);
	if (i == NULL)
		return (0);
	else
	{
		ft_bzero(i, n * size);
		return (i);
	}
}

char	*ft_substr(const char *s, int start, size_t len)
{
	size_t		i;
	char		*s1;
	size_t		size;
	size_t		c;

	if (s == 0)
		return (0);
	if (start > ft_strlen(s))
		len = 0;
	i = 0;
	size = len + 1;
	s1 = malloc(size * sizeof(char));
	if (s1 == NULL)
		return (NULL);
	c = start;
	while (s[i] != '\0' && i < len)
	{
		s1[i] = s[c];
		i++;
		c++;
	}
	s1[i] = '\0';
	return (s1);
}

int		ft_atoi(const char *str)
{
	int				s;
	unsigned long	r;
	unsigned int	i;

	s = 1;
	r = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	while (str[i] == '-' || str[i] == '+' || str[i] == '.' || str[i] == '*')
	{
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	if (r > __LONG_MAX__)
		return ((s > 0) ? -1 : 0);
	return (r * s);
}

int		wordputter(int b, char *s)
{
	int o;
	int a;

	a = ft_strlen(s);
	o = 0;
	if (a == 0)
		return (o);
	else
	{
		while (o < b && s[o] != '\0')
		{
			ft_putchar(s[o]);
			o++;
		}
	}
	return (o);
}
