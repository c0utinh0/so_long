/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:03:20 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/26 15:26:42 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char	**argv)
{
	t_game	game;

	init_validation(argc, argv[1]);
	create_map(&game, argv[1]);
	game.mlx = mlx_init();
	map_validation(&game);
	game.window = mlx_new_window(game.mlx, (game.window_width - 1) * PX, game.window_height * PX, "OrbSpaceHunter");
	upload_imgs(&game);
	render_map(&game);
	mlx_key_hook(game.window, keyhook, &game);
	mlx_hook(game.window, 17, 0, click_x, &game);
	mlx_loop(game.mlx);
	return (0);
}
