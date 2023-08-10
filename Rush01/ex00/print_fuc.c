/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fuc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:13:01 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/01 12:25:43 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int **board, int size)
{
	int		c_idx;
	int		r_idx;
	char	c;

	r_idx = 0;
	while (r_idx <= size + 1)
	{
		c_idx = 0;
		while (c_idx <= size + 1)
		{
			c = (char)(board[r_idx][c_idx] + '0');
			write(1, &c, 1);
			if (c_idx != size)
				write(1, " ", 1);
			c_idx++;
		}
		write(1, "\n", 1);
		r_idx++;
	}
}
