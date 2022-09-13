/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:05:33 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/13 18:46:39 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>

typedef struct s_config
{
	void	*mlx;
	void	*window;
}	t_config;

typedef struct s_map
{
	int		lines;
	char	**map;
}	t_map;

int	create_map(t_map	*obj);

#endif
