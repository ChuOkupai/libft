/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:47:25 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 17:05:22 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	ft_btree_prefix(t_btree *root, t_gfunction function)
{
	if (!root)
		return ;
	function(root->content);
	ft_btree_prefix(root->left, function);
	ft_btree_prefix(root->right, function);
}
