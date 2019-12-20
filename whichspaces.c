/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whichspaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mougnou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 22:06:04 by mougnou           #+#    #+#             */
/*   Updated: 2019/12/20 22:09:10 by mougnou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		whichspace(const char *num, int n, va_list args, int h)
{
	if (num[n + 1] == 's')
		printspace_s(args, h);
	else if (num[n + 1] == 'd' || num[n + 1] == 'i')
		printspace_d(args, h);
	else if (num[n + 1] == 'c')
		printspace_c(args, h);
	else if (num[n + 1] == 'x')
		printspace_x(args, h);
	else if (num[n + 1] == 'X')
		printspace_X(args, h);
	else if (num[n + 1] == 'p')
		printspace_p(args, h);
	else if (num[n + 1] == 'u')
		printspace_u(args, h);
	else if (num[n + 1] == '%')
		printspace_pp(h);
	return (0);
}

int		dwhichspace(const char *num, va_list args, t_container st, int n)
{
	if (num[n + 1] == 'd' || num[n] == 'd'
			|| num[n] == 'i' || num[n + 1] == 'i')
		dprintspace_d(st, args);
	else if (num[n + 1] == 's' || num[n] == 's')
		dprintspace_s(st, args);
	else if (num[n + 1] == 'c' || num[n] == 'c')
		dprintspace_c(st, args);
	else if (num[n + 1] == 'u' || num[n] == 'u')
		dprintspace_u(st, args);
	else if (num[n + 1] == 'x' || num[n] == 'x')
		dprintspace_x(st, args);
	else if (num[n + 1] == 'X' || num[n] == 'X')
		dprintspace_X(st, args);
	else if (num[n + 1] == 'p' || num[n] == 'p')
		dprintspace_p(st, args);
	else if (num[n + 1] == '%' || num[n] == '%')
		dprintspace_pp(st);
	return (0);
}

int		zdwhichspace(const char *num, va_list args, t_container st, int n)
{
	if (num[n + 1] == 'd' || num[n] == 'd'
			|| num[n] == 'i' || num[n + 1] == 'i')
		zdprintspace_d(st, args);
	else if (num[n + 1] == 's' || num[n] == 's')
		zdprintspace_s(st, args);
	else if (num[n + 1] == 'c' || num[n] == 'c')
		zdprintspace_c(st, args);
	else if (num[n + 1] == 'u' || num[n] == 'u')
		zdprintspace_u(st, args);
	else if (num[n + 1] == 'x' || num[n] == 'x')
		zdprintspace_x(st, args);
	else if (num[n + 1] == 'X' || num[n] == 'X')
		zdprintspace_X(st, args);
	else if (num[n + 1] == 'p' || num[n] == 'p')
		zdprintspace_p(st, args);
	else if (num[n + 1] == '%' || num[n] == '%')
		zdprintspace_pp(st);
	return (0);
}

int		zwhichspace(const char *num, int n, va_list args, int h)
{
	if (num[n + 1] == 's')
		zprintspace_s(args, h);
	else if (num[n + 1] == 'd' || num[n + 1] == 'i')
		zprintspace_d(args, h);
	else if (num[n + 1] == 'c')
		zprintspace_c(args, h);
	else if (num[n + 1] == 'x')
		zprintspace_x(args, h);
	else if (num[n + 1] == 'X')
		zprintspace_X(args, h);
	else if (num[n + 1] == 'p')
		zprintspace_p(args, h);
	else if (num[n + 1] == 'u')
		zprintspace_u(args, h);
	else if (num[n + 1] == '%')
		zprintspace_pp(h);
	return (0);
}

int		mwhichspace(const char *num, int n, va_list args, int h)
{
	if (num[n + 1] == 's')
		mprintspace_s(args, h);
	else if (num[n + 1] == 'd' || num[n + 1] == 'i')
		mprintspace_d(args, h);
	else if (num[n + 1] == 'c')
		mprintspace_c(args, h);
	else if (num[n + 1] == 'x')
		mprintspace_x(args, h);
	else if (num[n + 1] == 'X')
		mprintspace_X(args, h);
	else if (num[n + 1] == 'p')
		mprintspace_p(args, h);
	else if (num[n + 1] == 'u')
		mprintspace_u(args, h);
	else if (num[n + 1] == '%')
		mprintspace_pp(h);
	return (0);
}
