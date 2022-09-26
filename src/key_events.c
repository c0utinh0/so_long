/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:18:51 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/26 14:57:23 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	move_action(char key, t_game *game)
{
	player_position(game);
	player_move(key, game);
	render_map(game);
	return (0);
}

static void	exit_action(t_game *game)
{
    mlx_destroy_window(game->mlx, game->window);
    free_exit(game);
}

int	click_x(t_game *game)
{
    mlx_destroy_window(game->mlx, game->window);
    free_exit(game);
	return (0);
}

int	keyhook(int keycode, t_game *game)
{
	ft_printf("%d\n", keycode); //REMOVER ANTES DE ENTREGAR
//	if (keycode == 44)				//LINUX
	if (keycode == 13)				//MAC
		move_action('w', game);
//	else if (keycode == 101)		//LINUX
	else if (keycode == 1)		//MAC
		move_action('s', game);
//	else if (keycode == 105)		//LINUX
	else if (keycode == 0)		//MAC
		move_action('a', game);
//	else if (keycode == 97)			//LINUX
	else if (keycode == 2)		//MAC
		move_action('d', game);
	else if (keycode == 53)
		exit_action(game);
	return (0);
}
