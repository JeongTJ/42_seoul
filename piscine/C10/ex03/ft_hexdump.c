/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:55:00 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/07 14:52:34 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ex03.h"

char	**ft_init(void)
{
	char	**res;
	char	*temp;
	int		idx_res;
	int		idx_temp;

	res = (char **)malloc(sizeof(char *) * 3);
	idx_res = 0;
	while (idx_res < 3)
	{
		temp = (char *)malloc(sizeof(char) * 17);
		idx_temp = 0;
		while (idx_temp < 17)
				temp[idx_temp++] = '\0';
		res[idx_res++] = temp;
	}
	return (res);
}

int	ft_hexdump(char **file, char ***buff, int *size, int mod)
{
	int		fd;
	int		temp_size;
	char	*temp;

	fd = open(file[1], 0);
	if (fd < 0)
		return (print_error(strerror(errno), basename(file[0]), file[1]));
	while (1)
	{
		temp = (*buff)[2];
		temp_size = read(fd, temp + (*size % 16), 16 - (*size % 16));
		*size += temp_size;
		if (temp_size != 16 && (*size % 16 != 0 || temp_size == 0))
			break ;
		ft_print_buff(buff, *size, mod);
	}
	close(fd);
	return (1);
}

void	ft_repeat(int argc, char **argv, int mod)
{
	char	**buff;
	char	**temp_argv;
	int		size;
	int		idx;
	int		flag;

	flag = 0;
	buff = ft_init();
	temp_argv = (char **)malloc(sizeof(char *) * 2);
	temp_argv[0] = argv[0];
	size = 0;
	idx = 1 + mod;
	while (idx < argc)
	{
		temp_argv[1] = argv[idx];
		flag += ft_hexdump(temp_argv, &buff, &size, mod);
		idx++;
	}
	if (flag == 0)
		print_error("Bad file descriptor", basename(argv[0]), argv[argc - 1]);
	if (size == 0)
		return ;
	ft_end_of_file(buff[2], size, mod);
}

void	ft_no_file(int mod)
{
	char	**buff;
	char	*temp;
	int		size;
	int		temp_size;

	buff = ft_init();
	size = 0;
	while (1)
	{
		temp = buff[2];
		temp_size = read(0, temp + (size % 16), 16 - (size % 16));
		size += temp_size;
		if (temp_size != 16)
		{
			if (temp_size == 0)
				break ;
			if (size % 16 != 0)
				continue ;
		}
		ft_print_buff(&buff, size, mod);
	}
	if (size == 0)
		return ;
	ft_end_of_file(buff[2], size, mod);
}

int	main(int argc, char **argv)
{
	int		c_op;
	char	**buff;
	int		size;
	int		idx;

	buff = ft_init();
	size = 0;
	idx = 1;
	c_op = 0;
	if (argc > 1)
		c_op = ft_is_c(argv[1]);
	idx += c_op;
	if (argc == 1 + c_op)
	{
		ft_no_file(c_op);
	}
	else if (argc > 1 + c_op)
	{
		ft_repeat(argc, argv, c_op);
	}
	return (0);
}
