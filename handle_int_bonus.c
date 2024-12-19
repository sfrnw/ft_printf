/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:41:04 by asafrono          #+#    #+#             */
/*   Updated: 2024/11/07 17:23:30 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_int_prefix(t_flags *flags, int is_negative)
{
	if (is_negative)
		ft_putchar_fd('-', 1);
	else if (flags->plus)
		ft_putchar_fd('+', 1);
	else if (flags->space)
		ft_putchar_fd(' ', 1);
	else
		return (0);
	return (1);
}

static int	handle_zero_precision(t_flags *flags, int is_negative)
{
	int	count;

	count = 0;
	if (!flags->minus)
		count += print_padding(flags->width
				- (is_negative || flags->plus || flags->space), ' ');
	count += (is_negative || flags->plus || flags->space);
	if (flags->minus)
		count += print_padding(flags->width - count, ' ');
	return (count);
}

static int	calculate_padding(int len, t_flags *flags, int is_negative)
{
	int	padding;

	if (len > flags->precision)
		padding = flags->width - len
			- (is_negative || flags->plus || flags->space);
	else
		padding = flags->width - flags->precision
			- (is_negative || flags->plus || flags->space);
	return (padding);
}

static int	print_int(char *str, t_flags *flags, int len, int is_negative)
{
	int		count;
	char	pad_char;

	count = 0;
	pad_char = ' ';
	if (flags->zero && flags->precision == -1)
		pad_char = '0';
	if (flags->precision == 0 && str[0] == '0')
	{
		count += handle_zero_precision(flags, is_negative);
		return (count);
	}
	if (!flags->minus && pad_char == ' ')
		count += print_padding(calculate_padding(len, flags, is_negative), ' ');
	count += print_int_prefix(flags, is_negative);
	if (!flags->minus && pad_char == '0')
		count += print_padding(calculate_padding(len, flags, is_negative), '0');
	if (flags->precision > len - is_negative)
		count += print_padding(flags->precision - (len - is_negative), '0');
	ft_putstr_fd(str + is_negative, 1);
	count += len - is_negative;
	if (flags->minus)
		count += print_padding(calculate_padding(len, flags, is_negative), ' ');
	return (count);
}

int	handle_int_bonus(va_list args, t_flags *flags)
{
	int		num;
	char	*str;
	int		len;
	int		count;

	num = va_arg(args, int);
	str = ft_itoa(num);
	len = ft_strlen(str);
	count = print_int(str, flags, len, (num < 0));
	free(str);
	return (count);
}

// int	handle_int(va_list args)
// {
// 	int	num;

// 	num = va_arg(args, int);
// 	return (ft_putnbr(num));
// }
