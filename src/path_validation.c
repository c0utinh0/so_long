/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 07:57:30 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/10/05 17:19:46 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	path_validation(t_game *game, char *path)
{
	char		**visited;
	t_position	*collects[100];
	int			ret;
	int			valid;

	game->op_exit = 0;
	ret = 0;
	positions(game);
	collectible_positions(collects, game);
	visited = map_visited(game, path);
	valid = path_valid(game, visited, collects);
	if (game->count_collectible == valid)
		ret = valid;
	game->op_exit++;
	visited = map_visited(game, path);
	valid = path_valid(game, visited, collects);
	if (valid == 1)
		ret = ret + valid;
	if (!(ret == (game->count_collectible + 1)))
		free_print_error(game, "Invalid map");
	return (0);
}
