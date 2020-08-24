/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:30:19 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/24 17:31:10 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_dlist_search(t_dlist *l, const void *reference, t_gcompare cmp)
{
	while (l && cmp(reference, l->content))
		l = l->next;
	return (l);
}
