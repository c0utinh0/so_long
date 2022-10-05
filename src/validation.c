/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:40:44 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/10/05 17:19:28 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_error(char	*msg)
{
	ft_printf("Error: %s\n", msg);
	exit(0);
}

void	free_print_error(t_game	*game, char	*msg)
{
	ft_printf("\n%s", msg);
	free_exit(game);
}

void	free_exit(t_game	*game)
{
	int lines;

	lines = game->lines;
	while (lines > -1)
		free(game->map[lines--]);
	free(game->map);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->collectible);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
}
