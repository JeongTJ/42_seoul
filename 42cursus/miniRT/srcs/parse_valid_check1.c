/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_valid_check1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:48:18 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/22 07:58:24 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_ambient(t_list *node)
{
	t_ambient	*ambient;

	ambient = ((t_entity *)node->content)->content;
	if (!(0 <= ambient->color.r && ambient->color.r <= 255))
		error_manager("out of range in ambient R");
	if (!(0 <= ambient->color.g && ambient->color.g <= 255))
		error_manager("out of range in ambient G");
	if (!(0 <= ambient->color.b && ambient->color.b <= 255))
		error_manager("out of range in ambient B");
	if (!(0 <= ambient->lighting_ratio && ambient->lighting_ratio <= 1))
		error_manager("out of range in ambient lighting_ratio");
}

void	check_camera(t_list *node)
{
	t_camera	*camera;

	camera = ((t_entity *)node->content)->content;
	if (!(-1 <= camera->vec.x && camera->vec.x <= 1))
		error_manager("out of range in camera vector x");
	if (!(-1 <= camera->vec.y && camera->vec.y <= 1))
		error_manager("out of range in camera vector y");
	if (!(-1 <= camera->vec.z && camera->vec.z <= 1))
		error_manager("out of range in camera vector z");
	if (!(0 <= camera->fov && camera->fov <= 180))
		error_manager("out of range in camera fov");
}

void	check_light(t_list *node)
{
	t_light		*light;

	light = ((t_entity *)node->content)->content;
	if (!(0 <= light->brightness_ratio && light->brightness_ratio <= 1))
		error_manager("out of range in light brightness_ratio");
	if (!(0 <= light->color.r && light->color.r <= 255))
		error_manager("out of range in light R");
	if (!(0 <= light->color.g && light->color.g <= 255))
		error_manager("out of range in light G");
	if (!(0 <= light->color.b && light->color.b <= 255))
		error_manager("out of range in light B");
}
