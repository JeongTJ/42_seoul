/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/16 20:14:39 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/fdf_bonus.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (!(0 <= x && x < WIDTH && 0 <= y && y < HEIGHT))
		return ;
	dst = image->addr + \
	(y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	fdf_draw_line(t_image *image, t_data s_data, t_data e_data)
{
	const double	dx = (e_data.x - s_data.x) / \
					fmax(fabs(e_data.x - s_data.x), fabs(e_data.y - s_data.y));
	const double	dy = (e_data.y - s_data.y) / \
					fmax(fabs(e_data.x - s_data.x), fabs(e_data.y - s_data.y));
	const double	dr = (e_data.r - s_data.r) / \
					fmax(fabs(e_data.x - s_data.x), fabs(e_data.y - s_data.y));
	const double	dg = (e_data.g - s_data.g) / \
					fmax(fabs(e_data.x - s_data.x), fabs(e_data.y - s_data.y));
	const double	db = (e_data.b - s_data.b) / \
					fmax(fabs(e_data.x - s_data.x), fabs(e_data.y - s_data.y));

	while (!(dx == 0 && dy == 0) && \
			fabs(s_data.x - e_data.x) >= fabs(dx) && \
			fabs(s_data.y - e_data.y) >= fabs(dy))
	{
		fdf_trgv_to_int(&s_data);
		my_mlx_pixel_put(image, round(s_data.x), round(s_data.y), s_data.color);
		s_data.r += dr;
		s_data.g += dg;
		s_data.b += db;
		s_data.x += dx;
		s_data.y += dy;
	}
}

void	my_mlx_clear_image(t_image *image)
{
	int	col;
	int	row;

	row = 0;
	while (row < HEIGHT)
	{
		col = 0;
		while (col < WIDTH)
		{
			my_mlx_pixel_put(image, col, row, 0x0);
			col++;
		}
		row++;
	}
}

void	fdf_draw_image_data(t_info *info)
{
	int	col;
	int	row;

	row = 0;
	while (row < info->row_size)
	{
		col = 0;
		while (col < info->col_size)
		{
			if (col + 1 < info->col_size && \
			(fdf_is_drawable(info->image_data[row][col]) || \
			fdf_is_drawable(info->image_data[row][col + 1])))
				fdf_draw_line(&(info->image), info->image_data[row][col], \
									info->image_data[row][col + 1]);
			if (row + 1 < info->row_size && \
			(fdf_is_drawable(info->image_data[row][col]) || \
			fdf_is_drawable(info->image_data[row + 1][col])))
				fdf_draw_line(&(info->image), info->image_data[row][col], \
									info->image_data[row + 1][col]);
			col++;
		}
		row++;
	}
}
