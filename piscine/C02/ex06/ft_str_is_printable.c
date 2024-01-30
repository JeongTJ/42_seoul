/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:46:24 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/23 19:13:06 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	flag;

	flag = 1;
	while (1)
	{
		if (*str == '\0')
			return (flag);
		if (!(32 <= *str && *str <= 126))
			flag = 0;
		str++;
	}
	return (flag);
}
