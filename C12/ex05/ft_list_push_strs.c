/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:22:57 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/06 17:14:31 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*begin_list;
	t_list	*elem;
	int		idx;

	begin_list = NULL;
	idx = 0;
	while (idx < size)
	{
		elem = ft_create_elem(strs[idx]);
		elem->next = begin_list;
		begin_list = elem;
		idx++;
	}
	return (begin_list);
}
