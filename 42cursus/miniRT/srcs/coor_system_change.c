/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coor_system_change.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:48:18 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/22 10:41:09 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	matrix_mul(t_info *info)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				info->m_c[i][j] += info->m_a[i][k] * info->m_b[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
}

void	put_entity_vec_to_m_a(t_info *info, t_list *entity, t_entity_type type)
{
	info->m_a[0][0] = ()((t_entity *)entity->content)->content
}

void	change_camera_system_coor(t_info *info)
{
	t_list	*camera;

	camera = get_entity(info->entites, CAMERA);

}
