/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_postfix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:58:00 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 17:30:11 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	ft_btree_postfix(t_btree *root, t_gfunction function)
{
	if (!root)
		return ;
	ft_btree_postfix(root->left, function);
	ft_btree_postfix(root->right, function);
	function(root->content);
}
