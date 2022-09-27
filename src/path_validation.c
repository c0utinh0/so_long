/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:56:47 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/27 17:48:05 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
//DFS + memoization, Time O(m*n), Space O(m*n) 
int dfs(char **adj, int i, int j, char	**visited) 
{
	int m = 30;
	int n = 5;
	if(i < 0 || i >= m || j < 0 || j >= n || adj[i][j] == '1' || visited[i][j] == '1')
		return(0);
	visited[i][j] = '1';
	dfs(adj, i-1, j, visited); // Move left
	dfs(adj, i+1, j, visited); // Move Right
	dfs(adj, i, j-1, visited); //Move top
	dfs(adj, i, j+1, visited); //Move bottom		
	return(0);
}
*/

//int path(t_game	*game, int sx, int sy, int dx, int dy)
int path(t_game	*game, char	*path)
{
	char **visited;
	char	*str;
	int	len;
	int	lines;
	int i;
	int fd;
	int	line;

	line = 0;
	lines = game->lines;
	(void)game;
	i = 0;
	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	len = ft_strlen(str);
	visited = ft_calloc(len, sizeof(char *));
	while (str[i] != '\0')
			str[i++] = '0';
	i = 0;
	visited[line] = str;
	while ((lines - 1) != line)
	{
		ft_printf("\n%s", visited[line++]); //REMOVER
		str = get_next_line(fd);
		while (str[i] != '\0')
			str[i++] = '0';
		i = 0;
		visited[line] = str;
	}




/*
	dfs(adj, sx,sy, visited);
	if(!visited[dx][dy]) {
		return (0);
	}
	return (1);
*/
	return (0);
}


