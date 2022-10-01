/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 07:57:30 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/30 14:10:45 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	path_validation(t_game	*game, char	*path)
{
	char	**visited;
	t_position	*collects[game->count_collectible];
	int i;
	int ret;

	i = 0;

	positions(game);
	collectible_positions(collects, game);
	visited = map_visited(game, path);
	ret = path_valid(game, visited, collects, i);
	ft_printf("Path para Coletáveis: \n%d\n", ret);
	if(!(game->count_collectible == ret))
		return (0);
	i++;
	visited = map_visited(game, path);
	if(!(path_valid(game, visited, collects, i)))
		return (0);
	return (1);
}
