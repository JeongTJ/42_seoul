/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_valid_check2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:48:18 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/22 08:24:32 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_sphere(t_list *node)
{
	t_sphere	*sphere;

	sphere = ((t_entity *)node->content)->content;
	if (!(0 <= sphere->color.r && sphere->color.r <= 255))
		error_manager("out of range in sphere R");
	if (!(0 <= sphere->color.g && sphere->color.g <= 255))
		error_manager("out of range in sphere G");
	if (!(0 <= sphere->color.b && sphere->color.b <= 255))
		error_manager("out of range in sphere B");
}

void	check_plane(t_list *node)
{
	t_plane		*plane;

	plane = ((t_entity *)node->content)->content;
	if (!(-1 <= plane->vec.x && plane->vec.x <= 1))
		error_manager("out of range in plane vector x");
	if (!(-1 <= plane->vec.y && plane->vec.y <= 1))
		error_manager("out of range in plane vector y");
	if (!(-1 <= plane->vec.z && plane->vec.z <= 1))
		error_manager("out of range in plane vector z");
	if (!(0 <= plane->color.r && plane->color.r <= 255))
		error_manager("out of range in plane R");
	if (!(0 <= plane->color.g && plane->color.g <= 255))
		error_manager("out of range in plane G");
	if (!(0 <= plane->color.b && plane->color.b <= 255))
		error_manager("out of range in plane B");
}

void	check_cylinder(t_list *node)
{
	t_cylinder	*cylinder;

	cylinder = ((t_entity *)node->content)->content;
	if (!(-1 <= cylinder->vec.x && cylinder->vec.x <= 1))
		error_manager("out of range in cylinder vector x");
	if (!(-1 <= cylinder->vec.y && cylinder->vec.y <= 1))
		error_manager("out of range in cylinder vector y");
	if (!(-1 <= cylinder->vec.z && cylinder->vec.z <= 1))
		error_manager("out of range in cylinder vector z");
	if (!(0 <= cylinder->color.r && cylinder->color.r <= 255))
		error_manager("out of range in cylinder R");
	if (!(0 <= cylinder->color.g && cylinder->color.g <= 255))
		error_manager("out of range in cylinder G");
	if (!(0 <= cylinder->color.b && cylinder->color.b <= 255))
		error_manager("out of range in cylinder B");
}
