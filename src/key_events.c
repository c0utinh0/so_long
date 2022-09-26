/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:18:51 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/26 07:58:14 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_action(char key, t_game *game)
{
	game->movement++;
	player_position(game);
	player_move(key, game);
	render_map(game);
	return (0);
}

int	keyhook(int keycode, t_game *game)
{
	ft_printf("%d\n", keycode); //REMOVER ANTES DE ENTREGAR
//	if (keycode == 44)				//LINUX
	if (keycode == 13)				//MAC
		key_action('w', game);
//	else if (keycode == 101)		//LINUX
	else if (keycode == 1)		//MAC
		key_action('s', game);
//	else if (keycode == 105)		//LINUX
	else if (keycode == 0)		//MAC
		key_action('a', game);
//	else if (keycode == 97)			//LINUX
	else if (keycode == 2)		//MAC
		key_action('d', game);
	return (0);
}
