/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 01:24:13 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/10 13:00:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	*ft_list_clear(t_list **list, t_gfunction del)
{
	t_list *l;
	t_list *next;

	l = *list;
	*list = NULL;
	while (l)
	{
		if (del)
			del(l->content);
		next = l->next;
		free(l);
		l = next;
	}
	return (NULL);
}
