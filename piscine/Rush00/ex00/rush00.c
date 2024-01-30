/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jickim <jickim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:47:35 by jickim            #+#    #+#             */
/*   Updated: 2023/07/22 19:48:28 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_row(int x, char outside, char inside)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0 || i == x - 1)
			ft_putchar(outside);
		else
			ft_putchar(inside);
		i++;
	}
}

void	rush(int x, int y)
{
	int	j;

	j = 0;
	while (x > 0 && j < y)
	{
		if (j == 0 || j == y - 1)
			print_row(x, 'o', '-');
		else
			print_row(x, '|', ' ');
		j++;
		ft_putchar('\n');
	}
}
