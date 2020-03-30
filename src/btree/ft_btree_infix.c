/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_infix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:56:19 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/30 01:50:33 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

void	ft_btree_infix(t_btree *root, void (*f)(void *))
{
	if (!root)
		return ;
	ft_btree_infix(root->left, f);
	f(root->content);
	ft_btree_infix(root->right, f);
}
