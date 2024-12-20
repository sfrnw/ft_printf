/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:40:49 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/20 14:14:13 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_char_bonus(va_list args, t_flags *flags)
{
	char	c;
	int		count;

	c = va_arg(args, int);
	count = 0;
	if (!flags->minus && flags->width > 1)
		count += print_padding(flags->width - 1, ' ');
	ft_putchar_fd(c, 1);
	count++;
	if (flags->minus && flags->width > 1)
		count += print_padding(flags->width - 1, ' ');
	return (count);
}
