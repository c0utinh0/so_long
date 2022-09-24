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
		free_print_error(game, "Invalid map");
}

static void	line_validation(t_game *game, int	line, char	*str_line)
{
	int	len;

	len = game->window_width;
	len = len - 2;
	if	(line == 0 || line == game->lines)
		while (len-- > -1)
		{
			if(*str_line++ != '1')
				free_print_error(game, "Invalid map");
		}
	else if	(str_line[0] != '1' || str_line[len] != '1')
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
	map_counts(game);
	while (lines > 0)
	{
		line_validation(game, y, aux[y]);
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
