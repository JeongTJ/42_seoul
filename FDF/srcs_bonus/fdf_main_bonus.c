/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/12 18:52:44 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

/* delete */
void	check_leak(void)
{
	system("leaks fdf");
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc == 1)
		exit(EXIT_FAILURE);
	fdf_init(&info, argv[1]);
	mlx_hook(info.vars.win, 2, 0, key_hook, &info);
	mlx_hook(info.vars.win, 4, 0, mouse_hook, &info);
	mlx_hook(info.vars.win, 5, 0, mouse_hook, &info);
	mlx_hook(info.vars.win, ON_DESTROY, 0, fdf_close, &info);
	mlx_hook(info.vars.win, 6, 0, fdf_mouse_tracking, &info);
	mlx_loop_hook(info.vars.mlx, auto_rotate, &info);
	mlx_loop(info.vars.mlx);
	return (0);
}
