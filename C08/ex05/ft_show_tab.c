/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:45:25 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/02 16:44:07 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (*str++)
		size++;
	return (size);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putnbr(int nb)
{
	char	temp;

	if (nb < 0)
	{
		write(1, "-", 1);
		if (-(nb / 10) > 0)
			ft_putnbr(-(nb / 10));
		temp = (char)(-(nb % 10) + '0');
		write(1, &temp, 1);
	}
	if (nb >= 0)
	{
		if (nb / 10 > 0)
			ft_putnbr(nb / 10);
		temp = (char)((nb % 10) + '0');
		write(1, &temp, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	while ((*par).str != 0)
	{
		ft_putstr((*par).str);
		write(1, "\n", 1);
		ft_putnbr((*par).size);
		write(1, "\n", 1);
		ft_putstr((*par).copy);
		write(1, "\n", 1);
		par++;
	}
}
