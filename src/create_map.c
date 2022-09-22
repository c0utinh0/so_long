/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:34:00 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/22 14:09:38 by dcoutinh         ###   ########.fr       */
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
	int		len;

	game->lines = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		print_error("Invalid file");
	str = get_next_line(fd);
	len = ft_strlen(str);
	game->window_width = len;
	game->map = ft_calloc(len + 1, sizeof(char *));
	if	(!game->map)
		return (1);
	game->map[game->lines] = str;
	while (str)
	{
		ft_printf("%s", game->map[game->lines]); //REMOVER
		str = get_next_line(fd);
		game->map[++game->lines] = str;
	}
	game->window_height = game->lines;
	return(0);
}
