/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:03:13 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/29 15:25:23 by tajeong          ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0' && *s2 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return ((int)(*s1 - *s2));
}

void	ft_swap_char(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	ft_argv_sort(int argc, char **argv)
{
	int	here;

	while (argc > 0)
	{
		here = 1;
		while (here < argc - 1)
		{
			if (ft_strcmp(argv[here], argv[here + 1]) > 0)
				ft_swap_char(&argv[here], &argv[here + 1]);
			here++;
		}
		argc--;
	}
}

int	main(int argc, char *argv[])
{
	int	idx;

	idx = 1;
	ft_argv_sort(argc, argv);
	while (idx < argc)
	{
		write(1, argv[idx], ft_strlen(argv[idx]));
		write(1, "\n", 1);
		idx++;
	}
}
