/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:09:03 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/07 14:58:13 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ex02.h"

int	print_error(char *error_msg, char *command, char *file)
{
	write(2, command, ft_strlen(command));
	write(2, ": ", 2);
	write(2, file, ft_strlen(file));
	write(2, ": ", 2);
	write(2, error_msg, ft_strlen(error_msg));
	write(2, "\n", 1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (*str++)
		size++;
	return (size);
}

char	*ft_init(int size)
{
	char	*res;
	int		idx;

	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (0);
	idx = 0;
	while (idx <= size)
	{
		res[idx] = '\0';
		idx++;
	}
	return (res);
}

int	ft_tail(char **argv, int N, int idx, int *flag)
{
	char	*buff;
	int		fd;
	int		size;

	fd = open(argv[idx], 0);
	if (fd < 0)
		return (print_error(strerror(errno), basename(argv[0]), argv[idx]));
	buff = ft_init(N);
	if (!buff)
		return (2);
	while (1)
	{
		size = read(fd, buff, N);
		if (size < N || N == 0)
			break ;
	}
	print_tail(*flag, argv[idx]);
	write(1, buff + size, ft_strlen(buff + size));
	write(1, buff, size);
	*flag = 2;
	close(fd);
	free(buff);
	return (1);
}

int	main(int argc, char **argv)
{
	int	size;
	int	idx;
	int	flag;

	flag = 0;
	idx = 3;
	size = ft_atoi(argv[2]);
	if (argc == 3)
	{
		if (size == 0 || !print_not_file(size))
			return (0);
	}
	if (argc > 4)
		flag = 1;
	while (idx < argc)
	{
		if (ft_tail(argv, size, idx, &flag) == 2)
			return (0);
		idx++;
	}
	return (0);
}
