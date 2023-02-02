/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:05:32 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/06/11 14:23:42 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	arg_size(va_list ap, t_format *f)
{
	va_list	ap_copy;
	int		ret;
	char	*arg;

	*ap_copy = *ap;
	ret = 0;
	if (f->specifier == 'c')
		arg = char_to_str(va_arg(ap_copy, int));
	if (f->specifier == 's')
		arg = ft_strdup(va_arg(ap_copy, char *));
	if (f->specifier == 'p')
		arg = hex_conversion(va_arg(ap_copy, unsigned long), f);
	if (f->specifier == 'd' || f->specifier == 'i')
		arg = ft_itoa_printf(va_arg(ap_copy, int));
	if (f->specifier == 'u')
		arg = ft_uitoa(va_arg(ap_copy, unsigned int));
	if (f->specifier == 'x' || f->specifier == 'X')
		arg = hex_conversion(va_arg(ap_copy, unsigned int), f);
	if (f->specifier == '%')
		arg = ft_strdup("%");
	ret = ft_strlen_printf(arg, f);
	free(arg);
	return (ret);
}

int	arg_with_prec(va_list ap, t_format *f, int arg)
{
	va_list	ap_copy;
	char	*str;

	*ap_copy = *ap;
	if (ft_strchr_printf("diuxX", f->specifier) != NULL)
	{
		if (va_arg(ap_copy, unsigned int) == 0 && arg == 1)
			arg = 0;
		if (f->field_length <= arg)
			return (arg);
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

int	arg_with_width(t_format *f, int arg_with_precision, int flags)
{
	if (f->field_width >= (arg_with_precision + flags))
		return (f->field_width);
	return (arg_with_precision + flags);
}

static int	hash_flag(va_list ap_copy, t_format *f, char **flag)
{
	if (va_arg(ap_copy, unsigned int) == 0)
		return (0);
	if (f->specifier == 'x')
		*flag = "0x";
	if (f->specifier == 'X')
		*flag = "0X";
	return (2);
}

int	extra_flags(va_list ap, t_format *f, char **flag)
{
	va_list	ap_copy;

	*ap_copy = *ap;
	if ((f->flag_hash && ft_strchr_printf("xX", f->specifier) != NULL))
		return (hash_flag(ap_copy, f, flag));
	if (ft_strchr_printf("di", f->specifier) != NULL)
	{
		if (va_arg(ap_copy, int) < 0)
		{
			*flag = "-";
			return (1);
		}
	}
	if ((f->flag_plus || f->flag_space)
		&& ft_strchr_printf("di", f->specifier) != NULL)
	{
		if (f->flag_space)
			*flag = " ";
		else
			*flag = "+";
		return (1);
	}
	va_end(ap_copy);
	return (0);
}
