# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 16:32:52 by dcoutinh          #+#    #+#              #
#    Updated: 2022/09/15 20:19:34 by dcoutinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = so_long

CFLAGS = -Wall -Wextra -Werror

INCLUDE = -L ./mlx -lmlx -framework OpenGL -framework AppKit

INCLUDE_L = -L ./mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRCS =  so_long.c	\
		src/create_map.c	\
		src/render_map.c	\

OBJS = $(SRCS:.c=.o)

LIBFT = make -C libft && cp libft/libft.a $(NAME)

CLIBFT = make -C libft clean

FCLIBFT = make -C libft fclean

MLX = make -C mlx

MLX_L = make -C mlx_linux

CMLX = make -C mlx clean

CMLX_L = make -C mlx_linux clean

all: $(NAME)

$(NAME): $(SRC)
	@$(MLX)
	@$(LIBFT)
	@$(CC) $(CFLAGS) $(SRCS) $(NAME) $(INCLUDE) -g -o $(NAME) 

linux: $(SRC)
	$(MLX_L)
	$(LIBFT)
	$(CC) -g $(CFLAGS) $(SRCS) $(NAME) $(INCLUDE_L)

clean:
	@rm -f $(OBJS)
	@$(CLIBFT)
	@$(CMLX)
#	@$(CMLX_L)

fclean:
	@rm -f $(NAME)
	@rm -rf so_long.dSYM
	@$(FCLIBFT)
	@$(CMLX)
#	@$(CMLX_L)

re: fclean all

re_linux: fclean linux

.PHONY: all clean fclean re re_linux
