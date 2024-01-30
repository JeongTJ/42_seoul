/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:07:20 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/07 19:11:18 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ex03.h"

void	ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	while (idx < n)
	{
		dest[idx] = src[idx];
		idx++;
	}
}

char	*ft_char_to_hex(char c)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * 3);
	res[0] = "0123456789abcdef"[(unsigned char)c / 16];
	res[1] = "0123456789abcdef"[(unsigned char)c % 16];
	res[2] = '\0';
	return (res);
}

char	*ft_int_to_hex(int size, int mod)
{
	int		idx;
	char	*res;

	res = (char *)malloc(sizeof(char) * (8 + mod));
	idx = 6 + mod;
	res[7 + mod] = '\0';
	while (idx >= 0)
	{
		res[idx] = "0123456789abcdef"[size % 16];
		size /= 16;
		idx--;
	}
	return (res);
}
