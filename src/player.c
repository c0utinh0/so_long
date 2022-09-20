/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:42:21 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/19 21:04:18 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	player_move(char	key, t_game	*game)
{
	int	next_x;
	int	next_y;

	(void)key;
	next_x = game->player_x;
	next_y = game->player_y;
	if (game->map[--next_y][next_x] == '0')
	{
//		mlx_destroy_image(game->mlx, game->floor);
		game->map[next_y][next_x] = 'P';
		game->map[game->player_y][game->player_x] = '0';
	}
	player_position(game);
	return (0);
}

int	player_position(t_game	*game)
{
	char	**aux;
	int		x;
	int		y;
	int		lines;

	x = 0;
	y = 0;
	lines = game->lines;
	aux = game->map;
	while (lines-- > 0)
	{
		while (aux[y][x] != '\0')
		{
			if (aux[y][x] == 'P')
			{
				ft_printf("P");
				game->player_x = x;
				game->player_y = y;
			}
			else
				ft_printf("#");
			x++;
		}
		write(1, "\n", 1);
		x = 0;
		y++;
	}
	ft_printf("\n%d ,%d\n", game->player_x, game->player_y);
	return (0);
}
