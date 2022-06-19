/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:34:51 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/06/11 17:20:39 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

t_format	*initialize_format(void)
{
	t_format	*f;

	f = NULL;
	f = malloc(sizeof(t_format));
	if (f != NULL)
	{
		f->specifier = '\0';
		f->flag_minus = 0;
		f->flag_hash = 0;
		f->flag_plus = 0;
		f->flag_space = 0;
		f->flag_zero = 0;
		f->flag_precision = 0;
		f->field_width = 0;
		f->field_length = 0;
	}
	return (f);
}

int	put_format(const char *str, unsigned int *ip, va_list ap, t_format *f)
{
	int	fcount;

	fcount = 0;
	(*ip)++;
	check_format(str, ip, f);
	fcount = format(ap, f);
	(*ip)++;
	return (fcount);
}

int	ft_printf(const char *str, ...)
{
	t_format		*f;
	va_list			ap;
	unsigned int	i;
	int				count;
	int				fcount;

	count = 0;
	fcount = 0;
	f = initialize_format();
	va_start(ap, str);
	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '%')
		{
			fcount = fcount + put_format(str, &i, ap, f);
			continue ;
		}
		count += write(1, (str + i++), 1);
	}
	va_end(ap);
	free(f);
	return (count + fcount);
}

// #include <stdio.h>
// #include <limits.h>
// int main (void)
// {
// 	printf("%d\n", ft_printf(" %02d ", -1));
// 	printf("%d", printf(" %02d ", -1));
// }