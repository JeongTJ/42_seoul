/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/16 20:12:24 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	fdf_key_move(int keycode, t_info *info, int movement)
{
	if (info->zoom_level < 10 && keycode == KEY_SUM)
		info->zoom_level++;
	else if (info->zoom_level > 0 && keycode == KEY_SUB)
		info->zoom_level--;
	else if (keycode == KEY_W)
		info->dy += (double)movement;
	else if (keycode == KEY_S)
		info->dy -= (double)movement;
	else if (keycode == KEY_A)
		info->dx += (double)movement;
	else if (keycode == KEY_D)
		info->dx -= (double)movement;
}

void	fdf_move_init(t_info *info)
{
	info->angle.alpha = 0;
	info->angle.beta = 0;
	info->angle.gamma = 0;
	info->dx = (double)(WIDTH / 2 - (int)info->data \
				[(int)(info->row_size / 2)][(int)(info->col_size / 2)].x);
	info->dy = (double)(HEIGHT / 2 - (int)info->data \
				[(int)(info->row_size / 2)][(int)(info->col_size / 2)].y);
	fdf_make_rotate_data(info);
	if ((info->flag & (1 << KEY_0)) != 0)
		fdf_shape(info);
	fdf_make_rotate_axis(info);
	fdf_make_rotate_box(info);
	fdf_make_image_data(info);
	info->angle.gamma = 45;
	fdf_box_projection(info);
	fdf_axis_projection(info);
	fdf_projection(info);
	info->angle.alpha = 90 - atan(sin(45 / 180.0 * M_PI)) / M_PI * 180.0;
	fdf_box_projection(info);
	fdf_axis_projection(info);
	fdf_projection(info);
}

void	fdf_rotate(t_info *info, int keycode, double dangle)
{
	if (keycode == KEY_Z)
		info->angle.alpha = dangle;
	else if (keycode == KEY_X)
		info->angle.beta = (360 - dangle);
	else if (keycode == KEY_C)
		info->angle.gamma = dangle;
}
