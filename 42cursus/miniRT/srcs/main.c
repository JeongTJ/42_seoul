/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:48:18 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/23 15:15:30 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_info(t_info *info)
{
	t_list		*lst;
	t_entity	*print_a;
	t_entity	*print_c;
	t_entity	*print_l;
	t_entity	*print_sp;
	t_entity	*print_pl;
	t_entity	*print_cy;

	lst = info->entites;
	while (lst)
	{
		if (((t_entity *)lst->content)->type == AMBIENT)
		{
			print_a = (t_entity *)lst->content;
			printf("ambient :\n\tratio[%lf]\n\tcolor[r : %lf, g : %lf, b: %lf]\n", \
			print_a->color.r, print_a->color.g, print_a->color.b, print_a->lighting_ratio);
		}
		else if (((t_entity *)lst->content)->type == CAMERA)
		{
			print_c = (t_entity *)lst->content;
			printf("camera :\n\tcoor[x : %lf, y : %lf, z : %lf]\n\tvec[x : %lf, y : %lf, z : %lf]\n\tfov[%lf]\n", \
			print_c->coor.x, print_c->coor.y, print_c->coor.z, \
			print_c->vec.x, print_c->vec.y, print_c->vec.z,
			print_c->fov);
		}
		else if (((t_entity *)lst->content)->type == LIGHT)
		{
			print_l = (t_entity *)lst->content;
			printf("light :\n\tcoor[x : %lf, y : %lf, z : %lf]\n\tratio[%lf]\n\trgb[r : %lf, g : %lf, b : %lf]\n", \
			print_l->coor.x, print_l->coor.y, print_l->coor.z, \
			print_l->brightness_ratio, \
			print_l->color.r, print_l->color.g, print_l->color.b);
		}
		else if (((t_entity *)lst->content)->type == SPHERE)
		{
			print_sp = (t_entity *)lst->content;
			printf("sphere :\n\tcoor[x : %lf, y : %lf, z : %lf]\n\tradius[%lf]\n\trgb[r : %lf, g : %lf, b : %lf]\n", \
			print_sp->coor.x, print_sp->coor.y, print_sp->coor.z, \
			print_sp->radius, \
			print_sp->color.r, print_sp->color.g, print_sp->color.b);

		}
		else if (((t_entity *)lst->content)->type == PLANE)
		{
			print_pl = (t_entity *)lst->content;
			printf("plane :\n\tcoor[x : %lf, y : %lf, z : %lf]\n\tvec[x : %lf, y : %lf, z : %lf]\n\trgb[r : %lf, g : %lf, b : %lf]\n", \
			print_pl->coor.x, print_pl->coor.y, print_pl->coor.z, \
			print_pl->vec.x, print_pl->vec.y, print_pl->vec.z, \
			print_pl->color.r, print_pl->color.g, print_pl->color.b);
		}
		else if (((t_entity *)lst->content)->type == CYLINDER)
		{
			print_cy = (t_entity *)lst->content;
			printf("cylinder :\n\tcoor[x : %lf, y : %lf, z : %lf]\n\tvec[x : %lf, y : %lf, z : %lf]\n\tradius[%lf]\n\theight[%lf]\n\trgb[r : %lf, g : %lf, b : %lf]\n", \
			print_cy->coor.x, print_cy->coor.y, print_cy->coor.z, \
			print_cy->vec.x, print_cy->vec.y, print_cy->vec.z, \
			print_cy->radius, \
			print_cy->height, \
			print_cy->color.r, print_cy->color.g, print_cy->color.b);
		}
		lst = lst->next;
	}
}

void	info_init(t_info *info)
{
	info->var.mlx = mlx_init();
	info->var.win = mlx_new_window(info->var.mlx, \
					1000, 1000, "Hellow World!");
	info->image.img = mlx_new_image(info->var.mlx, \
					1000, 1000);
	info->image.addr = mlx_get_data_addr(info->image.img, \
				&info->image.bits_per_pixel, \
				&info->image.line_length, &info->image.endian);
	info->ambient = get_entity(info->entites, AMBIENT);
	info->camera = get_entity(info->entites, CAMERA);
	info->light = get_entity(info->entites, LIGHT);
}

void	matrix_init(t_info *info)
{
	int	idx;

	idx = 0;
	info->m_a = ft_calloc(4, sizeof(double *));
	if (!info->m_a)
		error_manager("malloc error");
	info->m_b = ft_calloc(4, sizeof(double *));
	if (!info->m_b)
		error_manager("malloc error");
	info->m_c = ft_calloc(4, sizeof(double *));
	if (!info->m_c)
		error_manager("malloc error");
	while (idx < 4)
	{
		info->m_a[idx] = ft_calloc(4, sizeof(double));
		if (!info->m_a[idx])
			error_manager("malloc error");
		info->m_b[idx] = ft_calloc(4, sizeof(double));
		if (!info->m_b[idx])
			error_manager("malloc error");
		info->m_c[idx] = ft_calloc(4, sizeof(double));
		if (!info->m_c[idx])
			error_manager("malloc error");
		idx++;
	}
}

int	main(int argc, char *argv[])
{
	t_info	info;

	parse(argc, argv[1], &info);
	matrix_init(&info);
	print_info(&info);
	info_init(&info);
	mlx_hook(info.var.win, KEYPRESS, 0, key_hook_f, &info);
	mlx_hook(info.var.win, DESTROYNOTIFY, 0, destroy_exit, &info);
	mlx_loop(info.var.mlx);
	return (0);
}
