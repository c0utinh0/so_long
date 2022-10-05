/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 07:57:30 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/10/05 10:48:55 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	path_validation(t_game	*game, char	*path)
{
	char	**visited;
	t_position	*collects[game->count_collectible];
//	int i;
	int ret;
	int valid;

	game->op_exit = 0;
	ret = 0;

	positions(game);
	collectible_positions(collects, game);
	visited = map_visited(game, path);
//	valid = path_valid(game, visited, collects, i);
	valid = path_valid(game, visited, collects);
	ft_printf("Proliferado com a saida fechada\n");
	ft_printf("Coletáveis: %d\n", game->count_collectible);
	ft_printf("Path Coletáveis: %d\n", valid);
	if(game->count_collectible == valid)
		ret = valid;
	game->op_exit++;
	visited = map_visited(game, path);
	valid = path_valid(game, visited, collects);
	ft_printf("Proliferado com a saida aberta\n");
	ft_printf("Path Saida: %d\n", valid);
	if(valid == 1)
		ret = ret + valid;
	ft_printf("\nRet total: %d\n", ret);
	ft_printf("Necessário para sair: %d\n", game->count_collectible + 1);
	if(!(ret == (game->count_collectible + 1)))
		free_print_error(game, "Invalid map");
	return (0);
}
