/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:18:51 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/10/05 14:01:25 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	move_action(char key, t_game *game)
{
	positions(game);
	player_move(key, game);
	render_map(game);
	ft_printf("\nMovement: %d", game->movement);
	return (0);
}

static void	exit_action(t_game *game)
{
	free_exit(game);
}

int	click_x(t_game *game)
{
	free_exit(game);
	return (0);
}

int	keyhook(int keycode, t_game *game)
{
	if (keycode == 13)
		move_action('w', game);
	else if (keycode == 1)
		move_action('s', game);
	else if (keycode == 0)
		move_action('a', game);
	else if (keycode == 2)
		move_action('d', game);
	else if (keycode == 53)
		exit_action(game);
	return (0);
}
