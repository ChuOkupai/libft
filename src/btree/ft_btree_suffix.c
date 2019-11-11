/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_suffix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:58:00 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/11 15:58:35 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

void	ft_btree_suffix(t_btree *root, void (*f)(void *))
{
	if (!root)
		return ;
	f(root->content);
	ft_btree_suffix(root->left, f);
	ft_btree_suffix(root->right, f);
}
