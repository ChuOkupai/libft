/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 20:38:53 by asoursou          #+#    #+#             */
/*   Updated: 2020/01/22 20:40:28 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_rbtree.h"

size_t	ft_rbtree_size(t_rbtree *root)
{
	if (!root)
		return (0);
	return (1 + ft_rbtree_size(root->left) + ft_rbtree_size(root->right));
}