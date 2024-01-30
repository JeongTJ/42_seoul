/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:25:32 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/09 17:04:02 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_board_fill(char **board, t_position *coor, int size)
{
	int	x_idx;
	int	y_idx;

	x_idx = 0;
	y_idx = 0;
	while (y_idx < size)
	{
		while (x_idx < size)
		{
			board[coor->y + y_idx][coor->x + x_idx] = coor->e_o_f[2];
			x_idx++;
		}
		x_idx = 0;
		y_idx++;
	}
}

int	ft_is_vaild_square(char **board, t_position *coor, int size)
{
	int	x_idx;
	int	y_idx;

	x_idx = 0;
	y_idx = 0;
	if (!(coor->y + size - 1 < coor->y_size && \
				coor->x + size - 1 < coor->x_size))
		return (0);
	while (y_idx < size)
	{
		while (x_idx < size)
		{
			if (board[coor->y + y_idx][coor->x + x_idx] == coor->e_o_f[1])
				return (0);
			x_idx++;
		}
		x_idx = 0;
		y_idx++;
	}
	return (1);
}

void	ft_save(t_position *coor, int *y, int *x)
{
	*y = coor->y;
	*x = coor->x;
}

void	ft_load(t_position *coor, int *y, int *x)
{
	coor->y = *y;
	coor->x = *x;
}

int	ft_biggest_square(char **board, t_position *coor, int size)
{
	int	x_idx;
	int	y_idx;
	int	temp;

	while (coor->y < coor->y_size)
	{
		coor->x = 0;
		while (coor->x < coor->x_size)
		{
			if (ft_is_vaild_square(board, coor, size))
			{
				ft_save(coor, &y_idx, &x_idx);
				temp = ft_biggest_square(board, coor, size + 1);
				if (temp == 0)
				{
					ft_load(coor, &y_idx, &x_idx);
					ft_board_fill(board, coor, size);
				}
				return (1);
			}
			coor->x++;
		}
		coor->y++;
	}
	return (0);
}
