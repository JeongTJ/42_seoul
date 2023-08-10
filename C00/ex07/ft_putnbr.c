/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:08:02 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/20 15:27:46 by tajeong          ###   ########.fr       */
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
	while (ten_square > 1 && nb / ten_square == 0)
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
