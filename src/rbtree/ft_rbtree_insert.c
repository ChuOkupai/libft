/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:11:49 by asoursou          #+#    #+#             */
/*   Updated: 2019/12/03 12:41:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/ft_rbtree.h"

static t_rbtree	*ft_fixup_left(t_rbtree **root, t_rbtree *x)
{
	if (x->parent->parent->right && x->parent->parent->right->color == RB_RED)
	{
		x->parent->color = RB_BLACK;
		x = x->parent->parent;
		x->right->color = RB_BLACK;
		x->color = RB_RED;
	}
	else
	{
		if (x == x->parent->right)
			ft_rbtree_rotate_left(root, (x = x->parent));
		x->parent->color = RB_BLACK;
		x->parent->parent->color = RB_RED;
		ft_rbtree_rotate_right(root, x->parent->parent);
	}
	return (x);
}

static t_rbtree	*ft_fixup_right(t_rbtree **root, t_rbtree *x)
{
	if (x->parent->parent->left && x->parent->parent->left->color == RB_RED)
	{
		x->parent->color = RB_BLACK;
		x = x->parent->parent;
		x->left->color = RB_BLACK;
		x->color = RB_RED;
	}
	else
	{
		if (x == x->parent->left)
			ft_rbtree_rotate_right(root, (x = x->parent));
		x->parent->color = RB_BLACK;
		x->parent->parent->color = RB_RED;
		ft_rbtree_rotate_left(root, x->parent->parent);
	}
	return (x);
}

void			ft_rbtree_insert(t_rbtree **root, t_rbtree *e,
				int (*cmp)(void *, void *))
{
	int			d;
	t_rbtree	*x;
	t_rbtree	*y;

	x = *root;
	y = NULL;
	while (x)
	{
		y = x;
		d = cmp(e->content, x->content);
		x = (d < 0) ? x->left : x->right;
	}
	if (!(e->parent = y))
		*root = e;
	else if (d < 0)
		y->left = e;
	else
		y->right = e;
	while (e != *root && e->parent->color == RB_RED)
		if (e->parent == e->parent->parent->left)
			e = ft_fixup_left(root, e);
		else
			e = ft_fixup_right(root, e);
	(*root)->color = RB_BLACK;
}
