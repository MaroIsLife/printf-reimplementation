/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 20:47:26 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/20 21:12:33 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int g_r;

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

int		numb_counter1(const char *num)
{
	struct s_test st2;
	int		z;
	int		b;
	int		n;

	z = i + 1;
	n = i + dotcounter(num, z);
	if (num[z] == '.')
		n = 0;
	st2.s1 = ft_substr(num, z, n);
	b = i + ncounter(num, z) + 1;
	n = i + convcounter(num, b);
	st2.s2 = ft_substr(num, b, n);
	st2.h1 = ft_atoi(st2.s1);
	st2.h2 = ft_atoi(st2.s2);
	free(st2.s1);
	free(st2.s2);
	return (st2.h1);
}

int		numb_counter2(const char *num)
{
	struct s_test st2;
	int		z;
	int		b;
	int		n;

	z = i + 1;
	n = i + dotcounter(num, z);
	st2.s1 = ft_substr(num, z, n);
	b = i + ncounter(num, z) + 1;
	n = i + convcounter(num, b);
	st2.s2 = ft_substr(num, b, n);
	st2.h1 = ft_atoi(st2.s1);
	st2.h2 = ft_atoi(st2.s2);
	free(st2.s1);
	free(st2.s2);
	return (st2.h2);
}

void	dprintspace(va_list args, const char *num)
{
	int	n;
	int	z;
	int	b;
	struct s_test st;

	st.h1 = numb_counter1(num);
	st.h2 = numb_counter2(num);
	z = i + 1;
	b = i + ncounter(num, z) + 1;
	n = i + dotcounter(num, z) + convcounter(num, b);
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
	i = i + convcounter(num, z) + 1;
}

int		arg_checker_one(const char *num, int n, va_list args)
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

int		arg_checker_two(const char *num, int n, va_list args)
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

struct	s_test	if_zero_negative(struct s_test st, int n, const char *num)
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

void	adprintspace(va_list args, const char *num)
{
	int		n;
	int		z;
	struct s_test st;
    
	z = i + 1;
	n = i + dotcounter(num, i + 1);
	st.h1 = arg_checker_one(num, n, args);
	st.h2 = arg_checker_two(num, n, args);
	st = if_zero_negative(st, n, num);
	n = i + convcounter(num, i + 1);
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
	z = convcounter(num, i + 1);
	i = i + z + 1;
}

void	normal_print(va_list args, const char *num, char c)
{
	if (num[i] == '%' && c == 'c')
		print_c(args, num);
	else if (num[i] == '%' && c == 'x')
		print_x(args, num);
	else if (num[i] == '%' && c == 'X')
		print_X(args, num);
	else if (num[i] == '%' && c == 'u')
		print_u(args, num);
	else if (num[i] == '%' && c == 's')
		print_s(args, num);
	else if (num[i] == '%' && (c == 'd' || c == 'i'))
		print_d(args, num);
	else if (num[i] == '%' && c == 'p')
		print_p(args, num);
	else if (num[i] == '%' && c == '%')
		print_perc(i);
	else
		print_n(num, &i);
}

void	precision_print(va_list args, const char *num)
{
	int aa;
	int ab;

	aa = pcounter(num);
	ab = pcounter2(num);
	g_tes = 0;
	g_tes2 = 0;
	if (num[i] == '%' && num[aa] == '.')
		adprintspace(args, num);
	else if (num[i] == '%' && num[ab] == '*')
		dprintspace(args, num);
}

void	asterix_print(va_list args, const char *num)
{
	int n;
	int k;

	n = zcounter(num, i + 1);
	k = mcounter(num, i + 1);
	if (num[i] == '%' && (num[i + 1] == '*'))
		aprintspace(args, &i, num);
	else if (num[i] == '%' && (num[i + n] == '0' && num[i + n + 1] == '*'))
		aprintspace(args, &i, num);
	else if (num[i] == '%' && (num[i + 1] == '-' && num[i + k + 1] == '*'))
		aprintspace(args, &i, num);
}

void	ft_checkstring(const char *num, va_list args)
{
	int n;
	int a;
	int k;

	i = -1;
	while (num[++i] != '\0')
	{
		n = zcounter(num, i + 1);
		k = mcounter(num, i + 1);
		a = pcounter(num);
		if (num[i] == '%' && num[i + k + 1 + n] == '%')
			print_perc(i);
		else if (num[i] == '%' && num[a] == '.')
			precision_print(args, num);
		else if (num[i] == '%' && (num[i + 1] >= '1' && num[i + 1] <= '9'))
			printspace(args, &i, num);
		else if (num[i] == '%' && (num[i + k + n + 1] == '*'))
			asterix_print(args, num);
		else if (num[i] == '%' && (num[i + n] == '0'
					&& (num[i + n + 1] >= '1' && num[i + n + 1] <= '9')))
			printspace(args, &i, num);
		else if (num[i] == '%' && (num[i + k] == '-'
					&& (num[i + k + 1] >= '1' && num[i + k + 1] <= '9')))
			printspace(args, &i, num);
		else
			normal_print(args, num, num[i + k + 1 + n]);
	}
}

int		ft_printf(const char *num, ...)
{
	va_list args;

	g_r = 0;
	va_start(args, num);
	ft_checkstring(num, args);
	va_end(args);
	return (g_r);
}

/*int	main()
{

	// FIX CTHEXA AND FTHEXA %16


	//Right = 0;
	//Left = Space


	//printf("%0-04.3%"); This
	int a;
	a = ft_printf("%*.c\n",-42,0);
	printf("%d", a);


	//Ela kan arguemnt lowla negative 0 is not working
	return (0);
}*/
