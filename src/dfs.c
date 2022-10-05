/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:56:47 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/10/05 11:38:49 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	dfs(t_game	*game, int i, int j, char	**visited)
{
	int	m;
	int	n;

	m = game->lines;
	n = ft_strlen(visited[0]);
	if (game->op_exit)
	{
		if (i < 0 || i >= m || j < 0 || j >= n
			|| game->map[i][j] == '1' || visited[i][j] == '1')
			return (0);
	}
	else
	{
		if (i < 0 || i >= m || j < 0 || j >= n
			|| game->map[i][j] == 'E' ||
			game->map[i][j] == '1' || visited[i][j] == '1')
			return (0);
	}
	visited[i][j] = '1';
	dfs(game, i - 1, j, visited);
	dfs(game, i + 1, j, visited);
	dfs(game, i, j - 1, visited);
	dfs(game, i, j + 1, visited);
	return (0);
}

int	path_valid(t_game	*game, char	**visited, t_position	*collects[])
{
	int	j;
	int	index;

	j = 0;
	index = 0;
	if (game->op_exit)
	{
		dfs(game, game->player_y, game->player_x, visited);
		if (visited[game->exit_y][game->exit_x] == '1')
			index++;
	}
	else
	{
		dfs(game, game->player_y, game->player_x, visited);
		while (j < game->count_collectible)
		{
			if (visited[collects[j]->pos_y][collects[j]->pos_x] == '1')
				index++;
			j++;
		}
	}
	return (index);
}

void	map_visited_util(char	*str, int	*i)
{
	int	j;

	j = *i;
	while (str[j] != '\0')
			str[j++] = '0';
	j = 0;
	i = &j;
}

char	**map_visited(t_game	*game, char	*path)
{
	char	**visited;
	char	*str;
	int		i;
	int		fd;
	int		line;

	line = 0;
	i = 0;
	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	str++;
	visited = ft_calloc(game->lines, sizeof(char *));
	map_visited_util(str, &i);
	visited[line] = str;
	while ((game->lines - 1) != line)
	{
		line++;
		str = get_next_line(fd);
		str++;
		map_visited_util(str, &i);
		visited[line] = str;
	}
	return (visited);
}
