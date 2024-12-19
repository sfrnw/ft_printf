/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:28:43 by asafrono          #+#    #+#             */
/*   Updated: 2024/11/05 12:28:45 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// #include <stdio.h>
// #include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
		i += ft_putchar(str[i]);
	return (i);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_putnbr_base(unsigned long long n, char *base)
{
	int					count;
	unsigned long long	base_len;

	count = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n >= base_len)
	{
		count += ft_putnbr_base(n / base_len, base);
		count += ft_putnbr_base(n % base_len, base);
	}
	else
		count += ft_putchar(base[n]);
	return (count);
}

// putnbr_base
// int main()
// {
//     char *decimal_base = "0123456789";
//     char *hex_base = "0123456789ABCDEF";
//     char *binary_base = "01";
//     printf("Decimal: ");
//     fflush(stdout);  // Ensure the label is printed before ft_putnbr_base
//     int count_dec = ft_putnbr_base(12345, decimal_base);
//     printf("\nCharacters printed: %d\n\n", count_dec);
//     printf("Hexadecimal: ");
//     fflush(stdout);  // Ensure the label is printed before ft_putnbr_base
//     int count_hex = ft_putnbr_base(255, hex_base);
//     printf("\nCharacters printed: %d\n\n", count_hex);
//     printf("Binary: ");
//     fflush(stdout);  // Ensure the label is printed before ft_putnbr_base
//     int count_bin = ft_putnbr_base(42, binary_base);
//     printf("\nCharacters printed: %d\n\n", count_bin);
//     return 0;
// }
