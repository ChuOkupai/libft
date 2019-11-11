/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:42:11 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/11 15:43:30 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_btree.h"

t_btree	*ft_btree_new(void *content)
{
	t_btree *b;

	if ((b = (t_btree*)malloc(sizeof(t_btree))))
	{
		b->content = content;
		b->left = NULL;
		b->right = NULL;
	}
	return (b);
}
