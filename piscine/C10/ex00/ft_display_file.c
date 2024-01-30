/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:23:44 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/03 13:44:23 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (*str++)
		size++;
	return (size);
}

int	check_error(int argc)
{
	if (argc == 1)
		return (0);
	else if (argc > 2)
		return (1);
	return (-1);
}

int	error(int flag)
{
	if (flag == 0)
		write(2, "File name missing.\n", 19);
	else if (flag == 1)
		write(2, "Too many arguments.\n", 20);
	else if (flag == 2)
		write(2, "Cannot read file.\n", 18);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		fd;
	int		size;
	char	buf[1024];

	if (check_error(argc) != -1)
		return (error(check_error(argc)));
	fd = open(argv[1], O_RDWR);
	if (-1 < fd)
	{
		while (1)
		{
			size = read(fd, buf, 1024);
			if (size <= -1)
				return (error(2));
			if (size == 0)
				return (0);
			write(1, buf, size);
		}
		close(fd);
	}
	else
		return (error(2));
	return (0);
}
