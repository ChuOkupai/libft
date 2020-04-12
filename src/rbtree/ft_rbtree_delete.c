/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:38:46 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/12 02:09:51 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_rbtree_utils.h"
#include "libft/ft_memory.h"

static t_rbtree	*ft_rbtree_fixup_left(t_rbtree **root, t_rbtree *w,
				t_rbtree *x)
{
	if ((!w->left || w->left->color == RB_BLACK)
		&& (!w->right || w->right->color == RB_BLACK))
	{
		w->color = RB_RED;
		return (x->parent);
	}
	if (!w->right || w->right->color == RB_BLACK)
	{
		w->left->color = RB_BLACK;
		w->color = RB_RED;
		ft_rbtree_rotate_right(root, w);
		w = x->parent->right;
	}
	w->color = x->parent->color;
	x->parent->color = RB_BLACK;
	w->right->color = RB_BLACK;
	ft_rbtree_rotate_left(root, x->parent);
	return (*root);
}

static t_rbtree	*ft_rbtree_fixup_right(t_rbtree **root, t_rbtree *w,
				t_rbtree *x)
{
	if ((!w->right || w->right->color == RB_BLACK)
		&& (!w->left || w->left->color == RB_BLACK))
	{
		w->color = RB_RED;
		return (x->parent);
	}
	if (!w->left || w->left->color == RB_BLACK)
	{
		w->right->color = RB_BLACK;
		w->color = RB_RED;
		ft_rbtree_rotate_left(root, w);
		w = x->parent->left;
	}
	w->color = x->parent->color;
	x->parent->color = RB_BLACK;
	w->left->color = RB_BLACK;
	ft_rbtree_rotate_right(root, x->parent);
	return (*root);
}

static void		ft_rbtree_fixup(t_rbtree **root, t_rbtree *w, t_rbtree *x)
{
	while (x != *root && x->color == RB_BLACK)
		if (x == x->parent->left)
		{
			if ((w = x->parent->right)->color == RB_RED)
			{
				w->color = RB_BLACK;
				x->parent->color = RB_RED;
				ft_rbtree_rotate_left(root, x->parent);
				w = x->parent->right;
			}
			x = ft_rbtree_fixup_left(root, w, x);
		}
		else
		{
			if ((w = x->parent->left)->color == RB_RED)
			{
				w->color = RB_BLACK;
				x->parent->color = RB_RED;
				ft_rbtree_rotate_right(root, x->parent);
				w = x->parent->left;
			}
			x = ft_rbtree_fixup_right(root, w, x);
		}
	x->color = RB_BLACK;
}

static t_rbtree	*ft_rbtree_delete_case2children(t_rbtree **root, t_rbtree *z,
				t_rbtree *guard, t_rbcolor *ycolor)
{
	t_rbtree *x;
	t_rbtree *y;

	y = ft_rbtree_min(z->right);
	*ycolor = y->color;
	if (!(x = y->right))
	{
		x = ft_memset(guard, 0, sizeof(t_rbtree));
		x->parent = y;
		y->right = x;
	}
	if (y->parent == z)
		x->parent = y;
	else
	{
		ft_rbtree_transplant(root, y, y->right);
		y->right = z->right;
		y->right->parent = y;
	}
	ft_rbtree_transplant(root, z, y);
	y->left = z->left;
	y->left->parent = y;
	y->color = z->color;
	return (x);
}

void			ft_rbtree_delete(t_rbtree **root, t_rbtree *z,
				void (*del)(void *))
{
	t_rbtree	guard;
	t_rbtree	*x;
	t_rbcolor	ycolor;

	ycolor = z->color;
	if (!z->left)
	{
		if (!(x = z->right))
		{
			x = ft_memset(&guard, 0, sizeof(t_rbtree));
			x->parent = z;
			z->right = x;
		}
		ft_rbtree_transplant(root, z, x);
	}
	else if (!z->right)
		ft_rbtree_transplant(root, z, (x = z->left));
	else
		x = ft_rbtree_delete_case2children(root, z, &guard, &ycolor);
	if (ycolor == RB_BLACK && *root != &guard)
		ft_rbtree_fixup(root, NULL, x);
	ft_rbtree_remove_guard(root, x, &guard);
	if (del)
		del(z->content);
	free(z);
}
