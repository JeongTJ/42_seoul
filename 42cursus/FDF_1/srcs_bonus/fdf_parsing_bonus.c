/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/16 20:14:55 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/fdf_bonus.h"

static int	fdf_atoi_base(char *str, char *base)
{
	int	res;
	int	digit;
	int	sixteen;

	sixteen = 1;
	res = 0;
	while (*str != '\0' && *str != '\n')
		str++;
	str--;
	while (*str != 'x')
	{
		digit = (int)(ft_strchr(base, *str) - base);
		if (digit < 0)
			digit = (int)(ft_strchr(base, (*str | 32)) - base);
		res += sixteen * digit;
		sixteen *= 16;
		str--;
	}
	return (res);
}

static void	fdf_set_data_size(t_info *info, t_list *data_lst)
{
	int		row;
	int		col;
	char	**split_res;

	row = 0;
	while (data_lst != NULL)
	{
		col = 0;
		split_res = ft_split((char *)data_lst->content, ' ');
		while (split_res[col] != NULL && split_res[col][0] != '\n')
			col++;
		if (info->col_size != 0 && info->col_size != col)
			exit(EXIT_FAILURE);
		info->col_size = col;
		row++;
		data_lst = data_lst->next;
		col = 0;
		while (split_res[col] != NULL)
			free(split_res[col++]);
		free(split_res);
	}
	info->row_size = row;
}

static void	fdf_init_info_data(t_info *info)
{
	int		row;
	int		col;
	t_data	*one_line;

	row = 0;
	info->data = ft_calloc(info->row_size, sizeof(t_data *));
	if (info->data == NULL)
		exit(EXIT_FAILURE);
	while (row < info->row_size)
	{
		col = 0;
		one_line = ft_calloc(info->col_size, sizeof(t_data));
		if (one_line == NULL)
			exit(EXIT_FAILURE);
		while (col < info->col_size)
		{
			one_line[col].y = row - info->row_size / 2;
			one_line[col].x = col - info->col_size / 2;
			one_line[col].color = 0x0;
			col++;
		}
		info->data[row] = one_line;
		row++;
	}
}

static void	fdf_input_data(t_info *info, t_list *data_lst)
{
	char	**split_res;
	int		row;
	int		col;

	row = 0;
	while (data_lst != NULL)
	{
		col = 0;
		split_res = ft_split((char *)data_lst->content, ' ');
		while (split_res[col] != NULL && split_res[col][0] != '\n')
		{
			info->data[row][col].z = ft_atoi(split_res[col]);
			if (ft_strchr(split_res[col], ',') != NULL)
				info->data[row][col].color = \
				fdf_atoi_base(&(ft_strchr(split_res[col], ',')[1]), \
								"0123456789abcdef");
			col++;
		}
		row++;
		data_lst = data_lst->next;
		col = 0;
		while (split_res[col] != NULL)
			free(split_res[col++]);
		free(split_res);
	}
}

void	fdf_parsing(t_info *info, char *file)
{
	t_list	*data_lst;
	t_list	*new_node;
	int		fd;
	char	*line;

	data_lst = NULL;
	fd = open(file, O_RDONLY);
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		new_node = ft_lstnew(line);
		if (new_node == NULL)
			exit(EXIT_FAILURE);
		ft_lstadd_back(&data_lst, new_node);
	}
	if (fd == -1 || data_lst == NULL)
		exit(EXIT_FAILURE);
	if (close(fd) == -1)
		exit(EXIT_FAILURE);
	fdf_set_data_size(info, data_lst);
	fdf_init_info_data(info);
	fdf_input_data(info, data_lst);
	ft_lstclear(&data_lst, free);
}
