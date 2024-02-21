/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:48:18 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/22 08:19:46 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_duplicate_type(t_info *info)
{
	t_list		*lst;
	int			flag;

	lst = info->entites;
	flag = 0;
	while (lst)
	{
		if (((t_entity *)lst->content)->type == AMBIENT)
			flag += (1 << (AMBIENT * 2));
		else if (((t_entity *)lst->content)->type == CAMERA)
			flag += (1 << (CAMERA * 2));
		else if (((t_entity *)lst->content)->type == LIGHT)
			flag += (1 << (LIGHT * 2));
		if ((flag & (1 << (AMBIENT * 2 + 1))))
			error_manager("too many ambient entity");
		if ((flag & (1 << (CAMERA * 2 + 1))))
			error_manager("too many camera entity");
		if ((flag & (1 << (LIGHT * 2 + 1))))
			error_manager("too many light entity");
		lst = lst->next;
	}
}

void	check_range(t_info *info)
{
	t_list		*lst;

	lst = info->entites;
	while (lst)
	{
		if (((t_entity *)lst->content)->type == AMBIENT)
			check_ambient(lst);
		else if (((t_entity *)lst->content)->type == CAMERA)
			check_camera(lst);
		else if (((t_entity *)lst->content)->type == LIGHT)
			check_light(lst);
		else if (((t_entity *)lst->content)->type == SPHERE)
			check_sphere(lst);
		else if (((t_entity *)lst->content)->type == PLANE)
			check_plane(lst);
		else if (((t_entity *)lst->content)->type == CYLINDER)
			check_cylinder(lst);
		lst = lst->next;
	}
}

int	check_extension(char *filename)
{
	char	*extension_ptr;

	extension_ptr = ft_strnstr(filename, ".rt", ft_strlen(filename));
	if (extension_ptr == filename)
		return (FALSE);
	if (!extension_ptr)
		return (FALSE);
	if (extension_ptr[3] != '\0')
		return (FALSE);
	return (TRUE);
}

void	parsing(int fd, t_info *info)
{
	char	*line;
	int		res;

	res = TRUE;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		oneline_parsing(line, info);
		free(line);
	}
	free(line);
}

int	parse(int argc, char *filename, t_info *info)
{
	int	fd;

	info->entites = NULL;
	if (argc == 1)
		error_manager("no .rt file");
	if (argc != 2)
		error_manager("too many files");
	if (!check_extension(filename))
		error_manager("non valid extension");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_manager(strerror(errno));
	parsing(fd, info);
	close(fd);
	check_range(info);
	check_duplicate_type(info);
	return (TRUE);
}
