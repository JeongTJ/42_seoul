/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_box.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/12 18:40:12 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	fdf_init_box(t_info *info)
{
	info->box = ft_calloc(8, sizeof(t_data));
	if (info->box == NULL)
		exit(EXIT_FAILURE);
	info->rotate_box = ft_calloc(8, sizeof(t_data));
	if (info->rotate_box == NULL)
		exit(EXIT_FAILURE);
	info->image_box = ft_calloc(8, sizeof(t_data));
	if (info->image_box == NULL)
		exit(EXIT_FAILURE);
	info->box[0] = (t_data){0, 0, 0, 0, 0, 0, 0, 0xFFFFFF};
	info->box[1] = (t_data){0, 10, 0, 0, 0, 0, 0, 0xFF0000};
	info->box[2] = (t_data){10, 0, 0, 0, 0, 0, 0, 0x00FF00};
	info->box[3] = (t_data){10, 10, 0, 0, 0, 0, 0, 0x0000FF};
	info->box[4] = (t_data){0, 0, 10, 0, 0, 0, 0, 0xFFFFFF};
	info->box[5] = (t_data){0, 10, 10, 0, 0, 0, 0, 0x00FFFF};
	info->box[6] = (t_data){10, 0, 10, 0, 0, 0, 0, 0xFF00FF};
	info->box[7] = (t_data){10, 10, 10, 0, 0, 0, 0, 0xFFFF00};
	fdf_int_to_trgb(&info->box[0]);
	fdf_int_to_trgb(&info->box[1]);
	fdf_int_to_trgb(&info->box[2]);
	fdf_int_to_trgb(&info->box[3]);
	fdf_int_to_trgb(&info->box[4]);
	fdf_int_to_trgb(&info->box[5]);
	fdf_int_to_trgb(&info->box[6]);
	fdf_int_to_trgb(&info->box[7]);
}

void	fdf_make_rotate_box(t_info *info)
{
	int	idx;

	idx = 0;
	while (idx < 8)
	{
		ft_memcpy(&info->rotate_box[idx], &info->box[idx], sizeof(t_data));
		idx++;
	}
}

void	fdf_box_projection(t_info *info)
{
	fdf_cal_projection(info, &info->rotate_box[0]);
	fdf_cal_projection(info, &info->rotate_box[1]);
	fdf_cal_projection(info, &info->rotate_box[2]);
	fdf_cal_projection(info, &info->rotate_box[3]);
	fdf_cal_projection(info, &info->rotate_box[4]);
	fdf_cal_projection(info, &info->rotate_box[5]);
	fdf_cal_projection(info, &info->rotate_box[6]);
	fdf_cal_projection(info, &info->rotate_box[7]);
	fdf_cal_image_data(info, &info->rotate_box[0], &info->image_box[0]);
	fdf_cal_image_data(info, &info->rotate_box[1], &info->image_box[1]);
	fdf_cal_image_data(info, &info->rotate_box[2], &info->image_box[2]);
	fdf_cal_image_data(info, &info->rotate_box[3], &info->image_box[3]);
	fdf_cal_image_data(info, &info->rotate_box[4], &info->image_box[4]);
	fdf_cal_image_data(info, &info->rotate_box[5], &info->image_box[5]);
	fdf_cal_image_data(info, &info->rotate_box[6], &info->image_box[6]);
	fdf_cal_image_data(info, &info->rotate_box[7], &info->image_box[7]);
}

void	fdf_draw_image_box(t_info *info)
{
	fdf_draw_line(&info->image, info->image_box[0], info->image_box[1]);
	fdf_draw_line(&info->image, info->image_box[0], info->image_box[2]);
	fdf_draw_line(&info->image, info->image_box[3], info->image_box[1]);
	fdf_draw_line(&info->image, info->image_box[3], info->image_box[2]);
	fdf_draw_line(&info->image, info->image_box[4], info->image_box[5]);
	fdf_draw_line(&info->image, info->image_box[4], info->image_box[6]);
	fdf_draw_line(&info->image, info->image_box[7], info->image_box[5]);
	fdf_draw_line(&info->image, info->image_box[7], info->image_box[6]);
	fdf_draw_line(&info->image, info->image_box[0], info->image_box[4]);
	fdf_draw_line(&info->image, info->image_box[1], info->image_box[5]);
	fdf_draw_line(&info->image, info->image_box[2], info->image_box[6]);
	fdf_draw_line(&info->image, info->image_box[3], info->image_box[7]);
}
