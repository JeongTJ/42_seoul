/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/15 13:07:50 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/fdf_bonus.h"

static void	fdf_init_rotate_data(t_info *info)
{
	t_data	*one_image_line;
	int		col;
	int		row;

	row = 0;
	info->rotate_data = ft_calloc(info->row_size, sizeof(t_data *));
	if (info->rotate_data == NULL)
		exit(EXIT_FAILURE);
	while (row < info->row_size)
	{
		col = 0;
		one_image_line = ft_calloc(info->col_size, sizeof(t_data));
		if (one_image_line == NULL)
			exit(EXIT_FAILURE);
		info->rotate_data[row] = one_image_line;
		row++;
	}
}

static void	fdf_init_image_data(t_info *info)
{
	t_data	*one_image_line;
	int		col;
	int		row;

	row = 0;
	info->image_data = ft_calloc(info->row_size, sizeof(t_data *));
	if (info->image_data == NULL)
		exit(EXIT_FAILURE);
	while (row < info->row_size)
	{
		col = 0;
		one_image_line = ft_calloc(info->col_size, sizeof(t_data));
		if (one_image_line == NULL)
			exit(EXIT_FAILURE);
		info->image_data[row] = one_image_line;
		row++;
	}
}

void	fdf_init(t_info *info, char *file)
{
	info->row_size = 0;
	info->col_size = 0;
	info->zoom_level = 1;
	info->vars.mlx = mlx_init();
	info->vars.win = mlx_new_window(info->vars.mlx, \
									WIDTH, HEIGHT, "Hellow World!");
	info->image.img = mlx_new_image(info->vars.mlx, \
									WIDTH, HEIGHT);
	info->image.addr = mlx_get_data_addr(info->image.img, \
								&info->image.bits_per_pixel, \
								&info->image.line_length, &info->image.endian);
	fdf_parsing(info, file);
	fdf_color_init(info);
	fdf_init_rotate_data(info);
	fdf_init_image_data(info);
	fdf_init_axis(info);
	fdf_init_box(info);
	fdf_make_rotate_box(info);
	fdf_make_rotate_axis(info);
	fdf_make_rotate_data(info);
	fdf_move_init(info);
	mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
							info->image.img, 0, 0);
}
