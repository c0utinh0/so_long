/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:54:07 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/10/05 11:44:21 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_path(char	*path)
{
	int	len;

	len = ft_strlen(path);
	while (len > 4)
	{
		path++;
		len--;
	}
	return (ft_strncmp(path, ".ber", len));
}

int	init_validation(int argc, char *path)
{
	if (argc != 2)
		print_error("Invalid arguments");
	if (ft_path(path))
		print_error("Invalid file type");
	return (0);
}
