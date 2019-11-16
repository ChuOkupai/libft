/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:11:49 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/16 16:10:47 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/ft_rbtree.h"

static t_rbtree	*ft_fixup_left(t_rbtree **root, t_rbtree *x)
{
	if (RUNCLE(x) && RUNCLE(x)->color == RB_RED)
	{
		x->parent->color = RB_BLACK;
		RUNCLE(x)->color = RB_BLACK;
		x = GPARENT(x);
		x->color = RB_RED;
	}
	else
	{
		if (x == x->parent->right)
			ft_rbtree_rotate_left(root, (x = x->parent));
		x->parent->color = RB_BLACK;
		GPARENT(x)->color = RB_RED;
		ft_rbtree_rotate_right(root, GPARENT(x));
	}
	return (x);
}

static t_rbtree	*ft_fixup_right(t_rbtree **root, t_rbtree *x)
{
	if (LUNCLE(x) && LUNCLE(x)->color == RB_RED)
	{
		x->parent->color = RB_BLACK;
		LUNCLE(x)->color = RB_BLACK;
		x = GPARENT(x);
		x->color = RB_RED;
	}
	else
	{
		if (x == x->parent->left)
			ft_rbtree_rotate_right(root, (x = x->parent));
		x->parent->color = RB_BLACK;
		GPARENT(x)->color = RB_RED;
		ft_rbtree_rotate_left(root, GPARENT(x));
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
		if (e->parent == GPARENT(e)->left)
			e = ft_fixup_left(root, e);
		else
			e = ft_fixup_right(root, e);
	(*root)->color = RB_BLACK;
}
