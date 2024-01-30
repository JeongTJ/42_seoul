/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:54:41 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/27 20:28:30 by tajeong          ###   ########.fr       */
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

	cnt = 1;
	while (cnt < argc)
	{
		write(1, argv[cnt], ft_strlen(argv[cnt]));
		write(1, "\n", 1);
		cnt++;
	}
	return (0);
}
