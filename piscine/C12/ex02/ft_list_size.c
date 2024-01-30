/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:08:43 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/06 15:22:14 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
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
