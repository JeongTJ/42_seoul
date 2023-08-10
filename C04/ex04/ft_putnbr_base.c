/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:35:12 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/25 15:56:38 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_base(char *base)
{
	int		here;
	int		idx;
	char	temp;

	here = 0;
	idx = 0;
	if (*base == '\0' || *(base + 1) == '\0')
		return (0);
	while (base[here] != '\0')
	{
		idx = here + 1;
		temp = base[here];
		if (base[here] == '+' || base[here] == '-')
			return (0);
		while (base[idx] != '\0')
		{
			if (base[idx] == temp)
				return (0);
			idx++;
		}
		here++;
	}
	return (1);
}

int	ft_strlen(char *base)
{
	int	size;

	size = 0;
	while (*base++)
		size++;
	return (size);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;

	size = ft_strlen(base);
	if (!ft_check_base(base))
		return ;
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		ft_putnbr_base(-(nbr / size), base);
		write(1, &base[-(nbr % size)], 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base(-nbr, base);
	}
	if (nbr >= 0)
	{
		if (nbr / size > 0)
			ft_putnbr_base(nbr / size, base);
		write(1, &base[nbr % size], 1);
	}
}
