/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:08:29 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/22 16:44:35 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	ten_square;

	ten_square = 1000000000;
	if (nb < 0)
	{
		ft_putchar('-');
	}
	while (ten_square > 10 && nb / ten_square == 0)
	{
		ten_square /= 10;
	}
	while (ten_square > 0)
	{
		if ((nb / ten_square) % 10 < 0)
		{
			ft_putchar((char)(-((nb / ten_square) % 10) + '0'));
		}
		else
		{
			ft_putchar((char)((nb / ten_square) % 10 + '0'));
		}
		ten_square /= 10;
	}
}

void	ft_print_comb2(void)
{
	int	first_num;
	int	second_num;

	first_num = 0;
	second_num = 0;
	while (first_num < 98)
	{
		second_num = first_num + 1;
		while (second_num < 100)
		{				
			ft_putnbr(first_num);
			ft_putchar(' ');
			ft_putnbr(second_num);
			write(1, ", ", 2);
			second_num++;
		}
		first_num++;
	}
	write(1, "98 99", 5);
}
