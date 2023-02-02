/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:39:25 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/06/11 13:53:03 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	check_specifier(const char *str, unsigned int *ip, t_format *f)
{
	while ((ft_strchr("-0.# +", str[*ip]) != NULL
			&& str[*ip] != '\0') || ft_isdigit(str[*ip]))
		(*ip)++;
	if (ft_strchr("cspdiuxX%", str[*ip]) != NULL && str[*ip] != '\0')
	{
		f->specifier = str[*ip];
		return ;
	}
	(*ip)--;
}

static void	check_flags(const char *str, unsigned int *jp, t_format *f)
{
	while (ft_strchr("-0# +", str[*jp]) != NULL)
	{
		if (str[*jp] == '0')
			f->flag_zero++;
		if (str[*jp] == '-')
			f->flag_minus++;
		if (str[*jp] == '#')
			f->flag_hash++;
		if (str[*jp] == ' ')
			f->flag_space++;
		if (str[*jp] == '+')
			f->flag_plus++;
		(*jp)++;
	}
}

static void	check_width(const char *str, unsigned int *jp, t_format *f)
{
	f->field_width = ft_atoi(str + (*jp));
	while (ft_isdigit(str[*jp]))
		(*jp)++;
}

static void	check_precision(const char *str, unsigned int *jp, t_format *f)
{
	if (str[*jp] == '.')
	{
		f->flag_precision++;
		(*jp)++;
		f->field_length = ft_atoi(str + (*jp));
		while (ft_isdigit(str[*jp]))
			(*jp)++;
	}
}

void	check_format(const char *str, unsigned int *ip, t_format *f)
{
	unsigned int	j;

	j = *ip;
	check_specifier(str, ip, f);
	check_flags(str, &j, f);
	check_width(str, &j, f);
	check_precision(str, &j, f);
	if ((f->flag_minus != 0 && f->flag_zero != 0)
		|| (f->flag_precision != 0 && f->flag_zero != 0))
		f->flag_zero = 0;
	if (f->flag_plus != 0 && f->flag_space != 0)
		f->flag_space = 0;
	if (f->field_length < 0)
		f->field_length = 0;
}
