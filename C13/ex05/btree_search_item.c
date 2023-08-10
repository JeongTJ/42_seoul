/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 02:00:16 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/08 05:57:41 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, \
		int (*cmpf)(void *, void *))
{
	void	*left_item;
	void	*right_item;

	if (root == NULL)
		return (NULL);
	left_item = btree_search_item(root->left, data_ref, cmpf);
	if (left_item != NULL && cmpf(left_item, data_ref) == 0)
		return (left_item);
	if (cmpf(root->item, data_ref) == 0 || cmpf(root->item, data_ref) == 0)
		return (root->item);
	right_item = btree_search_item(root->right, data_ref, cmpf);
	if (right_item != NULL && cmpf(right_item, data_ref) == 0)
		return (right_item);
	return (0);
}
