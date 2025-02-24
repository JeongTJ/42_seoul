/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_shape_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/16 20:14:58 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/fdf_bonus.h"

void	fdf_shape(t_info *info)
{
	double	beta;
	double	gamma;
	int		row;
	int		col;

	row = 0;
	while (row < info->row_size)
	{
		col = 0;
		while (col < info->col_size)
		{
			info->rotate_data[row][col].x = 0;
			info->rotate_data[row][col].y = 0;
			info->rotate_data[row][col].z += info->col_size / 2;
			beta = ((360.0 / info->col_size) * (info->col_size / 2 - col)) \
															/ 180.0 * M_PI;
			gamma = ((360.0 / info->row_size) * (info->row_size / 2 - row)) \
															/ 180.0 * M_PI;
			fdf_rotate_beta(&info->rotate_data[row][col], beta);
			fdf_rotate_gamma(&info->rotate_data[row][col], gamma);
			col++;
		}
		row++;
	}
}
