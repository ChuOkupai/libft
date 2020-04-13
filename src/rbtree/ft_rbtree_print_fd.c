/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_print_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 03:13:55 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/13 03:16:25 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbtree.h"
#include "ft_stdio.h"

static void	prefix_traversal(t_rbtree *root,
			void (*print)(const void *content, int fd), int fd, int deep)
{
	if (!root)
		return ;
	if (deep)
		ft_dprintf(fd, "%*c", deep, ' ');
	ft_dprintf(fd, "(\x1b[%dm  \x1b[0m, ", 40 + root->color);
	print(root->content, fd);
	ft_dprintf(fd, ")\n");
	prefix_traversal(root->left, print, fd, deep + 2);
	prefix_traversal(root->right, print, fd, deep + 2);
}

void		ft_rbtree_print_fd(t_rbtree *root,
			void (*print)(const void *content, int fd), int fd)
{
	prefix_traversal(root, print, fd, 0);
}
