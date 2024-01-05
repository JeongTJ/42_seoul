/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/05 16:01:35 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	fdf_int_to_trgb(t_data *data)
{
	data->t = (data->color & (0xFF << 24)) >> 24;
	data->r = (data->color & (0xFF << 16)) >> 16;
	data->g = (data->color & (0xFF << 8)) >> 8;
	data->b = (data->color & (0xFF << 0)) >> 0;
}

void	fdf_trgv_to_int(t_data *data)
{
	int			trgb;
	const int	t = round(data->t);
	const int	r = round(data->r);
	const int	g = round(data->g);
	const int	b = round(data->b);

	trgb = 0;
	trgb = ((t & 0xFF) << 24) | ((r & 0xFF) << 16) | \
			((g & 0xFF) << 8) | ((b & 0xFF) << 0);
	data->color = trgb;
}

int	fdf_is_drawable(t_data data)
{
	return (0 <= data.x && data.x < WIDTH && \
			0 <= data.y && data.y < HEIGHT);
}

