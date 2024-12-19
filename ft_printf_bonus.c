/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:54:18 by asafrono          #+#    #+#             */
/*   Updated: 2024/11/07 17:32:05 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_format(va_list args, const char *format)
{
	int			count;
	t_flags		flags;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			initialize_flags(&flags);
			parse_flags(&format, &flags);
			count += handle_format_bonus(*format, args, &flags);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			count++;
		}
		format++;
	}
	return (count);
}

void	initialize_flags(t_flags *flags)
{
	flags->width = 0;
	flags->precision = -1;
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
}

static void	parse_width_precision(const char **format, t_flags *flags)
{
	if (**format == '.')
		flags->precision = 0;
	else
		flags->width = 0;
	while (**format == '.' || (**format >= '0' && **format <= '9'))
	{
		if (**format == '.')
			flags->precision = 0;
		else if (flags->precision >= 0)
			flags->precision = flags->precision * 10 + (**format - '0');
		else
			flags->width = flags->width * 10 + (**format - '0');
		(*format)++;
	}
}

void	parse_flags(const char **format, t_flags *flags)
{
	initialize_flags(flags);
	while (**format)
	{
		if (**format == '-')
			flags->minus = 1;
		else if (**format == '0' && flags->width == 0)
			flags->zero = 1;
		else if (**format == '#')
			flags->hash = 1;
		else if (**format == ' ')
			flags->space = 1;
		else if (**format == '+')
			flags->plus = 1;
		else if (**format == '.' || (**format >= '0' && **format <= '9'))
		{
			parse_width_precision(format, flags);
			continue ;
		}
		else
			break ;
		(*format)++;
	}
	if (flags->minus)
		flags->zero = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = process_format(args, format);
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	// Test cases
// 	int count_printf;
// 	int count_ft_printf;
// 	// Test 1: Simple strings
// 	printf("Test 1: Simple strings\n");
// 	printf("Standard printf:\n");
// 	count_printf = printf("Hello, World!\n");
// 	printf("Characters printed: %d\n\n", count_printf);
// 	printf("Custom ft_printf:\n");
// 	count_ft_printf = ft_printf("Hello, World!\n");
// 	printf("Characters printed: %d\n\n", count_ft_printf);
// 	// Test 2: Characters
// 	char c = 'A';
// 	printf("Test 2: Single character\n");
// 	printf("Standard printf:\n");
// 	count_printf = printf("Character: %c\n", c);
// 	printf("Characters printed: %d\n\n", count_printf);
// 	printf("Custom ft_printf:\n");
// 	count_ft_printf = ft_printf("Character: %c\n", c);
// 	printf("Characters printed: %d\n\n", count_ft_printf);
// 	// Test 3: Strings with NULL
// 	char *null_str = NULL;
// 	printf("Test 3: String with NULL pointer\n");
// 	printf("Standard printf:\n");
// 	count_printf = printf("String: %s\n", null_str);
// 	printf("Characters printed: %d\n\n", count_printf);
// 	printf("Custom ft_printf:\n");
// 	count_ft_printf = ft_printf("String: %s\n", null_str);
// 	printf("Characters printed: %d\n\n", count_ft_printf);
// 	// Test 4: Integers
// 	int num = -12345;
// 	printf("Test 4: Negative integer\n");
// 	printf("Standard printf:\n");
// 	count_printf = printf("Integer: %d\n", num);
// 	printf("Characters printed: %d\n\n", count_printf);
// 	printf("Custom ft_printf:\n");
// 	count_ft_printf = ft_printf("Integer: %d\n", num);
// 	printf("Characters printed: %d\n\n", count_ft_printf);
// 	// Test 5: Unsigned integers
// 	unsigned int u_num = 12345;
// 	printf("Test 5: Unsigned integer\n");
// 	printf("Standard printf:\n");
// 	count_printf = printf("Unsigned Integer: %u\n", u_num);
// 	printf("Characters printed: %d\n\n", count_printf);
// 	printf("Custom ft_printf:\n");
// 	count_ft_printf = ft_printf("Unsigned Integer: %u\n", u_num);
// 	printf("Characters printed: %d\n\n", count_ft_printf);
// 	// Test 6: Hexadecimal (lowercase)
// 	unsigned int hex_num = 255;
// 	printf("Test 6: Hexadecimal (lowercase)\n");
// 	printf("Standard printf:\n");
// 	count_printf = printf("Hexadecimal (lowercase): %x\n", hex_num);
// 	printf("Characters printed: %d\n\n", count_printf);
// 	printf("Custom ft_printf:\n");
// 	count_ft_printf = ft_printf("Hexadecimal (lowercase): %x\n", hex_num);
// 	printf("Characters printed: %d\n\n", count_ft_printf);
// 	// Test 7: Hexadecimal (uppercase)
// 	printf("Test 7: Hexadecimal (uppercase)\n");
// 	printf("Standard printf:\n");
// 	count_printf = printf("Hexadecimal (uppercase): %X\n", hex_num);
// 	printf("Characters printed: %d\n\n", count_printf);
// 	printf("Custom ft_printf:\n");
// 	count_ft_printf = ft_printf("Hexadecimal (uppercase): %X\n", hex_num);
// 	printf("Characters printed: %d\n\n", count_ft_printf);
// 	// Test 8: Pointer
// 	int a = 42;
// 	int *ptr = &a;
// 	printf("Test 8: Pointer address\n");
// 	printf("Standard printf:\n");
// 	count_printf = printf("Pointer address: %p\n", (void *)ptr);
// 	printf("Characters printed: %d\n\n", count_printf);
// 	printf("Custom ft_printf:\n");
// 	count_ft_printf = ft_printf("Pointer address: %p\n", (void *)ptr);
// 	printf("Characters printed: %d\n\n", count_ft_printf); 
// 	// Test 9: Percent sign
// 	printf("Test 9: Percent sign output\n");
// 	printf("Standard printf:\n");
// 	count_printf = printf("Percent sign: %%\n");
// 	printf("\nCharacters printed: %d\n\n", count_printf);
// 	printf("Custom ft_printf:\n");
// 	count_ft_printf = ft_printf("Percent sign: %%\n"); 
// 	printf("\nCharacters printed: %d\n\n", count_ft_printf); 
// 	// Test 10: Null pointers
// 	printf("Test 10: Null pointers\n");
// 	printf("Standard printf:\n");
// 	count_printf = printf(" %p %p ", NULL, NULL);
// 	printf("\nCharacters printed: %d\n\n", count_printf);
// 	printf("Custom ft_printf:\n");
// 	count_ft_printf = ft_printf(" %p %p ", NULL, NULL);
// 	printf("\nCharacters printed: %d\n\n", count_ft_printf);
// 	// Test 11: Field width and left-align flag
// 	printf("Test 11: Field width and left-align flag\n");
// 	printf("Standard printf:\n");
// 	count_printf = printf("'%-10d'\n", 42);
// 	printf("Characters printed: %d\n\n", count_printf);
// 	printf("Custom ft_printf:\n");
// 	count_ft_printf = ft_printf("'%-10d'\n", 42);
// 	printf("Characters printed: %d\n\n", count_ft_printf);
//     // Test 12: Field width and zero-padding
// 	printf("Test 12: Field width and zero-padding\n");
// 	printf("Standard printf:\n");
// 	count_printf = printf("'%010d'\n", 42);
// 	printf("Characters printed: %d\n\n", count_printf);
// 	printf("Custom ft_printf:\n");
// 	count_ft_printf = ft_printf("'%010d'\n", 42);
// 	printf("Characters printed: %d\n\n", count_ft_printf);
//     // Test 13: Precision with integers
// 	printf("Test 13: Precision with integers\n");
// 	printf("Standard printf:\n");
// 	count_printf = printf("'%.5d'\n", 42);
// 	printf("Characters printed: %d\n\n", count_printf);
// 	printf("Custom ft_printf:\n");
// 	count_ft_printf = ft_printf("'%.5d'\n", 42);
// 	printf("Characters printed: %d\n\n", count_ft_printf);
//     // Test 14: Precision with strings
// 	printf("Test 14: Precision with strings\n");
// 	printf("Standard printf:\n");
// 	count_printf = printf("'%.3s'\n", "Hello");
// 	printf("Characters printed: %d\n\n", count_printf);
// 	printf("Custom ft_printf:\n");
// 	count_ft_printf = ft_printf("'%.3s'\n", "Hello");
// 	printf("Characters printed: %d\n\n", count_ft_printf);
//     // Test 15: Hash flag with hexadecimal
// 	printf("Test 15: Hash flag with hexadecimal\n");
// 	printf("Standard printf:\n");
// 	count_printf = printf("'%#x'\n", 42);
// 	printf("Characters printed: %d\n\n", count_printf);
// 	printf("Custom ft_printf:\n");
// 	count_ft_printf = ft_printf("'%#x'\n", 42);
// 	printf("Characters printed: %d\n\n", count_ft_printf);
//     // Test 16: Plus flag with positive numbers
// 	printf("Test 16: Plus flag with positive numbers\n");
// 	printf("Standard printf:\n");
// 	count_printf = printf("'%+d'\n", 42);
// 	printf("Characters printed: %d\n\n", count_printf);
// 	printf("Custom ft_printf:\n");
// 	count_ft_printf = ft_printf("'%+d'\n", 42);
// 	printf("Characters printed: %d\n\n", count_ft_printf);
//     // Test 17: Space flag with positive numbers
// 	printf("Test 17: Space flag with positive numbers\n");
// 	printf("Standard printf:\n");
// 	count_printf = printf("'% d'\n", 42);
// 	printf("Characters printed: %d\n\n", count_printf);
// 	printf("Custom ft_printf:\n");
// 	count_ft_printf = ft_printf("'% d'\n", 42);
// 	printf("Characters printed: %d\n\n", count_ft_printf);
//     // Test 18: Combination of flags
// 	printf("Test 18: Combination of flags\n");
// 	printf("Standard printf:\n");
// 	count_printf = printf("'%#-15.10x'\n", 42);
// 	printf("Characters printed: %d\n\n", count_printf);
// 	printf("Custom ft_printf:\n");
// 	count_ft_printf = ft_printf("'%#-15.10x'\n", 42);
// 	printf("Characters printed: %d\n\n", count_ft_printf);
// 	return (0);
// }

// cc -Wall -Wextra -Werror
// -I./libft ft_printf_bonus.c handle_char_bonus.c handle_format_bonus.c handle_hex_bonus.c 
// handle_int_bonus.c handle_percent_bonus.c handle_pointer_bonus.c handle_string_bonus.c
// handle_unsigned_bonus.c print_padding_bonus.c ./libft/libft.a && ./a.out

// void parse_flags(const char **format, t_flags *flags)
// {
//     initialize_flags(flags);  // Reset flags before parsing

//     while (**format)
//     {
//         if (**format == '-')
//             flags->minus = 1;
//         else if (**format == '0' && flags->width == 0)
//             flags->zero = 1;
//         else if (**format == '#')
//             flags->hash = 1;
//         else if (**format == ' ')
//             flags->space = 1;
//         else if (**format == '+')
//             flags->plus = 1;
//         else if (**format == '.' || (**format >= '0' && **format <= '9'))
//         {
//             if (**format == '.')
//                 flags->precision = 0;
//             else
//                 flags->width = 0;

//             while (**format == '.' || (**format >= '0' && **format <= '9'))
//             {
//                 if (**format == '.')
//                     flags->precision = 0;
//                 else if (flags->precision >= 0)
//      flags->precision = flags->precision * 10 + (**format - '0');
//                 else
//                     flags->width = flags->width * 10 + (**format - '0');
//                 (*format)++;
//             }
//             continue;
//         }
//         else
//             break;
//         (*format)++;
//     }

//     if (flags->minus)
//         flags->zero = 0;  // '-' flag overrides '0' flag
// }

// int main(void)
// {
//     ft_printf("Basic Tests:\n");
// 	printf("|%d|%i|%u|%x|%X|%c|%s|%p|%%|\n", 
//               42, -42, 42, 42, 42, 'A', "hello", (void *)0x42);
//     ft_printf("|%d|%i|%u|%x|%X|%c|%s|%p|%%|\n", 
//               42, -42, 42, 42, 42, 'A', "hello", (void *)0x42);
//     ft_printf("\nField Width Tests:\n");
// 	printf("|%5d|%10d|%-10d|%3d|\n", 
//               42, 42, 42, 42);
//     ft_printf("|%5d|%10d|%-10d|%3d|\n", 
//               42, 42, 42, 42);
//     ft_printf("\nZero Padding Tests:\n");
// 	printf("|%05d|%010d|%03d|\n", 
//               42, 42, 42);
//     ft_printf("|%05d|%010d|%03d|\n", 
//               42, 42, 42);
//     ft_printf("\nPrecision Tests:\n");
// 	printf("|%.5d|%.2d|%.0d|%.5s|%.2s|\n", 
//               42, 42, 0, "hello", "world");
//     ft_printf("|%.5d|%.2d|%.0d|%.5s|%.2s|\n", 
//               42, 42, 0, "hello", "world");
//     ft_printf("\nCombined Flag Tests:\n");
// 	printf("|%+10.5d|%-10.5d|%010.5d|\n", 
//               42, 42, 42);
//     ft_printf("|%+10.5d|%-10.5d|%010.5d|\n", 
//               42, 42, 42);
//     ft_printf("\nEdge Cases:\n");
// 	printf("|%d|%u|%x|\n", INT_MAX, UINT_MAX, 0);
//     ft_printf("|%d|%u|%x|\n", INT_MAX, UINT_MAX, 0);
//     return (0);
// }