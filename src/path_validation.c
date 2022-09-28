/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:56:47 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/28 14:06:24 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//DFS + memoization, Time O(m*n), Space O(m*n) 
int dfs(char **map, int i, int j, char	**visited) 
{
	int m = 40;
	int n = 5;
	
	int len_map = ft_strlen(map[0]);
	int len_visited = ft_strlen(visited[0]);

	(void)len_map;
	(void)len_visited;


	if(i < 0 || i >= m || j < 0 || j >= n || map[i][j] == '1' || visited[i][j] == '1')
		return(0);
	visited[i][j] = '1';
	dfs(map, i-1, j, visited); // Move left
	dfs(map, i+1, j, visited); // Move Right
	dfs(map, i, j-1, visited); //Move top
	dfs(map, i, j+1, visited); //Move bottom		
	return(0);
}


//int path(t_game	*game, int sx, int sy, int dx, int dy)
int path(t_game	*game, char	*path)
{
	char **visited;
	char	**map;
	char	*str;
	int	len;
	int	lines;
	int i;
	int fd;
	int	line;

	map = game->map;
	line = 0;
	lines = game->lines;
	i = 0;
	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	str++;
	len = ft_strlen(str);
	visited = ft_calloc(--len, sizeof(char *));
	while (str[i] != '\0')
			str[i++] = '0';
	i = 0;
	visited[line] = str;
	while ((lines - 1) != line)
	{
		ft_printf("%s", visited[line++]); //REMOVER
		str = get_next_line(fd);
		str++;
		while (str[i] != '\0')
			str[i++] = '0';
		i = 0;
		visited[line] = str;
	}
	ft_printf("\n%s", visited[line]); //REMOVER

	dfs(map, 1, 2, visited);
	if(!visited[3][6]) {
		return (0);
	}
	return (1);
/*
	dfs(adj, sx, sy, visited);
	if(!visited[dx][dy]) {
		return (0);
	}
	return (1);
*/
}
