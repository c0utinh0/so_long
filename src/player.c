/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:42:21 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/26 15:00:15 by dcoutinh         ###   ########.fr       */
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
	else if (game->map[move.next_y][move.next_x] == 'E' && game->count_collectible == 0)
	{
		game->movement++;
		game->map[move.next_y][move.next_x] = 'P';
		game->map[game->player_y][game->player_x] = '0';
		ft_printf("exit\n");	//TRATAR A SAIDA COM FREE
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
				ft_printf("P");		//REMOVER
				game->player_x = x;
				game->player_y = y;
			}
			else
				ft_printf("#");	//REMOVER
			x++;
		}
		write(1, "\n", 1);
		x = 0;
		y++;
	}
	ft_printf("\nMovement: %d\n", game->movement);
	ft_printf("\n%d ,%d\n", game->player_x, game->player_y); //REMOVER
	ft_printf("Player count: %d\n",game->count_player);	//REMOVER
	ft_printf("Collectible count: %d\n",game->count_collectible);	//REMOVER
	ft_printf("Exit count: %d\n",game->count_exit);	//REMOVER
	return (0);
}
