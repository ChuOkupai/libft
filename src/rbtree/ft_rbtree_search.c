/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:36:13 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/12 02:04:01 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_rbtree.h"

t_rbtree	*ft_rbtree_search(t_rbtree *root, void *ref,
			int (*cmp)(void *ref, void *content))
{
	t_rbtree *n;

	if (!root)
		return (NULL);
	if ((n = ft_rbtree_search(root->left, ref, cmp)))
		return (n);
	if (!cmp(ref, root->content))
		return (root);
	return (ft_rbtree_search(root->right, ref, cmp));
}
