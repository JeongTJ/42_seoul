/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:39:33 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/20 16:52:07 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_combn(int *num, int size, int idx)
{
	int	key;

	if (size < idx)
	{
		while (idx - size <= size)
		{
			ft_putchar((char)(num[idx - size] + '0'));
			idx++;
		}
		if (!(num[1] == 10 - size && num[size] == 9))
		{
			write(1, ", ", 2);
		}
		return ;
	}
	key = 0;
	while (key < 10)
	{
		if (num[idx - 1] < key)
		{
			num[idx] = key;
			ft_combn(num, size, idx + 1);
		}
		key++;
	}
}

void	ft_print_combn(int n)
{
	int	num[10];
	int	i;

	i = 0;
	while (i < 10)
	{
		num[i] = 0;
		i++;
	}
	num[0] = -1;
	ft_combn(num, n, 1);
}
