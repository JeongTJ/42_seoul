/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:15:55 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/09 21:15:31 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_find_char(char c, char *str)
{
	int	idx;

	idx = 0;
	if (c == '\0')
		return (-1);
	while (str[idx])
	{
		if (c != '\0' && str[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}

char	*ft_split_init(char *str, char *charset)
{
	int		idx;
	char	*res;

	res = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!res)
		return (res);
	idx = 0;
	while (str[idx])
	{
		res[idx] = str[idx];
		if (ft_find_char(res[idx], charset) >= 0)
			res[idx] = '\0';
		idx++;
	}
	res[idx] = '\0';
	return (res);
}

int	ft_split_cnt(char *str, char *charset)
{
	int	cnt;
	int	idx;

	cnt = 0;
	idx = 0;
	while (str[idx])
	{
		if (ft_find_char(str[idx], charset) >= 0)
			cnt++;
		idx++;
	}
	return (cnt);
}

char	**ft_split(char *str, char *charset)
{
	int		size;
	int		idx;
	char	*temp_start;
	char	*temp;
	char	**res;

	size = ft_split_cnt(str, charset);
	res = (char **)malloc(sizeof(char *) * (size + 1));
	temp = ft_split_init(str, charset);
	temp_start = temp;
	idx = 0;
	while (idx < size)
	{
		res[idx] = ft_strdup(temp);
		while (*temp != '\0')
			temp++;
		temp++;
		idx++;
	}
	free(temp_start);
	res[idx] = 0;
	free(str);
	return (res);
}
