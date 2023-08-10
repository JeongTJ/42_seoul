/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:34:27 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/25 17:47:40 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	div_num;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (0);
	if (nb == 2)
		return (1);
	div_num = 2;
	while (div_num < 1000000 && div_num < nb)
	{
		if (nb % div_num == 0)
			return (0);
		div_num++;
	}
	return (1);
}
