/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 00:21:38 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/08 00:48:09 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert2(t_list **begin_list, t_list *elem, int (*cmp)())
{
	t_list	dummy;

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

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, \
		int (*cmp)())
{
	t_list	*prev_elem;

	while (begin_list2 != NULL)
	{
		prev_elem = begin_list2;
		begin_list2 = begin_list2->next;
		prev_elem->next = NULL;
		ft_sorted_list_insert2(begin_list1, prev_elem, cmp);
	}
}
