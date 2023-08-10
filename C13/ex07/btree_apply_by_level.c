/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 04:56:19 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/10 18:41:12 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	get_child_size(t_btree **arr)
{
	int	idx;
	int	size;

	size = 0;
	idx = 0;
	while (arr[idx] != NULL)
	{
		if (arr[idx]->left != NULL)
			size++;
		if (arr[idx]->right != NULL)
			size++;
		idx++;
	}
	return (size);
}

t_btree	**child_arr(t_btree **parent_arr)
{
	t_btree	**child;
	int		idx;
	int		child_idx;
	int		size;

	size = get_child_size(parent_arr);
	child = (t_btree **)malloc(sizeof(t_btree *) * (size + 1));
	idx = 0;
	child_idx = 0;
	while (parent_arr[idx] != NULL)
	{
		if (parent_arr[idx]->left != NULL)
			child[child_idx++] = parent_arr[idx]->left;
		if (parent_arr[idx]->right != NULL)
			child[child_idx++] = parent_arr[idx]->right;
		idx++;
	}
	child[size] = NULL;
	free(parent_arr);
	return (child);
}

void	btree_apply_by_level(t_btree *root, \
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_btree	**parent;
	int		level;
	int		idx;

	level = 0;
	parent = (t_btree **)malloc(sizeof(t_btree *) * (2));
	parent[0] = root;
	parent[1] = NULL;
	while (parent && parent[0] != NULL)
	{
		idx = 0;
		while (parent[idx])
		{
			applyf(parent[idx]->item, level, idx == 0);
			idx++;
		}
		parent = child_arr(parent);
		level++;
	}
}
