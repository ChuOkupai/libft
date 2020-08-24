/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:02:00 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/24 17:35:58 by asoursou         ###   ########.fr       */
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
		ft_dlist_merge(l, NULL, NULL);
	}
	return (l);
}
