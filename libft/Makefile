# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 12:01:24 by dcoutinh          #+#    #+#              #
#    Updated: 2022/09/15 19:59:40 by dcoutinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

AR = ar -rcs

SRCS =  ft_isalpha.c	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_strlen.c		\
		ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strncmp.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strnstr.c	\
		ft_atoi.c		\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_split.c		\
		ft_itoa.c		\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_striteri.c	\
		ft_strmapi.c	\
		get_next_line.c	\
		get_next_line_bonus.c	\
		get_next_line_utils.c	\
		get_next_line_utils_bonus.c	\

OBJS = $(SRCS:.c=.o)

PF = make -C ft_printf && cp ft_printf/libftprintf.a $(NAME)

CPF = make -C ft_printf clean

FCPF = make -C ft_printf fclean

all: $(NAME) 

$(NAME): $(OBJS) 
	@$(AR) $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	@$(PF)
	@$(CC) -I . -c $(CFLAGS) $(SRCS)

clean:
	@$(RM) $(OBJS)
	@$(CPF)

fclean: clean
	@$(RM) $(NAME)
	@$(FCPF)

re: fclean all

.PHONY: all clean fclean re
