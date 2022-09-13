/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:25:52 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/13 19:58:20 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	print_sprite(char	op)
{
	if	(op == '0')
		write(1, "-", 1);
	else if (op == '1')
		write(1, "#", 1);
	else if (op == 'P')
		write(1, "P", 1);
	else if (op == 'C')
		write(1, "C", 1);
	else if (op == 'E')
		write(1, "E", 1);



	return (0);
}

int	render_map(t_map	*obj)
{
	int	line;
	int	temp;
	int i;

	i = 0;
	temp = 0;
	line = obj->lines;
	while (line-- > 0)
	{
		while (obj->map[temp][i] != '\0')
		{
			print_sprite(obj->map[temp][i++]);
		}
		write(1, "\n", 1);
		i = 0;
		temp++;
	}
	return (0);
}
