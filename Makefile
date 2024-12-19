# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 11:38:14 by asafrono          #+#    #+#              #
#    Updated: 2024/11/08 14:37:52 by asafrono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)
AR = ar
RM = rm -f

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = 	ft_printf.c  handle_char.c handle_format.c \
		handle_hex_lower.c handle_hex_upper.c handle_int.c handle_percent.c \
		handle_pointer.c handle_string.c handle_unsigned.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = ft_printf_bonus.c handle_char_bonus.c handle_format_bonus.c \
			handle_hex_bonus.c  handle_int_bonus.c handle_percent_bonus.c \
			handle_pointer_bonus.c handle_string_bonus.c \
			handle_unsigned_bonus.c print_padding_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(AR) rcs $(NAME) $(OBJS)
	$(AR) x $(LIBFT)
	$(AR) rcs $(NAME) *.o
	$(RM) *.o

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

bonus: .bonus

.bonus: $(BONUS_OBJS) $(LIBFT)
	$(AR) rcs $(NAME) $(BONUS_OBJS)
	$(AR) x $(LIBFT)
	$(AR) rcs $(NAME) *.o
	$(RM) *.o
	touch .bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) .bonus

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	
re: fclean all

.PHONY: all clean fclean re bonus

