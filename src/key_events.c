/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:18:51 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/19 20:51:52 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_action(char key, t_game *game)
{
	(void)key;
	player_position(game);
	player_move(key, game);
	render_map(game);
	return (0);
}

int	keyhook(int keycode, t_game *game)
{
	if (keycode == 13)
		key_action('w', game);
	return (0);
}
