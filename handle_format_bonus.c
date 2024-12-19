/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:40:55 by asafrono          #+#    #+#             */
/*   Updated: 2024/11/07 17:23:32 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format_bonus(char specifier, va_list args, t_flags *flags)
{
	if (specifier == 'c')
		return (handle_char_bonus(args, flags));
	else if (specifier == 's')
		return (handle_string_bonus(args, flags));
	else if (specifier == 'p')
		return (handle_pointer_bonus(args));
	else if (specifier == 'd' || specifier == 'i')
		return (handle_int_bonus(args, flags));
	else if (specifier == 'u')
		return (handle_unsigned_bonus(args, flags));
	else if (specifier == 'x')
		return (handle_hex_lower_bonus(args, flags));
	else if (specifier == 'X')
		return (handle_hex_upper_bonus(args, flags));
	else if (specifier == '%')
		return (handle_percent_bonus(flags));
	return (0);
}
