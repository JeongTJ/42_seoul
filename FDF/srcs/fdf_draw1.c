/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/05 17:40:54 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

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

void	fdf_draw_reactangle(t_image *image, t_data s_data, \
							int width, int height)
{
	fdf_draw_line(image, s_data, \
				(t_data){s_data.x + width, s_data.y, \
				0, 0, 0, 0, 0, s_data.color});
	fdf_draw_line(image, s_data, \
				(t_data){s_data.x, s_data.y + height, \
				0, 0, 0, 0, 0, s_data.color});
	fdf_draw_line(image, (t_data){s_data.x + width, s_data.y, \
				0, 0, 0, 0, 0, s_data.color}, \
			(t_data){s_data.x + width, s_data.y + height, \
				0, 0, 0, 0, 0, s_data.color});
	fdf_draw_line(image, \
			(t_data){s_data.x, s_data.y + height, \
				0, 0, 0, 0, 0, s_data.color}, \
			(t_data){s_data.x + width, s_data.y + height, \
				0, 0, 0, 0, 0, s_data.color});
}

void	fdf_draw_triangle(t_image *image, t_data s_data, \
							t_data m_data, t_data e_data)
{
	fdf_draw_line(image, s_data, m_data);
	fdf_draw_line(image, m_data, e_data);
	fdf_draw_line(image, e_data, s_data);
}

void	fdf_draw_circle(t_image *image, t_data center_data, int size)
{
	double			x;
	double			y;
	double			rad;
	const double	drad = 1 / (double)size;

	rad = 0;
	while (rad < 2 * M_PI)
	{
		x = center_data.x + size * cos(rad);
		y = center_data.y + size * sin(rad);
		if (0 <= (int)x && (int)x <= 1000 && 0 <= (int)y && (int)y <= 1000)
			my_mlx_pixel_put(image, (int)x, (int)y, center_data.color);
		rad += drad;
	}
}
