/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:20:50 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/11 16:24:46 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"
#include "libft_macros.h"

size_t	ft_btree_height(t_btree *root)
{
	size_t l;
	size_t r;

	if (!root)
		return (0);
	l = ft_btree_height(root->left);
	r = ft_btree_height(root->right);
	return (1 + MAX(l, r));
}
