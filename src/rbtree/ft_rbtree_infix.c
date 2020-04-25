/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_infix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:32:24 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 17:32:55 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbtree.h"

void	ft_rbtree_infix(t_rbtree *root, t_gfunction function)
{
	if (!root)
		return ;
	ft_rbtree_infix(root->left, function);
	function(root->content);
	ft_rbtree_infix(root->right, function);
}
