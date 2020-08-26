/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_remove_one.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 16:44:45 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/26 16:56:43 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	*ft_dlist_remove_one(t_dlist **list, const void *reference,
		t_gcompare cmp, t_gfunction del)
{
	t_dlist *l;

	l = *list;
	if (!l)
		return (NULL);
	if (!cmp(reference, l->content))
		return (ft_dlist_pop(list, del));
	return (ft_dlist_remove_one(&l, reference, cmp, del));
}
