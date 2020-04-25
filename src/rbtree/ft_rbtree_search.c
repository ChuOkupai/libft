/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:36:13 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/24 22:41:36 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbtree.h"

t_rbtree	*ft_rbtree_search(t_rbtree *root, const void *reference,
			t_gcompare cmp)
{
	int d;

	while (root && (d = cmp(reference, root->content)))
		root = d < 0 ? root->left : root->right;
	return (root);
}
