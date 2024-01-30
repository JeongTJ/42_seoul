/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:33:25 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/22 15:44:25 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	flag;

	flag = 1;
	while (1)
	{
		if (*str == '\0')
			return (flag);
		if (!('a' <= *str && *str <= 'z'))
			flag = 0;
		str++;
	}
	return (flag);
}
