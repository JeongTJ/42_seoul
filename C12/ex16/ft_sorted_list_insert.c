/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 00:08:10 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/08 00:34:35 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*elem;
	t_list	dummy;

	elem = ft_create_elem(data);
	if (*begin_list == NULL)
	{
		*begin_list = elem;
		return ;
	}
	dummy.next = *begin_list;
	*begin_list = &dummy;
	while (*begin_list != NULL)
	{
		if ((*begin_list)->next == NULL || \
				cmp((*begin_list)->next->data, elem->data) > 0)
		{
			elem->next = (*begin_list)->next;
			(*begin_list)->next = elem;
			break ;
		}
		*begin_list = (*begin_list)->next;
	}
	*begin_list = dummy.next;
}
