/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/15 13:07:54 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/fdf_bonus.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc == 1)
		exit(EXIT_FAILURE);
	fdf_init(&info, argv[1]);
	mlx_hook(info.vars.win, KEYPRESS, 0, key_hook, &info);
	mlx_hook(info.vars.win, BUTTONPRESS, 0, mouse_hook, &info);
	mlx_hook(info.vars.win, BUTTONRELEASE, 0, mouse_hook, &info);
	mlx_hook(info.vars.win, ON_DESTROY, 0, fdf_close, &info);
	mlx_hook(info.vars.win, MOTIONNOTIFY, 0, fdf_mouse_tracking, &info);
	mlx_loop_hook(info.vars.mlx, auto_rotate, &info);
	mlx_loop(info.vars.mlx);
	return (0);
}
