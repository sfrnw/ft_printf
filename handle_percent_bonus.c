/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:41:06 by asafrono          #+#    #+#             */
/*   Updated: 2024/11/07 17:23:29 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_percent_bonus(t_flags *flags)
{
	int		count;
	char	pad_char;

	count = 0;
	pad_char = ' ';
	if (flags->zero)
		pad_char = '0';
	if (!flags->minus && flags->width > 1)
		count += print_padding(flags->width - 1, pad_char);
	ft_putchar_fd('%', 1);
	count++;
	if (flags->minus && flags->width > 1)
		count += print_padding(flags->width - 1, ' ');
	return (count);
}

// int	handle_percent(void)
// {
// 	return (ft_putchar('%'));
// }
