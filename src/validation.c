/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:40:44 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/27 09:42:54 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_error(char	*msg)
{
	ft_printf("Error: %s\n", msg);
	exit(0);
}

void	free_print_error(t_game	*game, char	*msg)
{
	free(game->map); //REMOVER
	ft_printf("\nMEM FREE\n");	//ALTERAR PARA FUNC Q LIBERA MEM
	print_error(msg);
}

void	free_exit(t_game	*game)
{
	free(game->map); //REMOVER
	mlx_destroy_window(game->mlx, game->window);
	ft_printf("\nMEM FREE\n");	//ALTERAR PARA FUNC Q LIBERA MEM
	exit(0);
}
