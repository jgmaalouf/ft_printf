/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:06:04 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/06/11 13:48:14 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	hex_num(int n)
{
	if (n == 10)
		return ('a');
	if (n == 11)
		return ('b');
	if (n == 12)
		return ('c');
	if (n == 13)
		return ('d');
	if (n == 14)
		return ('e');
	if (n == 15)
		return ('f');
	return (n + '0');
}

char	*ret(char *str, unsigned int i)
{
	char	*ret;

	ret = NULL;
	ret = malloc(sizeof(char) * i + 1);
	if (ret != NULL)
		ft_strlcpy(ret, str + i + 1, 100 - i);
	return (ret);
}

char	*hex_conversion(unsigned long n, t_format *f)
{
	char			str[100];
	unsigned int	i;

	i = 98;
	if (n == 0 && (f->specifier == 'x' || f->specifier == 'X'))
		return (ft_strdup("0"));
	if (n == 0 && (f->specifier == 'p'))
		return (ft_strdup("0x0"));
	while (n != 0)
	{
		str[i] = hex_num((int)(n % 16));
		i--;
		n = n / 16;
	}
	if (f->specifier == 'p')
	{
		str[i--] = 'x';
		str[i--] = '0';
	}
	str[99] = '\0';
	return (ret(str, i));
}
