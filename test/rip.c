/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:29:07 by asoursou          #+#    #+#             */
/*   Updated: 2020/01/22 19:43:13 by asoursou         ###   ########.fr       */
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
	ft_printf("%d\e[0m", (root->content ? *((int*)root->content) : -1));
	if (root->parent)
		ft_printf(":↑ %d", *((int*)root->parent->content));
	ft_putchar('\n');
	preorder(root->left, deep + 1);
	preorder(root->right, deep + 1);
}

void	test1()
{
	t_rbtree *tree = NULL, *n, *n2;

	ft_rbtree_insert(&tree, (n = new_node(7)), &intcmp);
	ft_rbtree_insert(&tree, new_node(2), &intcmp);
	ft_rbtree_insert(&tree, (n2 = new_node(9)), &intcmp);
	ft_rbtree_insert(&tree, new_node(1), &intcmp);
	ft_rbtree_insert(&tree, new_node(3), &intcmp);
	ft_rbtree_insert(&tree, new_node(8), &intcmp);
	ft_rbtree_insert(&tree, new_node(10), &intcmp);
	ft_rbtree_insert(&tree, new_node(14), &intcmp);
	ft_rbtree_delete(&tree, n, &free);
	ft_rbtree_delete(&tree, n2, &free);
	preorder(tree, 0);
	ft_rbtree_clear(&tree, &free);
}

void	test2()
{
	t_rbtree *tree = NULL, *n;

	ft_rbtree_insert(&tree, (n = new_node(2)), &intcmp);
	ft_rbtree_insert(&tree, new_node(1), &intcmp);
	ft_rbtree_delete(&tree, n, &free);
	preorder(tree, 0);
	ft_rbtree_clear(&tree, &free);
}

int	main()
{
	test2();
	return 0;
}
