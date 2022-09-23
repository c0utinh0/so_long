/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:42:21 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/23 15:26:01 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* *i************************************************************************* */

#include "../so_long.h"

int movement(char key, t_game *game, t_movement	*move)
{
	if(key == 'w')
	{
		move->next_x = game->player_x;
		move->next_y = game->player_y;
		--move->next_y;
	}
	else if(key == 's')
	{
		move->next_x = game->player_x;
		move->next_y = game->player_y;
		++move->next_y;
	}
	else if(key == 'a')
	{
		move->next_x = game->player_x;
		move->next_y = game->player_y;
		--move->next_x;
	}
	else if(key == 'd')
	{
		move->next_x = game->player_x;
		move->next_y = game->player_y;
		++move->next_x;
	}
	return (0);
}

int	player_move(char	key, t_game	*game)
{
	t_movement	move;

	movement(key, game, &move);
	if (game->map[move.next_y][move.next_x] == '0' || game->map[move.next_y][move.next_x] == 'C')
	{
		game->map[move.next_y][move.next_x] = 'P';
		game->map[game->player_y][game->player_x] = '0';
	}
	else if (game->map[move.next_y][move.next_x] == 'E')
	{
		game->map[move.next_y][move.next_x] = 'P';
		game->map[game->player_y][game->player_x] = '0';
		ft_printf("exit\n");
		exit(0);
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
	ft_printf("\n%d ,%d\n", game->player_x, game->player_y); //REMOVER
	return (0);
}
