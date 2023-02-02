/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:34:01 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/06/11 13:50:21 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putunbr(unsigned int n, int arg_prec)
{
	char	c;

	if (arg_prec == 0)
		return ;
	if (n >= 10)
		ft_putunbr(n / 10, arg_prec--);
	n = n % 10;
	c = n + '0';
	write(1, &c, 1);
}

void	ft_putnbr_printf(int n, int arg_prec)
{
	char	c;

	if (arg_prec == 0)
		return ;
	if (n == -2147483648)
	{
		write(1, "2147483648", 10);
		return ;
	}
	if (n < 0)
		n = -n;
	if (n >= 10)
		ft_putnbr_printf(n / 10, arg_prec--);
	n = n % 10;
	c = n + '0';
	write(1, &c, 1);
}

void	ft_puthex(unsigned long n, t_format *f, int arg_prec)
{
	char	*hex_str;

	if (n == 0 && arg_prec == 0)
		return ;
	hex_str = hex_conversion(n, f);
	if (n == 0 && f->specifier == 'x')
		ft_putchar_fd('0', 1);
	else
		ft_putstr_fd(hex_str, 1);
	if (hex_str != NULL)
		free(hex_str);
}

void	ft_puthex_upper(unsigned long n, t_format *f, int arg_prec)
{
	char	*hex_str;

	if (n == 0 && arg_prec == 0)
		return ;
	hex_str = hex_conversion(n, f);
	if (n == 0 && f->specifier == 'X')
		ft_putchar_fd('0', 1);
	else
		ft_putstr_fd(ft_strtoupper(hex_str), 1);
	if (hex_str != NULL)
		free(hex_str);
}
