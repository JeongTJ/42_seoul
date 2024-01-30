/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:38:20 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/24 14:36:09 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp_2(char *str, char *to_find)
{
	while (1)
	{
		if (*to_find == '\0')
			return (1);
		if (*str != *to_find)
			return (0);
		if (*str == '\0')
			return (0);
		str++;
		to_find++;
	}
}

char	*ft_strstr(char *str, char *to_find)
{
	int		flag;

	if (*str == *to_find && *to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		flag = ft_strcmp_2(str, to_find);
		if (flag)
			return (str);
		str++;
	}
	return (0);
}
