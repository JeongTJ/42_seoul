/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/16 20:14:43 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/fdf_bonus.h"

static void	fdf_redraw(t_info *info)
{
	my_mlx_clear_image(&info->image);
	fdf_box_projection(info);
	fdf_axis_projection(info);
	fdf_projection(info);
	fdf_make_image_data(info);
	if ((info->flag & (1 << KEY_1)) == 0)
		fdf_draw_image_data(info);
	if ((info->flag & (1 << KEY_2)) != 0)
		fdf_draw_image_axis(info);
	if ((info->flag & (1 << KEY_3)) != 0)
		fdf_draw_image_box(info);
	mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
							info->image.img, 0, 0);
}

int	key_hook(int keycode, t_info *info)
{
	if (keycode == KEY_SUM || keycode == KEY_SUB || \
		keycode == KEY_W || keycode == KEY_A || \
		keycode == KEY_S || keycode == KEY_D)
		fdf_key_move(keycode, info, 1);
	else if (keycode == 15)
		fdf_move_init(info);
	else if (keycode == KEY_Z || keycode == KEY_X || keycode == KEY_C)
		fdf_rotate(info, keycode, 5);
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window(info->vars.mlx, info->vars.win);
		exit(0);
	}
	else if (keycode == KEY_1 || keycode == KEY_2 || \
			keycode == KEY_3 || keycode == KEY_Q)
		info->flag = info->flag ^ (1 << keycode);
	else if (keycode == KEY_0)
	{
		info->flag = info->flag ^ (1 << keycode);
		fdf_move_init(info);
	}
	fdf_redraw(info);
	return (0);
}

int	mouse_hook(int mouse, int x, int y, t_info *info)
{
	x = 0;
	y = 0;
	info->flag = info->flag ^ (1 << mouse);
	if (mouse == WHEEL_UP)
		fdf_key_move(KEY_SUM, info, 0);
	else if (mouse == WHEEL_DOWN)
		fdf_key_move(KEY_SUB, info, 0);
	fdf_redraw(info);
	return (0);
}

int	auto_rotate(t_info *info)
{
	if ((info->flag & (1 << KEY_Q)) != 0)
		fdf_rotate(info, KEY_X, 0.1);
	fdf_redraw(info);
	return (0);
}

int	fdf_mouse_tracking(int x, int y, t_info *info)
{
	if ((info->flag & (1 << MOUSE_RIGHT)) != 0)
	{
		info->angle.beta = (x - info->curr_coor.x);
		info->angle.alpha = -(y - info->curr_coor.y);
	}
	else if ((info->flag & (1 << MOUSE_LEFT)) != 0)
	{
		info->dx = WIDTH / 2 + ((double)(x) - WIDTH / 2) / \
					(pow(2, info->zoom_level));
		info->dy = HEIGHT / 2 + ((double)(y) - HEIGHT / 2) / \
					(pow(2, info->zoom_level));
	}
	fdf_redraw(info);
	info->curr_coor.x = x;
	info->curr_coor.y = y;
	return (0);
}
