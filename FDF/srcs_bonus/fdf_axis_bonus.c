/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_axis_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/15 13:07:36 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/fdf_bonus.h"

void	fdf_init_axis(t_info *info)
{
	info->axis = ft_calloc(6, sizeof(t_data));
	if (info->axis == NULL)
		exit(EXIT_FAILURE);
	info->rotate_axis = ft_calloc(6, sizeof(t_data));
	if (info->rotate_axis == NULL)
		exit(EXIT_FAILURE);
	info->image_axis = ft_calloc(6, sizeof(t_data));
	if (info->image_axis == NULL)
		exit(EXIT_FAILURE);
	info->axis[0] = (t_data){0, 0, 0, 0, 0, 0, 0, 0xFF0000};
	info->axis[1] = (t_data){0, 0, 0, 0, 0, 0, 0, 0x00FF00};
	info->axis[2] = (t_data){0, 0, 0, 0, 0, 0, 0, 0x0000FF};
	info->axis[3] = (t_data){WIDTH / 2, 0, 0, 0, 0, 0, 0, 0xFFFFFF};
	info->axis[4] = (t_data){0, HEIGHT / 2, 0, 0, 0, 0, 0, 0xFFFFFF};
	info->axis[5] = (t_data){0, 0, 1000, 0, 0, 0, 0, 0xFFFFFF};
	fdf_int_to_trgb(&info->axis[0]);
	fdf_int_to_trgb(&info->axis[1]);
	fdf_int_to_trgb(&info->axis[2]);
	fdf_int_to_trgb(&info->axis[3]);
	fdf_int_to_trgb(&info->axis[4]);
	fdf_int_to_trgb(&info->axis[5]);
}

void	fdf_make_rotate_axis(t_info *info)
{
	int	idx;

	idx = 0;
	while (idx < 6)
	{
		ft_memcpy(&info->rotate_axis[idx], &info->axis[idx], sizeof(t_data));
		idx++;
	}
}

void	fdf_axis_projection(t_info *info)
{
	fdf_cal_projection(info, &info->rotate_axis[0]);
	fdf_cal_projection(info, &info->rotate_axis[1]);
	fdf_cal_projection(info, &info->rotate_axis[2]);
	fdf_cal_projection(info, &info->rotate_axis[3]);
	fdf_cal_projection(info, &info->rotate_axis[4]);
	fdf_cal_projection(info, &info->rotate_axis[5]);
	fdf_cal_image_data(info, &info->rotate_axis[0], &info->image_axis[0]);
	fdf_cal_image_data(info, &info->rotate_axis[1], &info->image_axis[1]);
	fdf_cal_image_data(info, &info->rotate_axis[2], &info->image_axis[2]);
	fdf_cal_image_data(info, &info->rotate_axis[3], &info->image_axis[3]);
	fdf_cal_image_data(info, &info->rotate_axis[4], &info->image_axis[4]);
	fdf_cal_image_data(info, &info->rotate_axis[5], &info->image_axis[5]);
}

void	fdf_draw_image_axis(t_info *info)
{
	fdf_draw_line(&info->image, info->image_axis[0], info->image_axis[3]);
	fdf_draw_line(&info->image, info->image_axis[1], info->image_axis[4]);
	fdf_draw_line(&info->image, info->image_axis[2], info->image_axis[5]);
}
