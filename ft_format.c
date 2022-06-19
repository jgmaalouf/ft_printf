/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:05:32 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/06/09 17:36:25 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	arg_size(va_list ap, t_format *f)
{
	va_list	ap_copy;
	int		ret;
	char	*arg;

	*ap_copy = *ap;
	ret = 0;
	if(f->specifier == 'c')
		arg = char_to_str(va_arg(ap_copy, int));
	if(f->specifier == 's')
		arg = ft_strdup(va_arg(ap_copy, char*));
	if(f->specifier == 'p')
		arg = hex_conversion(va_arg(ap_copy, unsigned long), f);
	if(f->specifier == 'd' || f->specifier == 'i')
		arg = ft_itoa_printf(va_arg(ap_copy, int));
	if(f->specifier == 'u')
		arg = ft_uitoa(va_arg(ap_copy, unsigned int));
	if(f->specifier == 'x' || f->specifier == 'X')
		arg = hex_conversion(va_arg(ap_copy, unsigned int), f);
	if(f->specifier == '%')
		arg = ft_strdup("%");
	ret = ft_strlen_printf(arg, f);
	free(arg);
	return (ret);
}

static int	arg_with_prec(va_list ap, t_format *f, int arg)
{
	va_list	ap_copy;
	char	*str;

	*ap_copy = *ap;
	if (ft_strchr_printf("diuxX", f->specifier) != NULL)
	{
		if (f->field_length <= arg)
			return(arg);
	}
	if (f->specifier == 's')
	{
		str = va_arg(ap_copy, char *);
		if (f->field_length > ft_strlen_printf(str, f))
			return (ft_strlen_printf(str, f));
	}
	va_end(ap_copy);
	return (f->field_length);
}

static int	arg_with_width(t_format *f, int arg_with_precision, int flags)
{
	if (f->field_width >= (arg_with_precision + flags))
		return (f->field_width);
	return(arg_with_precision + flags);
}

static int	extra_flags(va_list ap, t_format *f, char **flag)
{
	va_list	ap_copy;

	*ap_copy = *ap;
	if ((f->flag_hash && ft_strchr_printf("xX", f->specifier) != NULL))
	{
		if (f->specifier == 'x')
			*flag = "0x";
		if (f->specifier == 'X')
			*flag = "0X";
		return (2);
	}
	if ((f->flag_plus || f->flag_space) && ft_strchr_printf("di", f->specifier) != NULL)
	{
		if (f->flag_space)
			*flag = " ";
		else
			*flag = "+";
		return(1);
	}
	if (ft_strchr_printf("di", f->specifier) != NULL)
	{
		if(va_arg(ap_copy, int) < 0)
		{
			*flag = "-";
			return (1);
		}
	}
	va_end(ap_copy);
	return (0);
}

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
		ft_puthex(va_arg(ap, unsigned long), f);
	if (f->specifier == 'd' || f->specifier == 'i')
		ft_putnbr_printf(va_arg(ap, int));
	if (f->specifier == 'u')
		ft_putunbr(va_arg(ap, unsigned int));
	if (f->specifier == 'x')
		ft_puthex(va_arg(ap, unsigned int), f);
	if (f->specifier == 'X')
		ft_puthex_upper(va_arg(ap, unsigned int), f);
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
	return(arg_width);
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
	return(arg_width);
}

int		format(va_list ap, t_format *f)
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
