/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:55:16 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/06/02 12:03:44 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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