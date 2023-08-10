/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:09:30 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/23 19:52:32 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_alphanumeric(char c)
{
	int	flag;

	flag = 0;
	if ('0' <= c && c <= '9')
		flag = 1;
	if ('a' <= c && c <= 'z')
		flag = 2;
	if ('A' <= c && c <= 'Z')
		flag = 3;
	return (flag);
}

char	*ft_strcapitalize(char *str)
{
	char	*res;
	int		flag;

	flag = 1;
	res = str;
	while (*str != '\0')
	{
		if (flag == 1)
		{
			if (ft_alphanumeric(*str) == 2)
				*str += 'A' - 'a';
			if (ft_alphanumeric(*str) != 0)
				flag = 0;
		}
		else if (flag == 0 && ft_alphanumeric(*str) == 3)
			*str += 'a' - 'A';
		if (ft_alphanumeric(*str) == 0)
			flag = 1;
		str++;
	}
	str = res;
	return (str);
}
