/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:05:07 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/24 22:45:49 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	ft_btree_insert(t_btree **root, t_btree *elem, t_gcompare cmp)
{
	if (!*root)
		*root = elem;
	else if (cmp(elem->content, (*root)->content) < 0)
		ft_btree_insert(&(*root)->left, elem, cmp);
	else
		ft_btree_insert(&(*root)->right, elem, cmp);
}
