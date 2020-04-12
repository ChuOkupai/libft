/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_remove_guard.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 15:24:08 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/12 02:04:01 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_rbtree.h"

void	ft_rbtree_remove_guard(t_rbtree **root, t_rbtree *x, t_rbtree *g)
{
	if (x != g)
		return ;
	if (!(x = x->parent))
		*root = NULL;
	else if (x->left == g)
		x->left = NULL;
	else
		x->right = NULL;
}
