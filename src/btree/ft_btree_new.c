/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:42:11 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/21 02:10:45 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree	*ft_btree_new(void *content)
{
	t_btree *b;

	if ((b = (t_btree*)malloc(sizeof(t_btree))))
		ft_btree_merge(b, NULL, NULL)->content = content;
	return (b);
}
