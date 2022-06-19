/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:42:38 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/06/09 14:31:10 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_strlen_printf(const char *s, t_format *f)
{
	int	i;

	if (f->specifier == 'c')
		if (s[0] == '\0')
			return (1);
	if (s == NULL)
		return (6);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strtoupper(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while(i >= 0)
	{
		str[i] = ft_toupper(str[i]);
		i--;
	}
	return (str);
}

char	*ft_strchr_printf(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

int	ft_putstr_printf(char *s, t_format *f, int arg_prec)
{
	char	*null;
	char	null_char;

	null = "(null)";
	null_char = '\0';
	if (s == NULL)
		return (write(1, null, ft_strlen(null)));
	if (f->specifier == 'c' && ft_strncmp("\0", s, 2) == 0)
		return(write(1, &null_char, 1));
	return (write(1, s, arg_prec));
}

void	ft_putunbr(unsigned int n)
{
	char	c;

	if (n >= 10)
		ft_putunbr(n / 10);
	n = n % 10;
	c = n + '0';
	write(1, &c, 1);
}

void	ft_putnbr_printf(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "2147483648", 10);
		return ;
	}
	if (n < 0)
		n = -n;
	if (n >= 10)
		ft_putnbr_printf(n / 10);
	n = n % 10;
	c = n + '0';
	write(1, &c, 1);
}
