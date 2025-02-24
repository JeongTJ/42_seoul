/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:48:18 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/23 14:55:45 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	error_manager(char *error_massage)
{
	ft_putendl_fd(error_massage, 2);
	exit(1);
}

t_list	*get_entity(t_list *entites, t_entity_type type)
{
	while (entites)
	{
		if (((t_entity *)entites->content)->type == type)
			return (entites);
		entites = entites->next;
	}
	return (NULL);
}
