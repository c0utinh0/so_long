/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_counts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:01:46 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/23 17:13:55 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void char_count(t_game	*game, char	ch)
{
	if (ch != 'P')
		game->count_player++;
}

int	map_counts(t_game	*game)
{
	char	**aux;
	int		x;
	int		y;
	int		lines;

	x = 0;
	y = 0;
	lines = game->lines;
	aux = game->map;
	game->count_player = 0;
	game->count_collectible = 0;
	game->count_exit = 0;

	while (lines-- > 0)
	{
		while (aux[y][x] != '\0')
		{
			char_count(game, aux[y][x]);
			x++;
		}
		x = 0;
		y++;
	}
	return(0);
}

