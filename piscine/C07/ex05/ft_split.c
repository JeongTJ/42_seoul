/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:08:09 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/02 17:59:31 by tajeong          ###   ########.fr       */
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

char	*ft_str_init(char *str, char *charset)
{
	char	*res;
	int		idx;
	int		set_idx;
	int		size;

	size = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (res == 0)
		return (0);
	idx = 0;
	while (idx < size)
	{
		set_idx = 0;
		res[idx] = str[idx];
		while (charset[set_idx])
		{
			if (str[idx] == charset[set_idx])
				res[idx] = charset[0];
			set_idx++;
		}
		idx++;
	}
	res[size] = '\0';
	return (res);
}

int	ft_sep_size(char *str, char c)
{
	int	res;
	int	str_size;
	int	idx;

	str_size = ft_strlen(str);
	idx = 1;
	res = 0;
	if (str[0] != c && str[0] != '\0')
		res = 1;
	while (idx < str_size)
	{
		if (str[idx - 1] == c && str[idx] != c)
			res++;
		idx++;
	}
	return (res);
}

char	*ft_find_sep_start(char **str, char c)
{
	char	*res;
	int		size;
	int		idx;

	while (*(*str) == c && *(*str) != '\0')
		(*str)++;
	size = 0;
	idx = 0;
	while ((*str)[idx] != c && (*str)[idx] != '\0')
	{
		size++;
		idx++;
	}
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (res == 0)
		return (0);
	idx = 0;
	while (*(*str) != c && *(*str) != '\0')
	{
		res[idx++] = *(*str)++;
	}
	res[idx] = '\0';
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	char	*init_str;
	int		size;
	int		idx;

	init_str = ft_str_init(str, charset);
	if (init_str == 0)
		return (0);
	size = ft_sep_size(init_str, charset[0]);
	res = (char **)malloc(sizeof(char *) * (size + 1));
	if (res == 0)
		return (0);
	idx = 0;
	while (idx < size)
	{
		res[idx] = ft_find_sep_start(&init_str, charset[0]);
		if (res[idx] == 0)
			return (0);
		idx++;
	}
	res[idx] = 0;
	return (res);
}
