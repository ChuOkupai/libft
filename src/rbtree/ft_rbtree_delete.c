/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:38:46 by asoursou          #+#    #+#             */
/*   Updated: 2020/01/21 20:04:21 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_rbtree.h"

#include <stdio.h>

static void	preorder(t_rbtree *root, int deep)
{
	for (int i = 0; i < deep - 1; i++)
		printf("  ");
	if (!root)
	{
		if (deep)
			printf("↳ NIL\n");
		return;
	}
	if (deep)
		printf("↳ ");
	if (root->color == RB_RED)
		printf("\x1B[38;2;255;0;0m");
	else
		printf("\x1B[38;2;128;128;128m");
	printf("%d\e[0m", (root->content ? *((int*)root->content) : -1));
	if (root->parent)
		printf(":↑ %d", (root->parent->content ? *((int*)root->parent->content) : -1));
	putchar('\n');
	preorder(root->left, deep + 1);
	preorder(root->right, deep + 1);
}

static void		ft_rbtree_fixup(t_rbtree **root, t_rbtree *x)
{
	t_rbtree *w;

	while (x != *root && x->color == RB_BLACK)
		if (x == x->parent->left)
		{
			w = x->parent->right;
			if (w->color == RB_RED)
			{
				w->color = RB_BLACK;
				x->parent->color = RB_RED;
				ft_rbtree_rotate_left(root, x->parent);
				w = x->parent->right;
			}
			if ((!w->left || w->left->color == RB_BLACK)
			&& (!w->right || w->right->color == RB_BLACK))
			{
				w->color = RB_RED;
				x = x->parent;
			}
			else
			{
				if (w->right->color == RB_BLACK)
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
				printf("tree2:\n");
				preorder(*root, 0);
				x = *root;
			}
		}
		else
		{
			w = x->parent->left;
			if (w->color == RB_RED)
			{
				w->color = RB_BLACK;
				x->parent->color = RB_RED;
				ft_rbtree_rotate_right(root, x->parent);
				w = x->parent->left;
			}
			if ((!w->right || w->right->color == RB_BLACK)
				&& (!w->left || w->left->color == RB_BLACK))
			{
				w->color = RB_RED;
				x = x->parent;
			}
			else
			{
				if (w->left->color == RB_BLACK)
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
				x = *root;
			}
		}
	if (x)
		x->color = RB_BLACK;
}

void			ft_rbtree_delete(t_rbtree **root, t_rbtree *z,
				void (*del)(void *))
{
	t_rbtree	g;
	t_rbtree	*x;
	t_rbtree	*y;
	t_rbcolor	ycolor;

	y = z;
	ycolor = y->color;
	if (!z->left)
		ft_rbtree_transplant(root, z, (x = z->right));
	else if (!z->right)
		ft_rbtree_transplant(root, z, (x = z->left));
	else
	{
		y = ft_rbtree_minimum(z->right);
		ycolor = y->color;
		x = y->right;
		if (!x)
		{
			g = ft_rbtree_guard(NULL, NULL, NULL);
			x = &g;
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
	}
	preorder(*root, 0);
	if (ycolor == RB_BLACK)
		ft_rbtree_fixup(root, x);
	if (x == &g)
	{
		printf("remove guard\n");
		x = x->parent;
		if (x->left == &g)
			x->left = NULL;
		else
			x->right = NULL;
	}
	preorder(*root, 0);
	if (del)
		del(z->content);
	free(z);
}
