/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:51:41 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/09 19:20:56 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

t_position	*ft_make_coor(char *title, char *one_line)
{
	int			size;
	t_position	*coor;

	size = ft_strlen(title);
	coor = (t_position *)malloc(sizeof(t_position) * 1);
	coor->e_o_f = (char *)malloc(sizeof(char) * 4);
	coor->x = 0;
	coor->y = 0;
	coor->x_size = ft_strlen(one_line);
	coor->y_size = ft_small_atoi(title);
	coor->e_o_f[0] = title[size - 3];
	coor->e_o_f[1] = title[size - 2];
	coor->e_o_f[2] = title[size - 1];
	coor->e_o_f[3] = '\0';
	return (coor);
}

void	free_all(t_position *coor, char **board)
{
	int	idx;

	idx = 0;
	if (coor)
	{
		free(coor->e_o_f);
		free(coor);
	}
	while (board[idx])
	{
		free(board[idx]);
		idx++;
	}
	free(board);
}

void	no_file(void)
{
	t_position	*coor;
	char		**res;

	res = ft_split(ft_std_input(), "\n");
	if (!res || !ft_is_valid(res))
	{
		print_error("map error");
		free_all(NULL, res);
	}
	else
	{
		coor = ft_make_coor(res[0], res[1]);
		ft_biggest_square(res + 1, coor, 1);
		print_board(res + 1, coor->x_size, coor->y_size);
		free_all(coor, res);
	}
}

void	yes_file(int argc, char **argv)
{
	int			idx;
	t_position	*coor;
	char		**res;

	idx = 1;
	while (idx < argc)
	{
		res = ft_split(ft_file_input(argv[idx]), "\n");
		if (!res || !ft_is_valid(res))
		{
			print_error("map error");
			free_all(NULL, res);
		}
		else
		{
			coor = ft_make_coor(res[0], res[1]);
			ft_biggest_square(res + 1, coor, 1);
			print_board(res + 1, coor->x_size, coor->y_size);
			free_all(coor, res);
		}
		if (idx != argc - 1)
			write(1, "\n", 1);
		idx++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		no_file();
	else
		yes_file(argc, argv);
	return (0);
}
