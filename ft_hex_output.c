/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:01:17 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/06/09 09:28:57 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long n, t_format *f)
{
	char	*hex_str;

	hex_str = hex_conversion(n, f);
	if (n == 0 && (f->specifier == 'x' || f->specifier == 'X'))
		ft_putchar_fd('0', 1);
	else
		ft_putstr_fd(hex_str, 1);
	if (hex_str != NULL)
		free(hex_str);
}

void	ft_puthex_upper(unsigned long n, t_format *f)
{
	char	*hex_str;

	hex_str = hex_conversion(n, f);
	ft_putstr_fd(ft_strtoupper(hex_str), 1);
	if (hex_str != NULL)
		free(hex_str);
}