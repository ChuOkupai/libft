/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_minimum.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 15:09:02 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/25 15:14:42 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_rbtree.h"

t_rbtree	*ft_rbtree_min(t_rbtree *root)
{
	if (!root)
		return (NULL);
	while (root->left)
		root = root->left;
	return (root);
}
