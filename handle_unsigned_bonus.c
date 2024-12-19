/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:41:13 by asafrono          #+#    #+#             */
/*   Updated: 2024/11/07 17:23:25 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_unsigned(char *str, t_flags *flags, int len)
{
	int	count;

	count = 0;
	if (!flags->minus && flags->width > len && !flags->zero)
		count += print_padding(flags->width - len, ' ');
	if (!flags->minus && flags->width > len
		&& flags->zero && flags->precision == -1)
		count += print_padding(flags->width - len, '0');
	if (flags->precision > len)
		count += print_padding(flags->precision - len, '0');
	ft_putstr_fd(str, 1);
	count += len;
	if (flags->minus && flags->width > len)
		count += print_padding(flags->width - len, ' ');
	return (count);
}

int	handle_unsigned_bonus(va_list args, t_flags *flags)
{
	unsigned int	num;
	int				count;
	char			*str;
	int				len;

	num = va_arg(args, unsigned int);
	if (num == 0 && flags->precision == 0)
		str = ft_strdup("");
	else
		str = ft_utoa(num);
	len = ft_strlen(str);
	count = print_unsigned(str, flags, len);
	free(str);
	return (count);
}

// int	handle_unsigned(va_list args)
// {
// 	unsigned int	num;

// 	num = va_arg(args, unsigned int);
// 	return (ft_putnbr_base(num, "0123456789"));
// }
