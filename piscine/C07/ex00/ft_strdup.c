/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:11:56 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/30 11:32:47 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (*str++)
		size++;
	return (size);
}

char	*ft_strdup(char *src)
{
	char	*res;
	char	*temp;

	res = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (res == 0)
		return (0);
	temp = res;
	while (*src != '\0')
		*res++ = *src++;
	*res = '\0';
	return (temp);
}
