/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:37:40 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/29 18:14:11 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_op(char c, int flag)
{
	if (flag == 3)
	{
		if (c == '\t' || c == '\n' || c == '\v')
			return (1);
		else if (c == '\r' || c == '\f' || c == ' ')
			return (1);
	}
	if (flag == 2 && (c == '-' || c == '+'))
		return (1);
	if (flag == 1 && ('0' <= c && c <= '9'))
		return (1);
	return (0);
}

int	ft_atoi(char *src)
{
	int	res;
	int	ten;
	int	sign;

	res = 0;
	ten = 1;
	sign = 1;
	while (ft_check_op(*src, 3))
		src++;
	while (ft_check_op(*src, 2))
		if (*src++ == '-')
			sign *= -1;
	if (!ft_check_op(*src, 1))
		return (0);
	while (ft_check_op(*(src + 1), 1) && ft_check_op(*src, 1))
		src++;
	while (ft_check_op(*src, 1))
	{
		res += ten * (int)((*src--) - '0');
		ten *= 10;
	}
	return (sign * res);
}
