/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:40:44 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/26 11:45:52 by dcoutinh         ###   ########.fr       */
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
	(void)game; //REMOVER
	ft_printf("\nMEM FREE\n");	//ALTERAR PARA FUNC Q LIBERA MEM
	print_error(msg);
}

void	free_exit(t_game	*game)
{
	(void)game; //REMOVER
	ft_printf("\nMEM FREE\n");	//ALTERAR PARA FUNC Q LIBERA MEM
	exit(0);
}
