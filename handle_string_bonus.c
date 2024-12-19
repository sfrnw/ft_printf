/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:41:11 by asafrono          #+#    #+#             */
/*   Updated: 2024/11/07 17:23:27 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_string_bonus(va_list args, t_flags *flags)
{
	char	*str;
	int		count;
	int		len;

	str = va_arg(args, char *);
	count = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags->precision >= 0 && flags->precision < len)
		len = flags->precision;
	if (!flags->minus && flags->width > len)
		count += print_padding(flags->width - len, ' ');
	count += write(1, str, len);
	if (flags->minus && flags->width > len)
		count += print_padding(flags->width - len, ' ');
	return (count);
}
