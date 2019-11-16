/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 11:49:33 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/16 11:53:20 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_btree.h"

static void	ft_clear(t_btree *root, void (*del)(void *))
{
	if (!root)
		return ;
	ft_clear(root->left, del);
	ft_clear(root->right, del);
	if (del)
		free(root->content);
	free(root);
}

void		ft_btree_clear(t_btree **root, void (*del)(void *))
{
	ft_clear(*root, del);
	*root = NULL;
}
