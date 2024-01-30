/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:19:31 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/30 20:45:18 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_convert_base2(char *nbr, char *base_from);
void	ft_int_to_base(int nb, char *base_to, char **res, int size);
int		ft_strlen(char *str);

int	ft_find_char(char c, char *base)
{
	int	idx;

	idx = 0;
	while (base[idx])
	{
		if (base[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}

int	ft_check_base(char *base)
{
	int	here;
	int	next;

	here = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[here])
	{
		next = here + 1;
		if (ft_find_char(base[here], "+-\t\n\v\r\f ") >= 0)
			return (0);
		while (base[next])
		{
			if (base[here] == base[next])
				return (0);
			next++;
		}
		here++;
	}
	return (1);
}

int	ft_base_to_size(int nb, char *base_to)
{
	int	cnt;

	cnt = 1;
	while (1)
	{
		if (nb / ft_strlen(base_to) == 0)
			return (cnt);
		cnt++;
		nb /= ft_strlen(base_to);
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		ten_base_res;
	int		size;
	char	*res;

	if (!(ft_check_base(base_from) && ft_check_base(base_to)))
		return (0);
	ten_base_res = ft_convert_base2(nbr, base_from);
	size = ft_base_to_size(ten_base_res, base_to);
	if (ten_base_res < 0)
		size++;
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (res == 0)
		return (0);
	res[size] = '\0';
	ft_int_to_base(ten_base_res, base_to, &res, size - 1);
	return (res);
}
