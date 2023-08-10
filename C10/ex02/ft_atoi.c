/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:58:40 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/06 14:01:08 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ex02.h"

int	ft_find(char c, char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}

int	ft_atoi(char *str)
{
	int	res;
	int	ten;

	ten = 1;
	res = 0;
	if (ft_find(*str, "0123456789") == -1)
		return (-1);
	while (ft_find(*(str + 1), "0123456789") >= 0)
		str++;
	while (ft_find(*str, "0123456789") >= 0)
	{
		res += ft_find(*str, "0123456789") * ten;
		ten *= 10;
		str--;
	}
	return (res);
}
