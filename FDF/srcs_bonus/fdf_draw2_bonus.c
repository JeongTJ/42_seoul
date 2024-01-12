/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/12 15:09:46 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	fdf_cal_image_data(t_info *info, \
							t_data *rotate_data, t_data *image_data)
{
	image_data->x = rotate_data->x + (int)round(info->dx);
	image_data->y = rotate_data->y + (int)round(info->dy);
	image_data->x = image_data->x + (image_data->x - WIDTH / 2) * \
									(pow(2, info->zoom_level) - 1);
	image_data->y = image_data->y + (image_data->y - HEIGHT / 2) * \
									(pow(2, info->zoom_level) - 1);
	image_data->t = rotate_data->t;
	image_data->r = rotate_data->r;
	image_data->g = rotate_data->g;
	image_data->b = rotate_data->b;
	image_data->color = rotate_data->color;
}

void	fdf_make_image_data(t_info *info)
{
	int	col;
	int	row;

	row = 0;
	while (row < info->row_size)
	{
		col = 0;
		while (col < info->col_size)
		{
			fdf_cal_image_data(info, \
			&info->rotate_data[row][col], &info->image_data[row][col]);
			col++;
		}
		row++;
	}
}

void	fdf_make_rotate_data(t_info *info)
{
	int	col;
	int	row;

	row = 0;
	while (row < info->row_size)
	{
		col = 0;
		while (col < info->col_size)
		{
			ft_memcpy(&info->rotate_data[row][col], \
					&info->data[row][col], sizeof(t_data));
			info->rotate_data[row][col].z *= 0.1;
			col++;
		}
		row++;
	}
}
