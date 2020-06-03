/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_print_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 03:13:55 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/03 13:33:19 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_const.h"
#include "ft_rbtree.h"
#include "ft_stdio.h"

static void	prefix(t_rbtree *root, t_gprint_fd print_fd, int fd, int deep)
{
	if (!root)
		return ;
	if (deep)
		ft_printf("%*c↳", deep - 2, ' ');
	ft_printf("(\x1b[%dm%c\x1b[0m, ",
	40 + root->color, (root->color == RB_BLACK ? 'B' : 'R'));
	print_fd(root->content, fd);
	ft_putstr_fd(")\n", fd);
	prefix(root->left, print_fd, fd, deep + 2);
	prefix(root->right, print_fd, fd, deep + 2);
}

void		ft_rbtree_print_fd(t_rbtree *root, t_gprint_fd print_fd, int fd)
{
	prefix(root, print_fd, fd, 0);
}
