/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:35:47 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/08 00:52:00 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size2(t_list *begin_list)
{
	int	size;

	if (begin_list == NULL)
		return (0);
	size = 1;
	while (begin_list->next != NULL)
	{
		begin_list = begin_list->next;
		size++;
	}
	return (size);
}

t_list	*ft_list_at2(t_list *begin_list, unsigned int nbr)
{
	unsigned int	idx;

	idx = 0;
	if (!begin_list)
		return (0);
	if (nbr == 0)
		return (begin_list);
	while (idx < nbr && begin_list != NULL)
	{
		begin_list = begin_list->next;
		idx++;
	}
	return (begin_list);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		size;
	int		idx;
	t_list	temp;
	t_list	*front_elem;
	t_list	*back_elem;

	size = ft_list_size2(begin_list);
	idx = 0;
	while (idx < size / 2)
	{
		front_elem = ft_list_at2(begin_list, idx);
		back_elem = ft_list_at2(begin_list, size - 1 - idx);
		temp.data = front_elem->data;
		front_elem->data = back_elem->data;
		back_elem->data = temp.data;
		idx++;
	}
}
