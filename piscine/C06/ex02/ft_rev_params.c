/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:01:16 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/27 20:28:49 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (*str++)
		size++;
	return (size);
}

int	main(int argc, char *argv[])
{
	int	cnt;

	cnt = argc - 1;
	while (cnt > 0)
	{
		write(1, argv[cnt], ft_strlen(argv[cnt]));
		write(1, "\n", 1);
		cnt--;
	}
	return (0);
}
