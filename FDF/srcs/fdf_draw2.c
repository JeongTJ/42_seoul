/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/05 20:42:32 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

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

void	fdf_move_one_data(t_info *info, t_data *image_data, int keycode,
							int move_scalse)
{
	if (keycode == KEY_SUM)
	{
		image_data->x = image_data->x + (image_data->x - WIDTH / 2);
		image_data->y = image_data->y + (image_data->y - HEIGHT / 2);
	}
	else if (info->zoom_level > 0 && keycode == KEY_SUB)
	{
		image_data->x = image_data->x - (image_data->x - WIDTH / 2) / 2;
		image_data->y = image_data->y - (image_data->y - HEIGHT / 2) / 2;
	}
	else if (keycode == KEY_W)
		image_data->y = image_data->y - move_scalse;
	else if (keycode == KEY_S)
		image_data->y = image_data->y + move_scalse;
	else if (keycode == KEY_A)
		image_data->x = image_data->x - move_scalse;
	else if (keycode == KEY_D)
		image_data->x = image_data->x + move_scalse;

}

void	fdf_move_data(t_info *info, int keycode)
{
	int	col;
	int	row;

	row = 0;
	while (row < info->row_size)
	{
		col = 0;
		while (col < info->col_size)
		{
			fdf_move_one_data(info, &info->image_data[row][col], \
								keycode, 10);
			col++;
		}
		row++;
	}
	if (keycode == KEY_SUM)
		info->zoom_level++;
	else if (info->zoom_level > 0 && keycode == KEY_SUB)
		info->zoom_level--;
}

void	fdf_move_init(t_info *info)
{
	const int	dx = WIDTH / 2 - (int)info->image_data \
				[(int)(info->row_size / 2)][(int)(info->col_size / 2)].x;
	const int	dy = HEIGHT / 2 - (int)info->image_data \
				[(int)(info->row_size / 2)][(int)(info->col_size / 2)].y;
	int			col;
	int			row;

	row = dx;
	col = dy;
	row = 0;
	while (row < info->row_size)
	{
		col = 0;
		while (col < info->col_size)
		{
			info->image_data[row][col].x += dx;
			info->image_data[row][col].y += dy;
			col++;
		}
		row++;
	}
}
