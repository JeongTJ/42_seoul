/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:51:14 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/25 20:36:26 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_fill_impos_loc(char *chess_loc, int *impos_loc, int here)
{
	int	idx;

	idx = 0;
	while (idx < here)
	{
		if (0 <= (int)(chess_loc[idx] - '0') - (here - idx))
			impos_loc[(int)(chess_loc[idx] - '0') - (here - idx)] = 1;
		if ((int)(chess_loc[idx] - '0') + (here - idx) < 10)
			impos_loc[(int)(chess_loc[idx] - '0') + (here - idx)] = 1;
		impos_loc[(int)(chess_loc[idx] - '0')] = 1;
		idx++;
	}
}

void	ft_fill_queens(char *chess_loc, int here, int *nb)
{
	int	impos_loc[11];
	int	idx;

	if (here == 10)
	{
		(*nb)++;
		write(1, chess_loc, 10);
		write(1, "\n", 1);
		return ;
	}
	idx = 0;
	while (idx < 10)
		impos_loc[idx++] = 0;
	idx = 0;
	ft_fill_impos_loc(chess_loc, impos_loc, here);
	while (idx < 10 && here != 10)
	{
		if (!impos_loc[idx])
		{
			chess_loc[here] = (char)(idx + '0');
			ft_fill_queens(chess_loc, here + 1, nb);
		}
		idx++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	chess_board[11];
	int		idx;
	int		res;

	res = 0;
	idx = 0;
	while (chess_board[idx])
	{
		chess_board[idx] = '-';
	}
	ft_fill_queens(chess_board, 0, &res);
	return (res);
}
