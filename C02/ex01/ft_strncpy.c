/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:10:15 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/24 11:30:48 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*res;
	unsigned int	cnt;

	res = dest;
	cnt = 0;
	while (*src != '\0' && cnt < n)
	{
		*dest++ = *src++;
		cnt++;
	}
	while (*dest != '\0' && cnt < n)
	{
		*dest++ = '\0';
		cnt++;
	}
	return (res);
}
