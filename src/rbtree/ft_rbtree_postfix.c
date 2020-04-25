/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_postfix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:31:04 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 17:32:43 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbtree.h"

void	ft_rbtree_postfix(t_rbtree *root, t_gfunction function)
{
	if (!root)
		return ;
	ft_rbtree_postfix(root->left, function);
	ft_rbtree_postfix(root->right, function);
	function(root->content);
}
