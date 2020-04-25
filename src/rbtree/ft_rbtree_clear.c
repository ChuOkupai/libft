/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:01:36 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 17:33:22 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_rbtree.h"

static void	clear(t_rbtree *root, t_gfunction del)
{
	if (!root)
		return ;
	clear(root->left, del);
	clear(root->right, del);
	if (del)
		del(root->content);
	free(root);
}

void		*ft_rbtree_clear(t_rbtree **root, t_gfunction del)
{
	clear(*root, del);
	return (*root = NULL);
}
