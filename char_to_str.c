/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:18:57 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/06/06 10:24:43 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_to_str(int i)
{
	char	c;
	char	*ret;

	c = (char)i;
	ret = NULL;
	ret = malloc (sizeof(char) * 2);
	if (ret != NULL)
	{
		ret[0] = c;
		ret[1] = '\0';
	}
	return(ret);
}
