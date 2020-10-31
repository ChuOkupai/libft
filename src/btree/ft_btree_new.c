/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:42:11 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/02 12:12:04 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "ft_memory.h"

t_btree	*ft_btree_new(void *content)
{
	t_btree *b;

	if ((b = (t_btree*)ft_new(sizeof(t_btree))))
		ft_btree_merge(b, NULL, NULL)->content = content;
	return (b);
}
