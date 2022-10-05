/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:34:00 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/10/05 09:35:10 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	upload_imgs(t_game	*game)
{
	game->img_width = PX;
	game->img_height = PX;
	game->wall = mlx_xpm_file_to_image(game->mlx, WALL, &game->img_width, &game->img_height);
	game->floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &game->img_width, &game->img_height);
	game->collectible = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE, &game->img_width, &game->img_height);
	game->player = mlx_xpm_file_to_image(game->mlx, PLAYER, &game->img_width, &game->img_height);
	game->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &game->img_width, &game->img_height);
	return (0);
}

int	create_map(t_game	*game, char	*path)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	game->movement = 0;
	map_init_count(game, path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		print_error("Invalid file");
	str = get_next_line(fd);
//	len = ft_strlen(str);
//	game->window_width = len;
	game->map = ft_calloc(game->lines, sizeof(char *));
	if	(!game->map)
		return (1);
	game->map[i] = str;
	while (str)
	{
		ft_printf("%s", game->map[i]); //REMOVER
		str = get_next_line(fd);
		game->map[++i] = str;
	}
//	game->window_height = game->lines;
	return(0);
}
