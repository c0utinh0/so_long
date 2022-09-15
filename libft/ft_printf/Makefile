# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 11:17:28 by dcoutinh          #+#    #+#              #
#    Updated: 2022/09/15 20:06:56 by dcoutinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -I . -c

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

AR = ar -rcs

RM = rm -rf

SRCS =  ft_choice_param.c	\
		ft_pf_strlen.c		\
		ft_print_char.c		\
		ft_print_int.c		\
		ft_print_p.c		\
		ft_print_str.c	\
		ft_printf.c	\
		ft_print_u.c	\
		ft_print_x.c	\
		ft_pf_putchar.c	
		
OBJS = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME): $(OBJS) 
	@$(AR) $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
