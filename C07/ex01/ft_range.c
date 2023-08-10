/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:36:33 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/30 11:40:50 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*res;
	int	idx;

	if (max <= min)
		return (0);
	res = (int *)malloc(sizeof(int) * (max - min));
	if (res == 0)
		return (0);
	idx = 0;
	while (idx < max - min)
	{
		res[idx] = min + idx;
		idx++;
	}
	return (res);
}
