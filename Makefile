# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 16:32:52 by dcoutinh          #+#    #+#              #
#    Updated: 2022/09/06 12:49:55 by dcoutinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = so_long

CFLAGS = -Wall -Wextra -Werror

INCLUDE = -L ./mlx -lmlx -framework OpenGL -framework AppKit

SRCS =  so_long.c	\

OBJS = $(SRCS:.c=.o)

LIBFT = make -C libft && cp libft/libft.a $(NAME)

CLIBFT = make -C libft clean

FCLIBFT = make -C libft fclean

MLX = make -C mlx

CMLX = make -C mlx clean

all: $(NAME)

$(NAME): $(SRC)
	$(MLX)
	$(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) $(INCLUDE) -o $(NAME) 

clean:
	rm -f $(OBJS)
	$(CLIBFT)
	$(CMLX)

fclean:
	rm -f $(NAME)
	$(FCLIBFT)
	$(CMLX)

re: fclean all

.PHONY: all clean fclean re
