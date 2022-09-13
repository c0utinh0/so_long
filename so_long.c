/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:03:20 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/13 19:51:35 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

int main(void)
{
	t_config	config;
	t_map		map;
	char	*wall_path = "./assets/wall.xpm";
	void	*wall;
	char	*floor_path = "./assets/floor.xpm";
	void	*floor;
	int		img_width;
	int		img_height;
//	int line;
//	int temp = 0;
	
	create_map(&map);
//	line = map.lines;
	ft_printf("\n");
//	while (line-- > 0)
//		ft_printf("%s", map.map[temp++]);
	render_map(&map);
	config.mlx = mlx_init();
	config.window = mlx_new_window(config.mlx, 1280, 640, "MyGame");

	wall = mlx_xpm_file_to_image(config.mlx, wall_path, &img_width, &img_height);
	floor = mlx_xpm_file_to_image(config.mlx, floor_path, &img_width, &img_height);

	mlx_put_image_to_window(config.mlx, config.window, wall, 0, 0);
	mlx_put_image_to_window(config.mlx, config.window, wall, 64, 0);
	mlx_put_image_to_window(config.mlx, config.window, wall, 0, 64);
	mlx_put_image_to_window(config.mlx, config.window, floor, 64, 64);
	mlx_put_image_to_window(config.mlx, config.window, floor, 128, 64);
	mlx_loop(config.mlx);
    return (0);
}
