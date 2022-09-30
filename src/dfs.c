/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:56:47 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/30 14:15:52 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	int dfs(t_game	*game, int i, int j, char	**visited) 
{
	int m;
	int n; //len visited
	
	m = game->lines;
	n = ft_strlen(visited[0]);

	if(i < 0 || i >= m || j < 0 || j >= n || game->map[i][j] == 'E' || game->map[i][j] == '1' || visited[i][j] == '1')
		return(0);
	visited[i][j] = '1';
	ft_printf("\n");
	ft_printf("%s\n", visited[0]);
	ft_printf("%s\n", visited[1]);
	ft_printf("%s\n", visited[2]);
	ft_printf("%s\n", visited[3]);
	ft_printf("%s\n", visited[4]); //REMOVER
	ft_printf("\n");
	dfs(game, i-1, j, visited); // Move left
	dfs(game, i+1, j, visited); // Move Right
	dfs(game, i, j-1, visited); //Move top
	dfs(game, i, j+1, visited); //Move bottom		
	return(0);
}

int path_valid(t_game	*game, char	**visited, t_position	*collects[])
{
	int	j;
	int x;
	int	y;
	j = game->count_collectible;
	visited[game->exit_y][game->exit_x] = '0';
	x = collects[0]->pos_x;
	y = collects[0]->pos_y;
//	while(j > 0)
//	{
//		dfs(game, game->player_y, game->player_x, visited);
//	}
	
	dfs(game, game->player_y, game->player_x, visited);
//	if(visited[game->exit_y][game->exit_x] == '0') { // ENDEREÇO DA SAIDA
	if(visited[x][y] == '0') {
		return (0);
	}
	return (1);
}

char	**map_visited(t_game	*game, char	*path)
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
	ft_printf("%s", visited[line]); //REMOVER
	return (visited);
}
