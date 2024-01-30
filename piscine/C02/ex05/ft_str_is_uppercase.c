/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:44:48 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/22 15:45:58 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	flag;

	flag = 1;
	while (1)
	{
		if (*str == '\0')
			return (flag);
		if (!('A' <= *str && *str <= 'Z'))
			flag = 0;
		str++;
	}
	return (flag);
}
