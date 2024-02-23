/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entity1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:48:18 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/23 17:13:57 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_list	*make_ambient(char *line, int idx)
{
	t_list		*res;
	t_entity	*content;

	content = ft_calloc(1, sizeof(t_entity));
	if (!content)
		error_manager("malloc error");
	content->type = AMBIENT;
	ft_atod(line, &idx, &content->lighting_ratio, "non valid ambient");
	ft_atod(line, &idx, &content->color.r, "non valid ambient");
	ft_atod(line, &idx, &content->color.g, "non valid ambient");
	ft_atod(line, &idx, &content->color.b, "non valid ambient");
	if (line[idx] != '\n')
		error_manager("non valid ambient");
	res = ft_lstnew(content);
	if (!res)
		error_manager("malloc error");
	return (res);
}

t_list	*make_camera(char *line, int idx)
{
	t_list		*res;
	t_entity	*content;

	printf("check\n");
	content = ft_calloc(1, sizeof(t_entity));
	if (!content)
		error_manager("malloc error");
	content->type = CAMERA;
	ft_atod(line, &idx, &content->coor.x, "non valid camera");
	ft_atod(line, &idx, &content->coor.y, "non valid camera");
	ft_atod(line, &idx, &content->coor.z, "non valid camera");
	ft_atod(line, &idx, &content->vec.x, "non valid camera");
	ft_atod(line, &idx, &content->vec.y, "non valid camera");
	ft_atod(line, &idx, &content->vec.z, "non valid camera");
	ft_atod(line, &idx, &content->fov, "non valid camera");
	if (line[idx] != '\n')
		error_manager("non valid camera");
	res = ft_lstnew(content);
	if (!res)
		error_manager("malloc error");
	return (res);
}

t_list	*make_light(char *line, int idx)
{
	t_list		*res;
	t_entity	*content;

	content = ft_calloc(1, sizeof(t_entity));
	if (!content)
		error_manager("malloc error");
	content->type = LIGHT;
	ft_atod(line, &idx, &content->coor.x, "non valid light");
	ft_atod(line, &idx, &content->coor.y, "non valid light");
	ft_atod(line, &idx, &content->coor.z, "non valid light");
	ft_atod(line, &idx, &content->brightness_ratio, "non valid light");
	ft_atod(line, &idx, &content->color.r, "non valid light");
	ft_atod(line, &idx, &content->color.g, "non valid light");
	ft_atod(line, &idx, &content->color.b, "non valid light");
	if (line[idx] != '\n')
		error_manager("non valid light");
	res = ft_lstnew(content);
	if (!res)
		error_manager("malloc error");
	return (res);
}
