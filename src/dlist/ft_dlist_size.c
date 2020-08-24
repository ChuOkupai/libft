/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:32:35 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/24 17:32:42 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

size_t	ft_dlist_size(t_dlist *l)
{
	size_t i;

	i = 0;
	while (l)
	{
		l = l->next;
		i++;
	}
	return (i);
}
