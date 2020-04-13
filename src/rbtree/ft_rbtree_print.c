/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 01:56:39 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/13 03:10:30 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbtree.h"
#include "ft_stdio.h"

static void	prefix_traversal(t_rbtree *root,
			void (*print)(const void *content), int deep)
{
	if (!root)
		return ;
	if (deep)
		ft_printf("%*c", deep, ' ');
	ft_printf("(\x1b[%dm  \x1b[0m, ", 40 + root->color);
	print(root->content);
	ft_printf(")\n");
	prefix_traversal(root->left, print, deep + 2);
	prefix_traversal(root->right, print, deep + 2);
}

void		ft_rbtree_print(t_rbtree *root,
			void (*print)(const void *content))
{
	prefix_traversal(root, print, 0);
}
