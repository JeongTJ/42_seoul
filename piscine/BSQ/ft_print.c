/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:21:03 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/09 18:31:02 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	print_error(char *error_msg)
{
	write(1, error_msg, ft_strlen(error_msg));
	write(1, "\n", 1);
}

void	print_board(char **board, int x_size, int y_size)
{
	int	y;

	y = 0;
	while (y < y_size)
	{
		write(1, board[y], x_size);
		write(1, "\n", 1);
		y++;
	}
}
