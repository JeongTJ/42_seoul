/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:13:44 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/06 15:51:09 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;
	t_list	*tail;

	elem = ft_create_elem(data);
	if (*begin_list == NULL)
	{
		*begin_list = elem;
		return ;
	}
	tail = *begin_list;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = elem;
}
