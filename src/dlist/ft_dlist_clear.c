/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:17:30 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/24 18:11:43 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	*ft_dlist_clear(t_dlist **list, t_gfunction del)
{
	t_dlist *l;

	l = *list;
	*list = NULL;
	while (l)
		ft_dlist_pop(&l, del);
	return (NULL);
}
