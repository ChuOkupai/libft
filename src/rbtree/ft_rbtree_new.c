/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:05:59 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 12:28:24 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_rbtree.h"

t_rbtree	*ft_rbtree_new(void *content)
{
	t_rbtree *n;

	if ((n = (t_rbtree*)ft_malloc(sizeof(t_rbtree))))
	{
		n->content = content;
		n->parent = NULL;
		n->left = NULL;
		n->right = NULL;
		n->color = RB_RED;
	}
	return (n);
}
