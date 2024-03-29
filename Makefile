# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 16:32:52 by dcoutinh          #+#    #+#              #
#    Updated: 2022/10/06 10:00:32 by dcoutinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = so_long

CFLAGS = -Wall -Wextra -Werror

INCLUDE = -L ./mlx -lmlx -framework OpenGL -framework AppKit

SRCS =  so_long.c	\
		src/create_map.c	\
		src/render_map.c	\
		src/key_events.c	\
		src/positions.c	\
		src/positions_utils.c	\
		src/validation.c	\
		src/init_validation.c	\
		src/map_validation.c	\
		src/path_validation.c	\
		src/map_counts.c	\
		src/dfs.c	\

OBJS = $(SRCS:.c=.o)

LIBFT = make -C libft && cp libft/libft.a $(NAME)

CLIBFT = make -C libft clean

FCLIBFT = make -C libft fclean

MLX = make -C mlx

CMLX = make -C mlx clean

all: $(NAME)

$(NAME): $(SRC)
	@$(MLX)
	@$(LIBFT)
	@$(CC) $(CFLAGS) $(SRCS) $(NAME) $(INCLUDE) -o $(NAME) 

clean:
	@rm -f $(OBJS)
	@$(CLIBFT)
	@$(CMLX)

fclean:
	@rm -f $(NAME)
	@rm -rf so_long.dSYM
	@$(FCLIBFT)
	@$(CMLX)

re: fclean all

.PHONY: all clean fclean re re_linux
