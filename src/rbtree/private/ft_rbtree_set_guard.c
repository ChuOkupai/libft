/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_set_guard.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 22:05:27 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/24 22:12:31 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbtree_utils.h"
#include "ft_memory.h"

t_rbtree	*ft_rbtree_set_guard(t_rbtree *z, t_rbtree *guard)
{
	t_rbtree *x;

	if (!(x = z->right))
	{
		ft_bzero(guard, sizeof(t_rbtree));
		x = guard;
		x->parent = z;
		z->right = x;
	}
	return (x);
}
