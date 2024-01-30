/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:19:45 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/24 14:38:46 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	cnt;
	char			*start;

	start = dest;
	while (*dest != '\0')
		dest++;
	cnt = 0;
	while (*src != '\0' && cnt < nb)
	{
		*dest++ = *src++;
		cnt++;
	}
	*dest = '\0';
	return (start);
}
