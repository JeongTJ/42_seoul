/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fuc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:03:29 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/29 17:54:46 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_key(int **board, int r_here, int c_here)
{
	int	flag;
	int	r_idx;
	int	c_idx;

	r_idx = 1;
	c_idx = 1;
	flag = 1;
	while (r_idx < r_here)
	{
		if (board[r_idx][c_here] == board[r_here][c_here])
			flag = 0;
		r_idx++;
	}
	while (c_idx < c_here)
	{
		if (board[r_here][c_idx] == board[r_here][c_here])
			flag = 0;
		c_idx++;
	}
	return (flag);
}
