/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:05:07 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/02 19:09:17 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*ft_btree_insert(t_btree **root, t_btree *elem, t_gcompare cmp)
{
	if (!*root)
		return (*root = elem);
	else if (cmp(elem->content, (*root)->content) < 0)
		return (ft_btree_insert(&(*root)->left, elem, cmp));
	else
		return (ft_btree_insert(&(*root)->right, elem, cmp));
}
