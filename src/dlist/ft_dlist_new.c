/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:02:00 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/26 12:51:12 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_dlist.h"

t_dlist	*ft_dlist_new(void *content)
{
	t_dlist *l;

	if ((l = (t_dlist*)malloc(sizeof(t_dlist))))
	{
		l->content = content;
		l->prev = NULL;
		l->next = NULL;
	}
	return (l);
}
