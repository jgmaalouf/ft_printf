/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 08:03:33 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/06/11 14:05:46 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct s_format
{
	char	specifier;
	int		flag_minus;
	int		flag_hash;
	int		flag_plus;
	int		flag_space;
	int		flag_zero;
	int		flag_precision;
	int		field_width;
	int		field_length;
}			t_format;

int		ft_printf(const char *s, ...);
int		ft_putstr_printf(char *s, t_format *f, int arg_prec);
void	check_format(const char *str, unsigned int *ip, t_format *f);
int		format(va_list ap, t_format *f);
void	ft_putunbr(unsigned int n, int arg_prec);
void	ft_putnbr_printf(int n, int arg_prec);
char	*ft_strtoupper(char *str);
char	*hex_conversion(unsigned long n, t_format *f);
char	*ft_itoa_printf(int n);
char	*ft_uitoa(unsigned int n);
char	*char_to_str(int i);
char	*ft_strchr_printf(const char *s, int c);
int		ft_strlen_printf(const char *s, t_format *f);
void	ft_puthex_upper(unsigned long n, t_format *f, int arg_prec);
void	ft_puthex(unsigned long n, t_format *f, int arg_prec);
int		extra_flags(va_list ap, t_format *f, char **flag);
int		arg_size(va_list ap, t_format *f);
int		arg_with_prec(va_list ap, t_format *f, int arg);
int		arg_with_width(t_format *f, int arg_with_precision, int flags);

#endif