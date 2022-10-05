/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:25:52 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/10/05 14:25:02 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	print_map(char op, int x, int y, t_game *game)
{
	if (op == '0')
		mlx_put_image_to_window(game->mlx,
			game->window, game->floor, x * PX, y * PX);
	else if (op == '1')
		mlx_put_image_to_window(game->mlx,
			game->window, game->wall, x * PX, y * PX);
	else if (op == 'C')
		mlx_put_image_to_window(game->mlx,
			game->window, game->collectible, x * PX, y * PX);
	else if (op == 'P')
		mlx_put_image_to_window(game->mlx,
			game->window, game->player, x * PX, y * PX);
	else if (op == 'E')
		mlx_put_image_to_window(game->mlx,
			game->window, game->exit, x * PX, y * PX);
	return (0);
}

int	render_map(t_game *game)
{
	int	lines;

	game->axis_x = 0;
	game->axis_y = 0;
	lines = game->lines;
	while (lines-- > 0)
	{
		while (game->map[game->axis_y][game->axis_x] != '\0')
		{
			print_map(game->map[game->axis_y][game->axis_x],
				game->axis_x, game->axis_y, game);
			game->axis_x++;
		}
		game->axis_x = 0;
		game->axis_y++;
	}
	return (0);
}
