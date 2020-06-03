/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 01:56:39 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/03 13:32:56 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_const.h"
#include "ft_rbtree.h"
#include "ft_stdio.h"

static void	prefix(t_rbtree *root, t_gprint print, int deep)
{
	if (!root)
		return ;
	if (deep)
		ft_printf("%*c↳", deep - 2, ' ');
	ft_printf("(\x1b[%dm%c\x1b[0m, ",
	40 + root->color, (root->color == RB_BLACK ? 'B' : 'R'));
	print(root->content);
	ft_putstr(")\n");
	prefix(root->left, print, deep + 2);
	prefix(root->right, print, deep + 2);
}

void		ft_rbtree_print(t_rbtree *root, t_gprint print)
{
	prefix(root, print, 0);
}
