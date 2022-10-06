/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:34:37 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/10/06 08:41:09 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	movement(char key, t_game *game, t_movement *move)
{
	if (key == 'w')
	{
		move->next_x = game->player_x;
		move->next_y = game->player_y;
		--move->next_y;
	}
	else if (key == 's')
	{
		move->next_x = game->player_x;
		move->next_y = game->player_y;
		++move->next_y;
	}
	else if (key == 'a')
	{
		move->next_x = game->player_x;
		move->next_y = game->player_y;
		--move->next_x;
	}
	else if (key == 'd')
	{
		move->next_x = game->player_x;
		move->next_y = game->player_y;
		++move->next_x;
	}
	return (0);
}

int	player_move(char key, t_game *game)
{
	t_movement	move;

	movement(key, game, &move);
	if (game->map[move.next_y][move.next_x] == '0')
	{
		game->movement++;
		game->map[move.next_y][move.next_x] = 'P';
		game->map[game->player_y][game->player_x] = '0';
	}
	else if (game->map[move.next_y][move.next_x] == 'C')
	{
		game->movement++;
		game->map[move.next_y][move.next_x] = 'P';
		game->map[game->player_y][game->player_x] = '0';
		game->count_collectible--;
	}
	else if (game->map[move.next_y][move.next_x]
			== 'E' && game->count_collectible == 0)
	{
		game->movement++;
		game->map[move.next_y][move.next_x] = 'P';
		game->map[game->player_y][game->player_x] = '0';
		free_print_error_mlx(game, "You Win!!!");
	}
	return (0);
}

static void	add_position(t_position **pos, int x, int y)
{
	t_position	*p;

	p = (t_position *)malloc(sizeof(t_position));
	p->pos_x = x;
	p->pos_y = y;
	*pos = p;
}

void	collectible_positions(t_position **collects, t_game *game)
{
	char	**aux;
	int		x;
	int		y;
	int		lines;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	lines = game->lines;
	aux = game->map;
	while (lines > 0)
	{
		while (aux[y][x] != '\0')
		{
			if (aux[y][x] == 'C')
				add_position(&collects[i++], x, y);
			x++;
		}
		x = 0;
		y++;
		lines--;
	}
}

int	positions(t_game *game)
{
	char	**aux;
	int		x;
	int		y;

	x = 0;
	y = 0;
	aux = game->map;
	positions_utils(aux, game, x, y);
	return (0);
}
