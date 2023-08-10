/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:51:32 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/06 14:03:06 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#include <fcntl.h>

void	print_error(char *error_msg, char *command, char *file);

void	ft_cat_no_argv(void)
{
	unsigned char	buff[1024];
	int				size;

	while (1)
	{
		size = read(0, buff, 1024);
		if (size > 0)
			write(1, buff, size);
		else
			break ;
	}
}

void	ft_cat_argv(int argc, char **argv)
{
	unsigned char	buff[1024];
	int				size;
	int				fd;
	int				idx;

	idx = 1;
	while (idx < argc)
	{
		fd = open(argv[idx], 0);
		if (fd > -1)
		{
			while (1)
			{
				size = read(fd, buff, 1024);
				if (size == 0)
					break ;
				write(1, buff, size);
			}
		}
		else
			print_error(strerror(errno), basename(argv[0]), argv[idx]);
		idx++;
	}
}

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (*str++)
		size++;
	return (size);
}

void	print_error(char *error_msg, char *command, char *file)
{
	write(2, command, ft_strlen(command));
	write(2, ": ", 2);
	write(2, file, ft_strlen(file));
	write(2, ": ", 2);
	write(2, error_msg, ft_strlen(error_msg));
	write(2, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_cat_no_argv();
	else
		ft_cat_argv(argc, argv);
	return (0);
}
