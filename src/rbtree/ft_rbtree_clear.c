/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:01:36 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/12 02:04:01 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/ft_rbtree.h"

static void	ft_clear(t_rbtree *root, void (*del)(void *))
{
	if (!root)
		return ;
	ft_clear(root->left, del);
	ft_clear(root->right, del);
	if (del)
		free(root->content);
	free(root);
}

void		ft_rbtree_clear(t_rbtree **root, void (*del)(void *))
{
	ft_clear(*root, del);
	*root = NULL;
}
