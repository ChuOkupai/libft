/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_transplant.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 15:24:46 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/25 15:25:51 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_rbtree.h"

void	ft_rbtree_transplant(t_rbtree **root, t_rbtree *u, t_rbtree *v)
{
	if (!u->parent)
		*root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	v->parent = u->parent;
}
