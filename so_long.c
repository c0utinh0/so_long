/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:03:20 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/10/05 09:50:45 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char	**argv)
{
	t_game	game;

	init_validation(argc, argv[1]);
	game.mlx = mlx_init();
	if (!(game.mlx))
		exit(0);
	create_map(&game, argv[1]);
	map_validation(&game);
	path_validation(&game, argv[1]);
	game.window = mlx_new_window(game.mlx, (game.window_width - 1)
			* PX, game.window_height * PX, "OrbSpaceHunter");
	if (!(game.window))
		exit(0);
	upload_imgs(&game);
	render_map(&game);
	mlx_key_hook(game.window, keyhook, &game);
	mlx_hook(game.window, 17, 0, click_x, &game);
	mlx_loop(game.mlx);
	return (0);
}
