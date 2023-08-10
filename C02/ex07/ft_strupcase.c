/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:53:00 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/22 16:12:58 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*res;

	res = str;
	while (1)
	{
		if (*str == '\0')
		{
			str = res;
			return (str);
		}
		if ('a' <= *str && *str <= 'z')
			*str += 'A' - 'a';
		str++;
	}
}
