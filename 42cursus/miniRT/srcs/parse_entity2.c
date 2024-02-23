/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entity2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:48:18 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/23 14:51:07 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_list	*make_sphere(char *line, int idx)
{
	t_list		*res;
	t_entity	*content;

	content = ft_calloc(1, sizeof(t_entity));
	if (!content)
		error_manager("malloc error");
	content->type = SPHERE;
	ft_atod(line, &idx, &content->coor.x, "non valid sphere");
	ft_atod(line, &idx, &content->coor.y, "non valid sphere");
	ft_atod(line, &idx, &content->coor.z, "non valid sphere");
	ft_atod(line, &idx, &content->radius, "non valid sphere");
	ft_atod(line, &idx, &content->color.r, "non valid sphere");
	ft_atod(line, &idx, &content->color.g, "non valid sphere");
	ft_atod(line, &idx, &content->color.b, "non valid sphere");
	if (line[idx] != '\n')
		error_manager("non valid shpere");
	res = ft_lstnew(content);
	if (!res)
		error_manager("malloc error");
	return (res);
}

t_list	*make_plane(char *line, int idx)
{
	t_list		*res;
	t_entity	*content;

	content = ft_calloc(1, sizeof(t_entity));
	if (!content)
		error_manager("malloc error");
	content->type = PLANE;
	ft_atod(line, &idx, &content->coor.x, "non valid plane");
	ft_atod(line, &idx, &content->coor.y, "non valid plane");
	ft_atod(line, &idx, &content->coor.z, "non valid plane");
	ft_atod(line, &idx, &content->vec.x, "non valid plane");
	ft_atod(line, &idx, &content->vec.y, "non valid plane");
	ft_atod(line, &idx, &content->vec.z, "non valid plane");
	ft_atod(line, &idx, &content->color.r, "non valid plane");
	ft_atod(line, &idx, &content->color.g, "non valid plane");
	ft_atod(line, &idx, &content->color.b, "non valid plane");
	if (line[idx] != '\n')
		error_manager("non valid plane");
	res = ft_lstnew(content);
	if (!res)
		error_manager("malloc error");
	return (res);
}

t_list	*make_cylinder(char *line, int idx)
{
	t_list		*res;
	t_entity	*content;

	content = ft_calloc(1, sizeof(t_entity));
	if (!content)
		error_manager("malloc error");
	content->type = CYLINDER;
	ft_atod(line, &idx, &content->coor.x, "non valid cylinder");
	ft_atod(line, &idx, &content->coor.y, "non valid cylinder");
	ft_atod(line, &idx, &content->coor.z, "non valid cylinder");
	ft_atod(line, &idx, &content->vec.x, "non valid cylinder");
	ft_atod(line, &idx, &content->vec.y, "non valid cylinder");
	ft_atod(line, &idx, &content->vec.z, "non valid cylinder");
	ft_atod(line, &idx, &content->radius, "non valid cylinder");
	ft_atod(line, &idx, &content->height, "non valid cylinder");
	ft_atod(line, &idx, &content->color.r, "non valid cylinder");
	ft_atod(line, &idx, &content->color.g, "non valid cylinder");
	ft_atod(line, &idx, &content->color.b, "non valid cylinder");
	if (line[idx] != '\n')
		error_manager("non valid cylinder");
	res = ft_lstnew(content);
	if (!res)
		error_manager("malloc error");
	return (res);
}
