/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:18:33 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/01 09:27:12 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (*str++)
		size++;
	return (size);
}

int	ft_res_size(int size, char **strs, char *sep)
{
	int	res_size;
	int	idx;

	if (size == 0)
		return (0);
	res_size = 0;
	idx = 0;
	while (idx < size)
		res_size += ft_strlen(strs[idx++]);
	res_size += ft_strlen(sep) * (size - 1);
	return (res_size);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*start;

	start = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (start);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		res_size;
	int		idx;
	char	*res;

	res_size = ft_res_size(size, strs, sep);
	res = (char *)malloc(sizeof(char) * (res_size + 1));
	if (res == 0)
		return (0);
	res[0] = '\0';
	idx = 0;
	while (idx < size)
	{
		res = ft_strcat(res, strs[idx]);
		if (idx != size - 1)
			res = ft_strcat(res, sep);
		idx++;
	}
	return (res);
}
