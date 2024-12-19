/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:26:08 by asafrono          #+#    #+#             */
/*   Updated: 2024/11/06 15:51:45 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_padding(int width, char pad_char)
{
	int	count;

	count = 0;
	while (width > 0)
	{
		ft_putchar_fd(pad_char, 1);
		count++;
		width--;
	}
	return (count);
}
