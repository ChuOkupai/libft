/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_infix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:56:19 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 17:04:51 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	ft_btree_infix(t_btree *root, t_gfunction function)
{
	if (!root)
		return ;
	ft_btree_infix(root->left, function);
	function(root->content);
	ft_btree_infix(root->right, function);
}
