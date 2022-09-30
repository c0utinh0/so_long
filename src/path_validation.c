/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 07:57:30 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/30 09:41:09 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	path_validation(t_game	*game, char	*path)
{

	t_position	*collects[game->count_collectible];

	positions(game);
	collectible_positions(collects, game);
	return (map_visited(game, path));
}

