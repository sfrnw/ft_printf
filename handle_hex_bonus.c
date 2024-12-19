/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:30:00 by asafrono          #+#    #+#             */
/*   Updated: 2024/11/07 17:23:31 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_prefix(unsigned int num, t_flags *flags, int uppercase)
{
	int		count;
	char	*prefix;

	count = 0;
	if (flags->hash && num != 0)
	{
		if (uppercase)
			prefix = "0X";
		else
			prefix = "0x";
		ft_putstr_fd(prefix, 1);
		count += 2;
	}
	return (count);
}

static int	print_hex(unsigned int num, t_flags *flags, int uppercase)
{
	int		count;
	char	*str;
	int		len;

	str = ft_utoa_base(num, 16, uppercase);
	len = ft_strlen(str);
	count = print_hex_prefix(num, flags, uppercase);
	if (!flags->minus && flags->width > len)
		count += print_padding(flags->width - len, ' ');
	if (flags->precision > len)
		count += print_padding(flags->precision - len, '0');
	ft_putstr_fd(str, 1);
	count += len;
	free(str);
	if (flags->minus && flags->width > len)
		count += print_padding(flags->width - len - flags->precision, ' ');
	return (count);
}

int	handle_hex_bonus(va_list args, t_flags *flags, int uppercase)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	return (print_hex(num, flags, uppercase));
}

int	handle_hex_lower_bonus(va_list args, t_flags *flags)
{
	return (handle_hex_bonus(args, flags, 0));
}

int	handle_hex_upper_bonus(va_list args, t_flags *flags)
{
	return (handle_hex_bonus(args, flags, 1));
}
