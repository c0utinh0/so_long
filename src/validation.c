/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:40:44 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/23 15:57:35 by dcoutinh         ###   ########.fr       */
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
