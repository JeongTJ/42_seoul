/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:29:54 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/06 17:00:51 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
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
