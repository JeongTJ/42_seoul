/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:28:47 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/09 21:03:56 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

char	*ft_strdup(char *str)
{
	char	*res;
	int		idx;

	idx = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!res)
		return (res);
	while (str[idx])
	{
		res[idx] = str[idx];
		idx++;
	}
	res[idx] = '\0';
	return (res);
}

void	ft_strcpy(char *dest, char *src)
{
	int	idx;

	idx = 0;
	while (src[idx] != 0)
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
}

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (*str++)
		size++;
	return (size);
}
