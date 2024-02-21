/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:48:18 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/22 05:39:44 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	destroy_exit(t_info *info)
{
	mlx_destroy_window(info->var.mlx, info->var.win);
	exit(0);
	return (0);
}

int	key_hook_f(int key, t_info *info)
{
	if (key == KEY_ESC)
		return (destroy_exit(info));
	return (0);
}
