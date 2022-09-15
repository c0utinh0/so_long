/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:34:00 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/15 18:10:04 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	upload_imgs(t_map	*map, t_config	*config)
{
	map->img_width = PX;
	map->img_height = PX;
	map->wall = mlx_xpm_file_to_image(config->mlx, WALL, &map->img_width, &map->img_height);
	map->floor = mlx_xpm_file_to_image(config->mlx, FLOOR, &map->img_width, &map->img_height);
	map->collect = mlx_xpm_file_to_image(config->mlx, COLLECT, &map->img_width, &map->img_height);
	map->player = mlx_xpm_file_to_image(config->mlx, PLAYER, &map->img_width, &map->img_height);
	map->exit = mlx_xpm_file_to_image(config->mlx, EXIT, &map->img_width, &map->img_height);
	return (0);
}

int	create_map(t_map	*obj, t_config	*config)
{
	char	*str;
	int		fd;
	int		len;

	obj->lines = 0;
	fd = open("map.ber", O_RDONLY);
	str = get_next_line(fd);
	len = ft_strlen(str);
	config->window_width = len;
	obj->map = ft_calloc(len + 1, sizeof(char *));
	if	(!obj->map)
		return (1);
	obj->map[obj->lines] = str;
	while (str)
	{
		ft_printf("%s", obj->map[obj->lines]); //REMOVER
		str = get_next_line(fd);
		obj->map[++obj->lines] = str;
	}
	config->window_height = obj->lines;
	return(0);
}
