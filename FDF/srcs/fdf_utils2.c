/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/05 20:43:26 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	fdf_projection(t_info *info)
{
	int	col;
	int	row;

	row = 0;
	while (row < info->row_size)
	{
		col = 0;
		while (col < info->col_size)
		{
			fdf_cal_projection(info, &info->image_data[row][col], &info->data[row][col]);
			col++;
		}
		row++;
	}
}

void	fdf_cal_projection(t_info *info, t_data *image_data, t_data *data)
{
	const double	alpha = info->angle.alpha / 180.0 * M_PI;
	const double	beta = info->angle.beta / 180.0 * M_PI;
	const double	gamma = info->angle.gamma / 180.0 * M_PI;

	image_data->x = data->x * (cos(beta) * cos(gamma)) + \
					data->y * (sin(alpha) * sin(beta) * cos(gamma) - \
								cos(alpha) * sin(gamma)) + \
					data->z * (cos(alpha) * sin(beta) * cos(gamma) + \
								sin(alpha) * sin(gamma));
	image_data->y = data->x * (cos(beta) * sin(gamma)) + \
					data->y * (sin(alpha) * sin(beta) * sin(gamma) + \
								cos(alpha) * cos(gamma)) + \
					data->z * (cos(alpha) * sin(beta) * sin(gamma) - \
								sin(alpha) * cos(gamma));
	image_data->z = data->x * (-sin(beta)) + \
					data->y * (sin(alpha) * cos(beta)) + \
					data->z * (cos(alpha) * cos(beta));
	image_data->x *= (1 << info->zoom_level);
	image_data->y *= (1 << info->zoom_level);
	image_data->z *= (1 << info->zoom_level);
	image_data->color = data->color;
	image_data->t = data->t;
	image_data->r = data->r;
	image_data->g = data->g;
	image_data->b = data->b;
}

void	fdf_rotate(t_info *info, int keycode)
{
	if (keycode == KEY_Z)
	{
		info->angle.alpha += 5;
		if (info->angle.alpha > 360)
			info->angle.alpha -= 360;
	}
	else if (keycode == KEY_X)
	{
		info->angle.beta += 355;
		if (info->angle.beta > 360)
			info->angle.beta -= 360;
	}
	else if (keycode == KEY_C)
	{
		info->angle.gamma += 5;
		if (info->angle.gamma > 360)
			info->angle.gamma -= 360;
	}
}
