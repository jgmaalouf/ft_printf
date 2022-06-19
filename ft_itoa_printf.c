/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:42:30 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/06/07 17:03:24 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	n_digits(long long n)
{
	int		len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	res(int len, int nb, char *char_int)
{
	int	i;

	i = 0;
	while (len > 0)
	{
		char_int[len - 1] = (nb % 10) + '0';
		nb = nb - (nb % 10);
		nb = nb / 10;
		i++;
		len--;
	}
	return (i);
}

char	*ft_itoa_printf(int n)
{
	char	*char_int;
	int		len;

	if (n == INT_MIN)
		return (strdup("2147483648"));
	char_int = NULL;
	len = n_digits(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		n *= -1;
	char_int = (char *)malloc(sizeof(char) * (len + 1));
	if (char_int == NULL)
		return (NULL);
	char_int[res(len, n, char_int)] = '\0';
	return (char_int);
}
