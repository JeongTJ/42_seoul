/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:48:18 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/23 14:52:13 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	t_list	*node;

	node = NULL;
	if (line[0] == 'A')
		node = make_ambient(line, 0);
	else if (line[0] == 'C')
		node = make_camera(line, 0);
	else if (line[0] == 'L')
		node = make_light(line, 0);
	else if (line[0] == 's' && line[1] == 'p')
		node = make_sphere(line, 0);
	else if (line[0] == 'p' && line[1] == 'l')
		node = make_plane(line, 0);
	else if (line[0] == 'c' && line[1] == 'y')
		node = make_cylinder(line, 0);
	ft_lstadd_back(&info->entites, node);
}
