/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 07:57:01 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/06/05 18:48:27 by jmaalouf         ###   ########.fr       */
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

static int	res(int len, long nb, char *char_int)
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

char	*ft_uitoa(unsigned int n)
{
	char	*char_int;
	int		len;
	long	nb;

	char_int = NULL;
	nb = n;
	len = n_digits(n);
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb > 0)
	{
		char_int = (char *)malloc(sizeof(char) * (len + 1));
		if (char_int == NULL)
			return (NULL);
		char_int[res(len, nb, char_int)] = '\0';
	}
	return (char_int);
}
