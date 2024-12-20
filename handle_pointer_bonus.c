/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:41:08 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/20 14:14:32 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_pointer_bonus(va_list args)
{
	void	*ptr;
	int		count;
	char	*str;

	ptr = va_arg(args, void *);
	count = 0;
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	str = ft_utoa_base((unsigned long)ptr, 16, 0);
	ft_putstr_fd("0x", 1);
	count += 2;
	ft_putstr_fd(str, 1);
	count += ft_strlen(str);
	free(str);
	return (count);
}
