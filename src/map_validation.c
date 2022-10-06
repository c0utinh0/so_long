/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:33:20 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/10/06 09:11:03 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	char_validation(t_game *game, char ch)
{
	if (ch != 'P' && ch != 'E' && ch != '0'
		&& ch != '1' && ch != 'C' && ch != '\n')
		free_print_error(game, "Invalid map (Invalid Character)");
}

static void	line_validation(t_game *game, int line, char *str_line)
{
	int	len;

	len = game->window_width;
	len = len - 2;
	if ((int)ft_strlen(str_line) != game->window_width)
		free_print_error(game, "Invalid map (Invalid lines size)");
	if (line == 0 || line == (game->lines - 1))
	{
		while (len-- > -1)
		{
			if (*str_line++ != '1')
				free_print_error(game, "Invalid map (Extremities)");
		}
	}
	else if (str_line[0] != '1' || str_line[len] != '1')
		free_print_error(game, "Invalid map (Extremities)");
}

static void	map_format(t_game *game)
{
	int	x;
	int	y;

	x = game->window_width;
	y = game->window_height;
	if (--x == y)
		free_print_error(game, "Invalid map (Not Rectangle)");
}

int	map_validation(t_game *game)
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
	map_format(game);
	while (lines > 0)
	{
		while (aux[y][x] != '\0')
		{
			char_validation(game, aux[y][x]);
			x++;
		}
		line_validation(game, y, aux[y]);
		x = 0;
		y++;
		lines--;
	}
	return (0);
}
