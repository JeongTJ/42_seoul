/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/16 20:07:10 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int	main(int argc, char **argv)
{
	t_info	info;

	ft_memset(&info, 0, sizeof(t_info));
	if (argc != 2)
		exit(EXIT_FAILURE);
	if (ft_strncmp(&(argv[1][ft_strlen(argv[1]) - 4]), ".fdf", 4) != 0)
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
