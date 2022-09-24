/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:33:20 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/23 16:23:07 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void char_validation(t_game	*game, char	ch)
{
	if (ch != 'P' && ch != 'E' && ch != '0' && ch != '1' &&  ch != 'C' && ch != '\n')
		free_print_error(game, "Invalid character map");
}

static	void	line_validation(t_game *game, char	*line)
{
	int	len;

	len = game->window_width;
	len = len - 2;
	if	(line[0] != '1' || line[len] != '1')
		free_print_error(game, "Invalid map");
}


int	map_validation(t_game	*game)
{
	char	**aux;
	int		x;
	int		y;
	int		lines;

	x = 0;
	y = 0;
	lines = game->lines;
	aux = game->map;
	while (lines > 0)
	{
		line_validation(game, aux[y]);
		while (aux[y][x] != '\0')
		{
			char_validation(game, aux[y][x]);
			x++;
		}
		x = 0;
		y++;
		lines--;
	}
	return(0);
}
