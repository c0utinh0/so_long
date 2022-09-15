/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:25:52 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/13 19:58:20 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	print_map(char	op, int	x, int	y, t_config	*config, t_map	*map)
{
	if	(op == '0')
		mlx_put_image_to_window(config->mlx, config->window, map->floor, x * PX, y * PX);
	else if (op == '1')
		mlx_put_image_to_window(config->mlx, config->window, map->wall, x * PX, y * PX);
	return (0);
}

int	render_map(t_map	*obj, t_config	*config)
{
	int	lines;

	obj->axis_x = 0;
	obj->axis_y = 0;
	lines = obj->lines;
	while (lines-- > 0)
	{
		while (obj->map[obj->axis_y][obj->axis_x] != '\0')
		{
			print_map(obj->map[obj->axis_y][obj->axis_x], obj->axis_x, obj->axis_y, config, obj);
			obj->axis_x++;
		}
		write(1, "\n", 1);
		obj->axis_x = 0;
		obj->axis_y++;
	}
	return (0);
}
