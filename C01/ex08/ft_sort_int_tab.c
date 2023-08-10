/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:58:59 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/20 22:24:25 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	here;
	int	idx;
	int	min;
	int	min_idx;

	here = 0;
	while (here < size)
	{
		idx = here;
		min = tab[idx];
		min_idx = here;
		while (idx < size)
		{
			if (tab[idx] < min)
			{
				min = tab[idx];
				min_idx = idx;
			}
			idx++;
		}
		ft_swap(&tab[here], &tab[min_idx]);
		here++;
	}
}
