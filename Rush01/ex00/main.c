/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:52:24 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/01 12:24:52 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	print(int **board, int size);
void	rush_01(int **board, int r_idx, int c_idx, int *size);

int	**make_board(int size)
{
	int	idx;
	int	**board;

	board = (int **)malloc(sizeof(int *) * (size + 2));
	idx = 0;
	while (idx < size + 2)
	{
		board[idx] = (int *)malloc(sizeof(int) * (size + 2));
		idx++;
	}
	return (board);
}

int	**board_idx(char *str, int size)
{
	int	idx;
	int	**board;

	board = make_board(size);
	idx = 0;
	while (idx < size)
	{
		board[0][idx + 1] = (int)(str[idx * 2] - '0');
		board[size + 1][idx + 1] = (int)(str[size * 2 + idx * 2] - '0');
		board[idx + 1][0] = (int)(str[size * 4 + idx * 2] - '0');
		board[idx + 1][size + 1] = (int)(str[size * 6 + idx * 2] - '0');
		idx++;
	}
	return (board);
}

int	error(char *argv)
{
	int	size;

	size = 0;
	while (argv[size])
	{
		if (size % 2 == 1 && argv[size] != ' ')
			return (-1);
		else if (size % 2 == 0 && !('0' <= argv[size] && argv[size] <= '9'))
			return (-1);
		size++;
	}
	if ((size + 1) % 8 != 0)
		return (-1);
	return ((size + 1) / 8);
}

void	board_free(int **board, int size)
{
	int	idx;

	idx = 0;
	while (idx < size + 2)
	{
		free(board[idx]);
		idx++;
	}
	free(board);
}

int	main(int argc, char **argv)
{
	int	**board;
	int	size;
	int	free_size;

	size = 0;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (error(argv[1]) == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	size = error(argv[1]);
	free_size = size;
	board = board_idx(argv[1], size);
	print(board, size);
	rush_01(board, 1, 1, &size);
	board_free(board, free_size);
	board = 0;
	if (size != 0)
		write(1, "error\n", 6);
	return (0);
}
