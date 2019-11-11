/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:25:22 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/11 16:26:14 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

size_t	ft_btree_size(t_btree *root)
{
	if (!root)
		return (0);
	return (1 + ft_btree_size(root->left) + ft_btree_size(root->right));
}
