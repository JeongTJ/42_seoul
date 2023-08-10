/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:57:24 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/07 23:35:01 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	dummy;
	t_list	*idx_elem;
	t_list	*min_elem;

	dummy.next = *begin_list;
	*begin_list = &dummy;
	while ((*begin_list)->next != NULL)
	{
		min_elem = *begin_list;
		idx_elem = min_elem;
		while (idx_elem->next != NULL)
		{
			if (cmp(idx_elem->next->data, min_elem->next->data) < 0)
				min_elem = idx_elem;
			idx_elem = idx_elem->next;
		}
		idx_elem = min_elem->next;
		min_elem->next = idx_elem->next;
		idx_elem->next = (*begin_list)->next;
		(*begin_list)->next = idx_elem;
		*begin_list = (*begin_list)->next;
	}
	*begin_list = dummy.next;
}
