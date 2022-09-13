/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:34:00 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/13 18:49:47 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	create_map(t_map	*obj)
{
	char	*str;
	int		fd;
	int		len;

	obj->lines = 0;
	fd = open("map.ber", O_RDONLY);
	str = get_next_line(fd);
	len = ft_strlen(str);
	obj->map = ft_calloc(len + 1, sizeof(char *));
	if	(!obj->map)
		return (1);
	obj->map[obj->lines] = str;
	while (str)
	{
		ft_printf("%s", obj->map[obj->lines++]); //TRATAR
		str = get_next_line(fd);
		obj->map[obj->lines] = str;
	}
	return(0);
}
