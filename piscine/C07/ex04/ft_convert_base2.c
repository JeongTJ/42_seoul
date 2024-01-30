/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:27:25 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/30 20:45:16 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_find_char(char c, char *base);
int		ft_check_base(char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (*str++)
		size++;
	return (size);
}

void	ft_int_to_base(int nb, char *base_to, char **res, int size)
{
	int	idx;

	idx = size;
	if (nb == 0)
		(*res)[0] = base_to[0];
	if (nb < 0)
	{
		(*res)[0] = '-';
		(*res)[idx] = base_to[-(nb % ft_strlen(base_to))];
		nb = -(nb / ft_strlen(base_to));
		idx--;
	}
	while (nb > 0)
	{
		(*res)[idx] = base_to[nb % ft_strlen(base_to)];
		nb /= ft_strlen(base_to);
		idx--;
	}
}

int	ft_convert_base2(char *nbr, char *base_from)
{
	int	res;
	int	bin;
	int	sign;

	res = 0;
	bin = 1;
	sign = 1;
	while (ft_find_char(*nbr, "\t\n\v\r\f ") >= 0)
		nbr++;
	while (ft_find_char(*nbr, "+-") >= 0)
		if (*nbr++ == '-')
			sign *= -1;
	if (ft_find_char(*nbr, base_from) == -1)
		return (0);
	while (ft_find_char(*(nbr +1), base_from) >= 0)
		nbr++;
	while (ft_find_char(*nbr, base_from) >= 0)
	{
		res += bin * (ft_find_char(*nbr, base_from));
		bin *= ft_strlen(base_from);
		nbr--;
	}
	return (sign * res);
}
