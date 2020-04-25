/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 01:56:39 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 20:14:27 by asoursou         ###   ########.fr       */
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
		ft_printf("%*c", deep, ' ');
	ft_printf(FT_DS_BEGIN "\x1b[%dmX\x1b[0m" FT_ARRAY_LINK,
	30 + root->color);
	print(root->content);
	ft_putstr(FT_DS_END);
	prefix(root->left, print, deep + 2);
	prefix(root->right, print, deep + 2);
}

void		ft_rbtree_print(t_rbtree *root, t_gprint print)
{
	prefix(root, print, 0);
}
