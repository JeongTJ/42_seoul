/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:34:54 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/08 20:10:26 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_reverse_recur(t_list *begin_list)
{
	t_list	*head;
	t_list	*reverse_tail;

	if (begin_list == NULL || begin_list->next == NULL)
		return (begin_list);
	head = begin_list;
	reverse_tail = begin_list->next;
	begin_list = ft_reverse_recur(begin_list->next);
	reverse_tail->next = head;
	head->next = NULL;
	return (begin_list);
}

void	ft_list_reverse(t_list **begin_list)
{
	*begin_list = ft_reverse_recur(*begin_list);
}
