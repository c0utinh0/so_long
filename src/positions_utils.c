/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:11:28 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/10/05 14:21:36 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	positions_utils(char **aux, t_game *game, int x, int y)
{
	int		lines;

	lines = game->lines;
	while (lines-- > 0)
	{
		while (aux[y][x] != '\0')
		{
			if (aux[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			else if (aux[y][x] == 'E')
			{
				game->exit_x = x;
				game->exit_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
}
