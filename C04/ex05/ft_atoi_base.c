/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:21:58 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/26 21:27:24 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_op(char c, int flag, char *base)
{
	int	idx;

	if (flag == 3)
	{
		if (c == '\t' || c == '\n' || c == '\v')
			return (1);
		else if (c == '\r' || c == '\f' || c == ' ')
			return (1);
	}
	if (flag == 2 && (c == '-' || c == '+'))
		return (1);
	idx = 0;
	if (flag == 1)
	{
		while (base[idx] != '\0')
		{
			if (base[idx] == c)
				return (idx);
			idx++;
		}
	}
	return (-1);
}

int	ft_atoi(char *src, char *base, int size)
{
	int	res;
	int	bin;
	int	sign;

	res = 0;
	bin = 1;
	sign = 1;
	while (ft_check_op(*src, 3, "") == 1)
		src++;
	while (ft_check_op(*src, 2, "") == 1)
		if (*src++ == '-')
			sign *= -1;
	if (ft_check_op(*src, 1, base) < 0)
		return (0);
	while (ft_check_op(*src, 1, base) >= 0)
		src++;
	src--;
	while (ft_check_op(*src, 1, base) >= 0)
	{
		res += bin * ft_check_op(*src--, 1, base);
		bin *= size;
	}
	return (sign * res);
}

int	ft_check_base(int size, char *base)
{
	int		here;
	int		idx;
	char	temp;

	here = 0;
	idx = 0;
	if (size <= 1)
		return (0);
	while (here < size)
	{
		idx = here + 1;
		temp = base[here];
		if (base[here] == '+' || base[here] == '-')
			return (0);
		if (ft_check_op(base[here], 3, "") == 1)
			return (0);
		while (idx < size)
		{
			if (base[idx++] == temp)
				return (0);
		}
		here++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		atoi_retn;
	int		base_size;
	char	*temp;

	temp = base;
	base_size = 0;
	while (*temp++)
		base_size++;
	if (!ft_check_base(base_size, base))
		return (0);
	atoi_retn = ft_atoi(str, base, base_size);
	return (atoi_retn);
}
