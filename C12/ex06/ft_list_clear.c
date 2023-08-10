/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:27:42 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/08 00:51:46 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*free_elem;

	while (begin_list != NULL)
	{
		free_elem = begin_list;
		begin_list = begin_list->next;
		free_fct(free_elem->data);
		free_elem->next = NULL;
		free(free_elem);
	}
}
