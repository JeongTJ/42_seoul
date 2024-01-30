/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:24:52 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/22 16:40:02 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check(int num)
{
	int	first_digit;
	int	second_digit;
	int	third_digit;

	first_digit = num / 100;
	second_digit = (num / 10) % 10;
	third_digit = num % 10;
	if (first_digit < second_digit && second_digit < third_digit)
	{
		return (1);
	}
	else
	{
		return (0);
	}	
}

void	ft_print_comb(void)
{
	int	i;

	i = 0;
	while (i < 1000)
	{
		if (i == 789)
		{
			ft_putchar('7');
			ft_putchar('8');
			ft_putchar('9');
		}
		else if (check(i))
		{
			ft_putchar((char)(i / 100 + '0'));
			ft_putchar((char)((i / 10) % 10 + '0'));
			ft_putchar((char)(i % 10 + '0'));
			ft_putchar(',');
			ft_putchar(' ');
		}
		i++;
	}
}
