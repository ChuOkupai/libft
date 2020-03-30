/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 15:14:27 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/25 15:16:08 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_rbtree.h"

t_rbtree	*ft_rbtree_max(t_rbtree *root)
{
	if (!root)
		return (NULL);
	while (root->right)
		root = root->right;
	return (root);
}
