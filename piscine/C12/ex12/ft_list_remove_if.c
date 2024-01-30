/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:05:16 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/08 04:26:27 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, \
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*prev_elem;
	t_list	*remove_elem;
	t_list	dummy;

	dummy.next = *begin_list;
	*begin_list = &dummy;
	prev_elem = *begin_list;
	while (prev_elem->next != NULL)
	{
		if (cmp(prev_elem->next->data, data_ref) == 0)
		{
			remove_elem = prev_elem->next;
			prev_elem->next = remove_elem->next;
			free_fct(remove_elem->data);
			remove_elem->next = NULL;
			free(remove_elem);
		}
		else if (prev_elem->next != NULL)
			prev_elem = prev_elem->next;
	}
	*begin_list = dummy.next;
}
