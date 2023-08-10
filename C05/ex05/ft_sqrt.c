/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:30:06 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/25 17:37:33 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	sqrt_num;

	if (nb < 0)
		return (0);
	sqrt_num = 1;
	while (sqrt_num < 100000)
	{
		if (nb % sqrt_num == 0 && sqrt_num == nb / sqrt_num)
			return (sqrt_num);
		sqrt_num++;
	}
	return (0);
}
