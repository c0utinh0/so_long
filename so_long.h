/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:05:33 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/29 08:01:08 by dcoutinh         ###   ########.fr       */
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

typedef struct s_movement
{
	int	next_x;
	int	next_y;
}	t_movement;

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
	int		exit_x;
	int		exit_y;
	void	*exit;
	int		img_width;
	int		img_height;
	int		axis_x;
	int		axis_y;
	int		movement;
	int		count_player;
	int		count_collectible;
	int		count_exit;
	char	**m_collect;
//	int		s_x;
//	int		s_y;
//	int		d_x;
//	int		s_y;
}	t_game;

int	create_map(t_game	*game, char	*path);
int	render_map(t_game	*game);
int	upload_imgs(t_game	*game);
int	keyhook(int keycode, t_game *game);
int	click_x(t_game *game);
int	positions(t_game *game);
int	player_move(char key, t_game *game);
int movement(char key, t_game *game, t_movement *move);
int	init_validation(int argc, char	*path);
void	print_error(char	*msg);
void	free_print_error(t_game	*game, char	*msg);
void	free_exit(t_game *game);
int	map_validation(t_game	*game);
int	map_counts(t_game	*game);
int	path_validation(t_game	*game, char	*path);
int map_visited(t_game	*game, char	*path);

#endif

