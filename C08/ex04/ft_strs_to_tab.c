/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:28:47 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/02 16:35:59 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char*str)
{
	int	size;

	size = 0;
	while (*str++)
		size++;
	return (size);
}

char	*ft_strdup(char *str)
{
	char	*dup_str;
	int		idx;

	idx = 0;
	dup_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dup_str == 0)
		return (0);
	while (idx < ft_strlen(str))
	{
		dup_str[idx] = str[idx];
		idx++;
	}
	dup_str[idx] = '\0';
	return (dup_str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*res;
	int			idx;

	res = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (res == 0)
		return (0);
	idx = 0;
	while (idx < ac)
	{
		res[idx].size = ft_strlen(av[idx]);
		res[idx].str = av[idx];
		res[idx].copy = ft_strdup(av[idx]);
		if (res[idx].copy == 0)
			return (0);
		idx++;
	}
	res[idx].str = 0;
	return (res);
}
