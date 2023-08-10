/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:38:33 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/23 15:24:29 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	idx;

	idx = 0;
	while (idx < size / 2)
	{
		temp = tab[idx];
		tab[idx] = tab[size - 1 - idx];
		tab[size - 1 - idx] = temp;
		idx++;
	}
}
