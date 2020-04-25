/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:15:32 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/24 22:45:40 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*ft_btree_search(t_btree *root, void *ref, t_gcompare cmp)
{
	t_btree *b;

	if (!root)
		return (NULL);
	if ((b = ft_btree_search(root->left, ref, cmp)))
		return (b);
	if (!cmp(ref, root->content))
		return (root);
	return (ft_btree_search(root->right, ref, cmp));
}
