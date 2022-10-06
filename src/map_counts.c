/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_counts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:01:46 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/10/06 10:48:15 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	char_count(t_game *game, char ch)
{
	if (ch == 'P')
		game->count_player++;
	else if (ch == 'C')
		game->count_collectible++;
	else if (ch == 'E')
		game->count_exit++;
}

static void	count_validation(t_game	*game)
{
	if (game->count_player != 1 || game->count_exit
		!= 1 || game->count_collectible == 0)
		free_print_error(game, "Invalid map (Count Validation)");
	if (game->count_collectible > 100)
		free_print_error(game, "Max 100 Collectibles");
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
	game->movement = 0;
	game->count_player = 0;
	game->count_collectible = 0;
	game->count_exit = 0;
	while (lines-- > 0)
	{
		while (aux[y][x] != '\0')
			char_count(game, aux[y][x++]);
		x = 0;
		y++;
	}
	count_validation(game);
	return (0);
}

int	map_init_count(t_game	*game, char	*path)
{
	char	*str;
	int		fd;

	game->lines = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		print_error("Invalid file");
	str = get_next_line(fd);
	if (!str)
		print_error("Empty file");
	game->window_width = ft_strlen(str);
	while (str)
	{
		str = get_next_line(fd);
		game->lines++;
	}
	game->window_height = game->lines;
	close(fd);
	return (0);
}
