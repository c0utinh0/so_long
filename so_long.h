/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:05:33 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/19 20:43:22 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WALL "./assets/wall.xpm"
# define FLOOR "./assets/floor.xpm"
# define COLLECTIBLE "./assets/collectible.xpm"
# define PLAYER "./assets/player.xpm"
# define EXIT "./assets/exit.xpm"
# define PX 64

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		window_width;
	int		window_height;
	int		lines;
	char	**map;
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*player;
	int		player_x;
	int		player_y;
	void	*exit;
	int		img_width;
	int		img_height;
	int		axis_x;
	int		axis_y;
}	t_game;

int	create_map(t_game	*game);
int	render_map(t_game	*game);
int	upload_imgs(t_game	*game);
int	keyhook(int keycode, t_game *game);
int	key_action(char key, t_game *game);
int	player_position(t_game *game);
int	player_move(char key, t_game *game);

#endif
