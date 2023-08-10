/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:36:35 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/26 21:14:12 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	size;

	size = 0;
	while (*str != '\0')
	{
		str++;
		size++;
	}
	return (size);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	res;
	unsigned int	cnt;

	cnt = 0;
	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	res = ft_strlen(src) + ft_strlen(dest);
	while (*dest != '\0')
	{
		cnt++;
		dest++;
	}
	while (cnt + 1 < size && *src != '\0')
	{
		*dest++ = *src++;
		cnt++;
	}
	*dest = '\0';
	return (res);
}
