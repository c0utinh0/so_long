/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:25:40 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/15 17:58:46 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_getline(int fd, char *buffer_line)
{
	int		count;
	char	*buffer;

	count = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!buffer_line)
		buffer_line = ft_gnl_strdup("\0");
	while ((!(ft_gnl_strchr(buffer_line, '\n'))) && count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0)
		{
			free(buffer);
			free(buffer_line);
			return (NULL);
		}
		buffer[count] = '\0';
		buffer_line = ft_gnl_strjoin(buffer_line, buffer);
	}
	free(buffer);
	return (buffer_line);
}

static char	*ft_line(char	*buffer_line)
{
	char			*line;
	unsigned int	i;

	i = 0;
	if (buffer_line[i] == '\0')
		return (NULL);
	while (buffer_line[i] != '\n' && buffer_line[i] != '\0')
		i++;
	if (buffer_line[i] == '\n')
		i++;
	line = ft_gnl_substr(buffer_line, 0, i);
	return (line);
}

char	*ft_cut(char *buffer_line)
{
	char			*temp;
	unsigned int	i;

	i = 0;
	while (buffer_line[i] != '\n' && buffer_line[i] != '\0')
		i++;
	if (buffer_line[i] == '\0')
	{
		free(buffer_line);
		return (NULL);
	}
	if (buffer_line[i] == '\n')
		i++;
	temp = ft_gnl_substr(buffer_line, i, (ft_gnl_strlen(buffer_line) - i));
	free(buffer_line);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buffer_line[4096];
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	buffer_line[fd] = ft_getline(fd, buffer_line[fd]);
	if (!buffer_line[fd])
		return (NULL);
	line = ft_line(buffer_line[fd]);
	buffer_line[fd] = ft_cut(buffer_line[fd]);
	return (line);
}
