/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 01:10:13 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/08 16:02:44 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_insert_node(t_btree *prev_node, void *item, \
		int (*cmpf)(void *, void *))
{
	while (1)
	{
		if (cmpf(prev_node->item, item) < 0)
		{
			if (prev_node->right == NULL)
				break ;
			else
				prev_node = prev_node->right;
		}
		else
		{
			if (prev_node->left == NULL)
				break ;
			else
				prev_node = prev_node->left;
		}
	}
	return (prev_node);
}

void	btree_insert_data(t_btree **root, void *item, \
		int (*cmpf)(void *, void *))
{
	t_btree	*node;
	t_btree	*prev_node;

	node = btree_create_node(item);
	if (*root == NULL)
	{
		*root = node;
		return ;
	}
	prev_node = btree_insert_node(*root, item, cmpf);
	if (cmpf(prev_node->item, item) < 0)
		prev_node->right = node;
	else if (cmpf(prev_node->item, item) >= 0)
		prev_node->left = node;
}
