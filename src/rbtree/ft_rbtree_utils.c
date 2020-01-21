/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 13:31:54 by asoursou          #+#    #+#             */
/*   Updated: 2020/01/21 18:09:22 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_rbtree.h"

t_rbtree	ft_rbtree_guard(t_rbtree *parent, t_rbtree *left, t_rbtree *right)
{
	t_rbtree g;

	g.content = NULL;
	g.parent = parent;
	g.left = left;
	g.right = right;
	g.color = RB_BLACK;
	return (g);
}

t_rbtree	*ft_rbtree_minimum(t_rbtree *root)
{
	while (root->left)
		root = root->left;
	return (root);
}

void		ft_rbtree_rotate_left(t_rbtree **root, t_rbtree *x)
{
	t_rbtree *y;

	y = x->right;
	x->right = y->left;
	if (y->left)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent)
	{
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	else
		*root = y;
	y->left = x;
	x->parent = y;
}
void		ft_rbtree_rotate_right(t_rbtree **root, t_rbtree *y)
{
	t_rbtree *x;

	x = y->left;
	y->left = x->right;
	if (x->right)
		x->right->parent = y;
	x->parent = y->parent;
	if (y->parent)
	{
		if (y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;
	}
	else
		*root = x;
	x->right = y;
	y->parent = x;
}

void		ft_rbtree_transplant(t_rbtree **root, t_rbtree *u, t_rbtree *v)
{
	if (!u->parent)
		*root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	if (v)
		v->parent = u->parent;
}
