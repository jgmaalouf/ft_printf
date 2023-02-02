/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:42:38 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/06/11 13:50:01 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
	while (i >= 0)
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
		return (write(1, null, arg_prec));
	if (f->specifier == 'c' && ft_strncmp("\0", s, 2) == 0)
		return (write(1, &null_char, 1));
	return (write(1, s, arg_prec));
}

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
	return (ret);
}
