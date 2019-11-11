/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:47:25 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/11 15:58:33 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

void	ft_btree_prefix(t_btree *root, void (*f)(void *))
{
	if (!root)
		return ;
	f(root->content);
	ft_btree_prefix(root->left, f);
	ft_btree_prefix(root->right, f);
}
