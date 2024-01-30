/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:32:59 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/06 12:26:39 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ex03.h"

void	ft_end_of_file(char *str, int size, int mod)
{
	if (size % 16 != 0)
		ft_print_memory(str, size - (size % 16), size % 16, mod);
	write(1, ft_int_to_hex(size, mod), 7 + mod);
	write(1, "\n", 1);
}

void	ft_print_buff(char ***buff, int size, int mod)
{
	char	**temp;

	temp = *buff;
	if (ft_strcmp(temp[1], temp[2]) == 0)
	{
		if (ft_strcmp(temp[0], temp[2]) != 0)
			write(1, "*\n", 2);
	}
	else
	{
		ft_print_memory(temp[2], size - 16, 16, mod);
	}
	ft_strncpy(temp[0], temp[1], 16);
	ft_strncpy(temp[1], temp[2], 16);
}

void	ft_print_memory(char *str, int size, int len, int mod)
{
	int		idx;
	char	*res;

	idx = 0;
	res = ft_int_to_hex(size, mod);
	write(1, res, 7 + mod);
	while (idx < 16)
	{
		write(1, "  ", 1 + (idx % 8 == 0 && mod == 1));
		if (idx < len)
			write(1, ft_char_to_hex(str[idx]), 2);
		else
			write(1, "  ", 2);
		idx++;
	}
	if (mod == 1)
		ft_print_last(str, len);
	write(1, "\n", 1);
}

void	ft_print_last(char *str, int len)
{
	int	idx;

	idx = 0;
	write(1, "  |", 3);
	while (idx < 16)
	{
		if (idx < len)
		{
			if (32 <= str[idx] && str[idx] <= 126)
				write(1, &str[idx], 1);
			else
				write(1, ".", 1);
		}
		idx++;
	}
	write(1, "|", 1);
}
