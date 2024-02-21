/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:48:18 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/22 08:23:56 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	print_info(t_info *info)
// {
// 	t_list		*lst;
// 	t_ambient	*print_a;
// 	t_camera	*print_c;
// 	t_light		*print_l;
// 	t_sphere	*print_sp;
// 	t_plane		*print_pl;
// 	t_cylinder	*print_cy;

// 	lst = info->entites;
// 	while (lst)
// 	{
// 		if (((t_entity *)lst->content)->type == AMBIENT)
// 		{
// 			print_a = ((t_entity *)lst->content)->content;
// 			printf("ambient : ratio[%lf] color[r : %lf, g : %lf, b: %lf]\n", \
// 			print_a->color.r, print_a->color.g, print_a->color.b, print_a->lighting_ratio);
// 		}
// 		else if (((t_entity *)lst->content)->type == CAMERA)
// 		{
// 			print_c = ((t_entity *)lst->content)->content;
// 			printf("camera : coor[x : %lf, y : %lf, x : %lf] vec[x : %lf, y : %lf, x : %lf] fov[%lf]\n", \
// 			print_c->coor.x, print_c->coor.y, print_c->coor.z, \
// 			print_c->vec.x, print_c->vec.y, print_c->vec.z,
// 			print_c->fov);
// 		}
// 		else if (((t_entity *)lst->content)->type == LIGHT)
// 		{
// 			print_l = ((t_entity *)lst->content)->content;
// 			printf("light : coor[x : %lf, y : %lf, x : %lf] ratio[%lf] rgb[r : %lf, g : %lf, b : %lf]\n", \
// 			print_l->coor.x, print_l->coor.y, print_l->coor.z, \
// 			print_l->brightness_ratio, \
// 			print_l->color.r, print_l->color.g, print_l->color.b);
// 		}
// 		else if (((t_entity *)lst->content)->type == SPHERE)
// 		{
// 			print_sp = ((t_entity *)lst->content)->content;
// 			printf("sphere : coor[x : %lf, y : %lf, x : %lf] radius[%lf] rgb[r : %lf, g : %lf, b : %lf]\n", \
// 			print_sp->coor.x, print_sp->coor.y, print_sp->coor.z, \
// 			print_sp->radius, \
// 			print_sp->color.r, print_sp->color.g, print_sp->color.b);

// 		}
// 		else if (((t_entity *)lst->content)->type == PLANE)
// 		{
// 			print_pl = ((t_entity *)lst->content)->content;
// 			printf("plane : coor[x : %lf, y : %lf, x : %lf] vec[x : %lf, y : %lf, x : %lf] rgb[r : %lf, g : %lf, b : %lf]\n", \
// 			print_pl->coor.x, print_pl->coor.y, print_pl->coor.z, \
// 			print_pl->vec.x, print_pl->vec.y, print_pl->vec.z, \
// 			print_pl->color.r, print_pl->color.g, print_pl->color.b);
// 		}
// 		else if (((t_entity *)lst->content)->type == CYLINDER)
// 		{
// 			print_cy = ((t_entity *)lst->content)->content;
// 			printf("cylinder : coor[x : %lf, y : %lf, x : %lf] vec[x : %lf, y : %lf, x : %lf] radius[%lf] height[%lf] rgb[r : %lf, g : %lf, b : %lf]\n", \
// 			print_cy->coor.x, print_cy->coor.y, print_cy->coor.z, \
// 			print_cy->vec.x, print_cy->vec.y, print_cy->vec.z, \
// 			print_cy->radius, \
// 			print_cy->height, \
// 			print_cy->color.r, print_cy->color.g, print_cy->color.b);
// 		}
// 		lst = lst->next;
// 	}
// }

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
}

int	main(int argc, char *argv[])
{
	t_info	info;

	parse(argc, argv[1], &info);
	print_info(&info);
	info_init(&info);
	mlx_hook(info.var.win, KEYPRESS, 0, key_hook_f, &info);
	mlx_hook(info.var.win, DESTROYNOTIFY, 0, destroy_exit, &info);
	mlx_loop(info.var.mlx);
	return (0);
}
