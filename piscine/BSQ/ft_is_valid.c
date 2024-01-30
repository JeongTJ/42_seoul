/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:41:32 by inryu             #+#    #+#             */
/*   Updated: 2023/08/09 21:16:53 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_is_valid(char **board)
{
	int		i;
	int		j;
	int		len;
	char	eof[2];

	if (!board || !board[0] || ft_strlen(board[0]) < 4)
		return (0);
	eof[0] = board[0][ft_strlen(board[0]) - 3];
	eof[1] = board[0][ft_strlen(board[0]) - 2];
	i = 1;
	while (board[i])
	{
		len = ft_strlen(board[1]);
		if (len == 0 || len != ft_strlen(board[i]))
			return (0);
		j = 0;
		while (board[i][j] != '\0')
		{
			if (ft_find_char(board[i][j], eof) == -1)
				return (0);
			j++;
		}
		i++;
	}
	return (i - 1 == ft_small_atoi(board[0]));
}

int	ft_small_atoi(char *str)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while ('0' <= str[i] && str[i] <= '9' && str[i + 3] != '\0')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (nb == 0 || str[i] == str[i + 1] || str[i + 1] == str[i + 2]
		|| str[i] == str[i + 2] || str[i + 3] != '\0')
		return (-1);
	else
	{
		while (str[i] != '\0')
		{
			if (str[i] < 32 || 126 < str[i])
				return (-1);
			i++;
		}
	}
	return (nb);
}
