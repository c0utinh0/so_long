/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:03:20 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/16 10:34:24 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	t_config	config;
	t_map		map;

	config.mlx = mlx_init();
	create_map(&map, &config);
	config.window = mlx_new_window(config.mlx, (config.window_width - 1) * PX, config.window_height * PX, "OrbSpaceHunter");
	upload_imgs(&map, &config);
	render_map(&map, &config);
	mlx_key_hook(config.window, keyhook, &config);
	mlx_loop(config.mlx);

	return (0);
}
