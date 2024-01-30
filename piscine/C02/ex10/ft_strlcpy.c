/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:55:40 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/24 18:34:19 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_size(char *src)
{
	unsigned int	size;

	size = 0;
	while (*src != '\0')
	{
		src++;
		size++;
	}
	return (size);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int n)
{
	unsigned int	cnt;
	unsigned int	size;

	size = ft_size(src);
	cnt = 0;
	if (n <= 0)
		return (size);
	while (cnt < size && cnt < n - 1)
	{
		dest[cnt] = src[cnt];
		cnt++;
	}
	dest[cnt] = '\0';
	return (size);
}
