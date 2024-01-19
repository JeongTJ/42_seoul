/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/15 13:07:59 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/fdf_bonus.h"

void	fdf_rotate_alpha(t_data *rotate_data, double angle)
{
	double	tmp_x;
	double	tmp_y;
	double	tmp_z;

	tmp_x = rotate_data->x;
	tmp_y = rotate_data->y;
	tmp_z = rotate_data->z;
	rotate_data->x = tmp_x;
	rotate_data->y = tmp_y * cos(angle) - tmp_z * sin(angle);
	rotate_data->z = tmp_y * sin(angle) + tmp_z * cos(angle);
}

void	fdf_rotate_beta(t_data *rotate_data, double angle)
{
	double	tmp_x;
	double	tmp_y;
	double	tmp_z;

	tmp_x = rotate_data->x;
	tmp_y = rotate_data->y;
	tmp_z = rotate_data->z;
	rotate_data->x = tmp_x * cos(angle) + tmp_z * sin(angle);
	rotate_data->y = tmp_y;
	rotate_data->z = tmp_x * (-sin(angle)) + tmp_z * cos(angle);
}

void	fdf_rotate_gamma(t_data *rotate_data, double angle)
{
	double	tmp_x;
	double	tmp_y;
	double	tmp_z;

	tmp_x = rotate_data->x;
	tmp_y = rotate_data->y;
	tmp_z = rotate_data->z;
	rotate_data->x = tmp_x * cos(angle) - tmp_y * sin(angle);
	rotate_data->y = tmp_x * sin(angle) + tmp_y * cos(angle);
	rotate_data->z = tmp_z;
}

void	fdf_cal_projection(t_info *info, t_data *rotate_data)
{
	fdf_rotate_alpha(rotate_data, info->angle.alpha / 180.0 * M_PI);
	fdf_rotate_beta(rotate_data, info->angle.beta / 180.0 * M_PI);
	fdf_rotate_gamma(rotate_data, info->angle.gamma / 180.0 * M_PI);
}

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
			fdf_cal_projection(info, &info->rotate_data[row][col]);
			col++;
		}
		row++;
	}
	info->angle.alpha = 0;
	info->angle.beta = 0;
	info->angle.gamma = 0;
}
