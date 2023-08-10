/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rule.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:51:28 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/29 17:52:11 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_up(int **board, int c_idx, int size)
{
	int	rule;
	int	idx;
	int	max;
	int	result;

	rule = board[0][c_idx];
	max = 0;
	result = 0;
	idx = 1;
	while (idx <= size)
	{
		if (board[idx][c_idx] > max)
		{
			result++;
			max = board[idx][c_idx];
		}
		idx++;
	}
	return (result == rule);
}

int	is_valid_down(int **board, int c_idx, int size)
{
	int	rule;
	int	idx;
	int	max;
	int	result;

	rule = board[size + 1][c_idx];
	max = 0;
	result = 0;
	idx = size;
	while (idx > 0)
	{
		if (board[idx][c_idx] > max)
		{
			result++;
			max = board[idx][c_idx];
		}
		idx--;
	}
	return (result == rule);
}

int	is_valid_left(int **board, int r_idx, int size)
{
	int	rule;
	int	idx;
	int	max;
	int	result;

	rule = board[r_idx][0];
	max = 0;
	result = 0;
	idx = 1;
	while (idx <= size)
	{
		if (board[r_idx][idx] > max)
		{
			result++;
			max = board[r_idx][idx];
		}
		idx++;
	}
	return (result == rule);
}

int	is_valid_right(int **board, int r_idx, int size)
{
	int	rule;
	int	idx;
	int	max;
	int	result;

	rule = board[r_idx][size + 1];
	max = 0;
	result = 0;
	idx = size;
	while (idx > 0)
	{
		if (board[r_idx][idx] > max)
		{
			result++;
			max = board[r_idx][idx];
		}
		idx--;
	}
	return (result == rule);
}
