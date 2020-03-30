/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_suffix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:58:00 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/30 01:50:44 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

void	ft_btree_suffix(t_btree *root, void (*f)(void *))
{
	if (!root)
		return ;
	ft_btree_suffix(root->left, f);
	ft_btree_suffix(root->right, f);
	f(root->content);
}
