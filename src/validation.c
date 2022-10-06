/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:40:44 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/10/06 10:38:08 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_error(char	*msg)
{
	ft_printf("Error\n%s\n", msg);
	exit(0);
}

void	free_exit_mlx(t_game	*game, char	*msg)
{
	int	lines;

	lines = game->lines;
	ft_printf("\n%s\n", msg);
	lines--;
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

void	free_print_error_mlx(t_game	*game, char	*msg)
{
	int	lines;

	lines = game->lines;
	ft_printf("\nError\n%s\n", msg);
	lines--;
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

void	free_print_error(t_game	*game, char	*msg)
{
	int	lines;

	lines = game->lines;
	ft_printf("\nError\n%s\n", msg);
	lines--;
	while (lines > -1)
		free(game->map[lines--]);
	free(game->map);
	exit(0);
}
