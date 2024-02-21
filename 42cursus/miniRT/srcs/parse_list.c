/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:48:18 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/22 07:55:06 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_entity	*ft_entitynew(void *content, t_entity_type type)
{
	t_entity	*res;

	res = ft_calloc(1, sizeof(t_entity));
	if (!res)
		return (NULL);
	res->type = type;
	res->content = content;
	return (res);
}

int	get_decimal(char *str, int idx)
{
	int	cnt;

	cnt = 0;
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		cnt++;
		idx++;
	}
	cnt--;
	return (cnt);
}

void	ft_atod(char *str, int *idx, double *a, char *error_massage)
{
	double	res;
	int		sign;
	int		decimal;

	res = 0;
	sign = 1;
	while (!('0' <= str[*idx] && str[*idx] <= '9') && str[*idx] != '\0')
		if (str[(*idx)++] == '-')
			sign *= -1;
	if (str[(*idx)] == '\0')
		error_manager(error_massage);
	decimal = get_decimal(str, *idx);
	while (('0' <= str[*idx] && str[*idx] <= '9') || str[*idx] == '.')
	{
		if (str[*idx] == '.')
			(*idx)++;
		res += ((double)(str[(*idx)] - '0')) * ((double)powf(10.0, decimal));
		decimal--;
		(*idx)++;
	}
	*a = res * sign;
}

void	oneline_parsing(char *line, t_info *info)
{
	t_list		*node;
	t_entity	*content;

	content = NULL;
	if (line[0] == 'A')
		content = make_ambient(line);
	else if (line[0] == 'C')
		content = make_camera(line);
	else if (line[0] == 'L')
		content = make_light(line);
	else if (line[0] == 's' && line[1] == 'p')
		content = make_sphere(line);
	else if (line[0] == 'p' && line[1] == 'l')
		content = make_plane(line);
	else if (line[0] == 'c' && line[1] == 'y')
		content = make_cylinder(line);
	node = ft_lstnew(content);
	if (!node)
		error_manager("malloc error");
	ft_lstadd_back(&info->entites, node);
}
