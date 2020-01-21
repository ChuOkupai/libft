/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:25:13 by asoursou          #+#    #+#             */
/*   Updated: 2020/01/21 19:55:58 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libft.h>

t_rbtree	*new_node(int n)
{
	int *p;

	if ((p = malloc(sizeof(int))))
	{
		*p = n;
		return (ft_rbtree_new(p));
	}
	return (NULL);
}

int	intcmp(void *a, void *b)
{
	return (*((int*)a) - *((int*)b));
}

int	minHeight(t_rbtree *root)  
{
	if (!root)
		return 0;
	if (!(root->left || root->right))
		return 1;
	if (!root->left)
		return minHeight(root->right) + 1;
	if (!root->right)
		return minHeight(root->left) + 1;
	if (minHeight(root->left) < minHeight(root->right))
		return minHeight(root->left) + 1;
	return minHeight(root->right) + 1;
}

int	maxHeight(t_rbtree *root)  
{
	if (! root)
		return 0;
	int l, r;
	l = maxHeight(root->left);
	r = maxHeight(root->right);
	return 1 + ((l > r) ? l : r);
}

int	menu()
{
	ft_printf("MENU\n");
	ft_printf("0: exit\n");
	ft_printf("1: insert a new node\n");
	ft_printf("2: print current tree\n");
	ft_printf("3: insert values from max to 1 in the tree (without duplicates)\n");
	ft_printf("4: search a key\n");
	ft_printf("5: remove a node\n");
	ft_printf("6: delete the current tree\n");
	ft_printf("7: ultimate random tree\n");
	return 1;
}

void	preorder(t_rbtree *root, int deep)
{
	for (int i = 0; i < deep - 1; i++)
		ft_printf("  ");
	if (!root)
	{
		if (deep)
			ft_printf("↳ NIL\n");
		return;
	}
	if (deep)
		ft_printf("↳ ");
	if (root->color == RB_RED)
		ft_printf("\x1B[38;2;255;0;0m");
	else
		ft_printf("\x1B[38;2;128;128;128m");
	ft_printf("%d\e[0m", *((int*)root->content));
	if (root->parent)
		ft_printf(":↑ %d", *((int*)root->parent->content));
	ft_putchar('\n');
	preorder(root->left, deep + 1);
	preorder(root->right, deep + 1);
}

int	main()
{
	t_rbtree	*tree = NULL;
	t_rbtree	*n;
	int			choice;
	int			key;
	unsigned	max;
	
	while (menu() && ft_printf("choice:\n") && scanf("%d", &choice) == 1 && choice)
		if (choice == 1)
		{
			ft_printf("new node key:\n");
			if (scanf("%d", &key) == 1)
			{
				if (ft_rbtree_search(tree, &key, &intcmp))
					ft_printf("key already exist!\n");
				else
					ft_rbtree_insert(&tree, new_node(key), &intcmp);
			}
		}
		else if (choice == 2)
		{
			ft_printf("tree:\n");
			preorder(tree, 0);
			ft_printf("\nheight:\nmin = %d, max = %d\n", minHeight(tree), maxHeight(tree));
		}
		else if (choice == 3)
		{
			ft_printf("number of values:\n");
			if (scanf("%d", &key) == 1)
				while (key > 0)
				{
					if (!ft_rbtree_search(tree,  &key, &intcmp))
						ft_rbtree_insert(&tree, new_node(key), &intcmp);
					key--;
				}
		}
		else if (choice == 4)
		{
			ft_printf("key to search:\n");
			if (scanf("%d", &key) == 1)
			{
				ft_printf("key ");
				if (! ft_rbtree_search(tree,  &key, &intcmp))
					ft_printf("not ");
				ft_printf("found!\n");
			}
		}
		else if (choice == 5)
		{
			ft_printf("node key to remove:\n");
			if (scanf("%d", &key) == 1)
			{
				if (!(n = ft_rbtree_search(tree, &key, &intcmp)))
					ft_printf("key not found\n");
				else
					ft_rbtree_delete(&tree, n, &free);
			}
		}
		else if (choice == 6)
			ft_rbtree_clear(&tree, &free);
		else if (choice == 7)
		{
			ft_rbtree_clear(&tree, &free);
			ft_printf("number of values:\n");
			if (scanf("%d", &choice) == 1)
			{
				max = 2 * choice;
				while (choice > 0)
				{
					key = rand() % max;
					if (ft_rbtree_search(tree,  &key, &intcmp))
						continue ;
					ft_rbtree_insert(&tree, new_node(key), &intcmp);
					choice--;
				}
				while (tree)
					ft_rbtree_delete(&tree, tree, &free);
			}
		}
	if (tree)
		ft_rbtree_clear(&tree, &free);
	return 0;
}
