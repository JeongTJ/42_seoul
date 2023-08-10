/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:29:03 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/07 19:13:01 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ex02.h"

void	print_tail(int flag, char *file)
{
	if (flag == 2)
		write(1, "\n", 1);
	if (flag == 1 || flag == 2)
	{
		write(1, "==> ", 4);
		write(1, file, ft_strlen(file));
		write(1, " <==\n", 5);
	}
}

int	print_not_file(int N)
{
	char	*circle_buff;
	char	*one_buff;
	int		idx;
	int		size;

	circle_buff = ft_init(N);
	one_buff = ft_init(1);
	if (!(one_buff && circle_buff))
		return (0);
	idx = 0;
	while (1)
	{
		size = read(0, one_buff, 1);
		if (size == 0)
			break ;
		if (N != 0)
		{
			circle_buff[idx] = one_buff[0];
			idx = (idx + 1) % N;
		}
	}
	write(1, circle_buff + idx, ft_strlen(circle_buff + idx));
	write(1, circle_buff, idx);
	return (1);
}
