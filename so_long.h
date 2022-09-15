/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:05:33 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/13 19:40:40 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WALL "./assets/wall.xpm"
# define FLOOR "./assets/floor.xpm"
# define PX 64

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>

typedef struct s_config
{
	void	*mlx;
	void	*window;
	int		window_width;
	int		window_height;
}	t_config;

typedef struct s_map
{
	int		lines;
	char	**map;
	void	*wall;
	void	*floor;
	int		img_width;
	int		img_height;
	int		axis_x;
	int		axis_y;
}	t_map;

int	create_map(t_map	*obj, t_config	*config);
int	render_map(t_map	*obj, t_config	*config);
int	upload_imgs(t_map	*map, t_config	*config);

#endif
