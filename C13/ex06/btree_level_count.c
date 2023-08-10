/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 04:48:28 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/08 05:57:47 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	btree_level_count(t_btree *root)
{
	if (root == NULL)
		return (0);
	return (ft_max(btree_level_count(root->left), \
				btree_level_count(root->right)) + 1);
}
