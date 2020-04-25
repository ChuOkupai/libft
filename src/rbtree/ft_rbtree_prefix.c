/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_prefix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:23:42 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 17:24:04 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbtree.h"

void	ft_rbtree_prefix(t_rbtree *root, t_gfunction function)
{
	if (!root)
		return ;
	function(root->content);
	ft_rbtree_prefix(root->left, function);
	ft_rbtree_prefix(root->right, function);
}
