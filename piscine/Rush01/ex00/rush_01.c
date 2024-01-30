/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:26:49 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/30 18:31:28 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_valid_key(int **board, int r_idx, int c_idx);
int		is_valid_up(int **board, int c_idx, int size);
int		is_valid_down(int **board, int c_idx, int size);
int		is_valid_left(int **board, int r_idx, int size);
int		is_valid_right(int **board, int r_idx, int size);	
void	print(int **board, int size);

void	rush_01(int **board, int r_idx, int c_idx, int *size)
{
	int	key;

	key = 1;
	if (r_idx == *size + 1)
	{
		print(board, *size);
		*size = 0;
		return ;
	}
	while (key <= *size)
	{
		board[r_idx][c_idx] = key;
		if (is_valid_key(board, r_idx, c_idx))
		{
			if (r_idx == *size && (!is_valid_up(board, c_idx, *size) || \
					!is_valid_down(board, c_idx, *size)))
				return ;
			if (c_idx < *size)
				rush_01(board, r_idx, c_idx + 1, size);
			else if (is_valid_left(board, r_idx, *size) && \
					is_valid_right(board, r_idx, *size))
				rush_01(board, r_idx + 1, 1, size);
		}
		key++;
	}
}
