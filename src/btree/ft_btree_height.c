/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:20:50 by asoursou          #+#    #+#             */
/*   Updated: 2019/12/03 12:14:48 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

size_t	ft_btree_height(t_btree *root)
{
	size_t l;
	size_t r;

	if (!root)
		return (0);
	l = ft_btree_height(root->left);
	r = ft_btree_height(root->right);
	return (1 + (l > r ? l : r));
}
