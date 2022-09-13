# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 16:32:52 by dcoutinh          #+#    #+#              #
#    Updated: 2022/09/13 18:03:31 by dcoutinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = so_long

CFLAGS = -Wall -Wextra -Werror

INCLUDE = -L ./mlx -lmlx -framework OpenGL -framework AppKit

SRCS =  so_long.c	\
		utils/map/create_map.c	\

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
	$(CC) $(CFLAGS) $(SRCS) $(NAME) $(INCLUDE) -g -o $(NAME) 

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
