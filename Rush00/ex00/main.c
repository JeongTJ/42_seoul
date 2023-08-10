/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jickim <jickim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:59:01 by jickim            #+#    #+#             */
/*   Updated: 2023/07/22 19:47:35 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);
void	ft_putchar(char c);

int	ft_size(char *s1)
{
	int	size;

	size = 0;
	while (*s1 != '\0')
	{
		s1++;
		size++;
	}
	return (size);
}

int	ft_atoi(char *s1)
{
	int	res;
	int	size;
	int	idx;
	int	ten;

	size = ft_size(s1);
	idx = size - 1;
	res = 0;
	ten = 1;
	while (idx >= 0)
	{
		if (s1[idx] == '-')
			res *= -1;
		else
		{
			res += ten * (int)(s1[idx] - '0');
			ten *= 10;
		}
		idx--;
	}
	return (res);
}

int	main(int args, char *argc[])
{
	if (args == 3)
		rush(ft_atoi(argc[1]), ft_atoi(argc[2]));
}
