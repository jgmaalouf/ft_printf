/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:38:08 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/06/11 13:46:37 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	padding(int size, char c)
{
	int	i;

	i = 0;
	while (i++ < size)
		ft_putchar_fd(c, 1);
}

static void	display_arg(va_list ap, t_format *f, int arg_prec)
{
	if (f->specifier == 'c')
		ft_putchar_fd((char)va_arg(ap, int), 1);
	if (f->specifier == 's')
		ft_putstr_printf(va_arg(ap, char *), f, arg_prec);
	if (f->specifier == 'p')
		ft_puthex(va_arg(ap, unsigned long), f, arg_prec);
	if (f->specifier == 'd' || f->specifier == 'i')
		ft_putnbr_printf(va_arg(ap, int), arg_prec);
	if (f->specifier == 'u')
		ft_putunbr(va_arg(ap, unsigned int), arg_prec);
	if (f->specifier == 'x')
		ft_puthex(va_arg(ap, unsigned int), f, arg_prec);
	if (f->specifier == 'X')
		ft_puthex_upper(va_arg(ap, unsigned int), f, arg_prec);
	if (f->specifier == '%')
		ft_putchar_fd('%', 1);
}

static int	format_right(va_list ap, t_format *f, int arg, int arg_prec)
{
	int		arg_width;
	int		flags;
	char	*flag;

	flag = NULL;
	flags = extra_flags(ap, f, &flag);
	arg_width = arg_with_width(f, arg_prec, flags);
	if (f->flag_zero)
	{
		ft_putstr_fd(flag, 1);
		padding(arg_width - (arg_prec + flags), '0');
	}
	else
	{
		padding(arg_width - (arg_prec + flags), ' ');
		ft_putstr_fd(flag, 1);
	}
	padding(arg_prec - arg, '0');
	display_arg(ap, f, arg_prec);
	return (arg_width);
}

static int	format_left(va_list ap, t_format *f, int arg, int arg_prec)
{
	int		arg_width;
	int		flags;
	char	*flag;

	flag = NULL;
	flags = extra_flags(ap, f, &flag);
	arg_width = arg_with_width(f, arg_prec, flags);
	ft_putstr_fd(flag, 1);
	if (ft_strchr_printf("diuxX", f->specifier) != NULL)
		padding(arg_prec - arg, '0');
	display_arg(ap, f, arg_prec);
	padding(arg_width - (arg_prec + flags), ' ');
	return (arg_width);
}

int	format(va_list ap, t_format *f)
{
	int		fcount;
	int		arg;
	int		arg_prec;

	arg = arg_size(ap, f);
	arg_prec = arg;
	if (f->flag_precision)
		arg_prec = arg_with_prec(ap, f, arg);
	if (f->flag_minus)
		fcount = format_left(ap, f, arg, arg_prec);
	else
		fcount = format_right(ap, f, arg, arg_prec);
	return (fcount);
}
