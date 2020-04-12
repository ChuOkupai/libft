/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 01:13:28 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/12 18:24:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	*ft_list_pop(t_list **l, void (*del)(void *))
{
	t_list	*next;
	void	*content;

	next = (*l)->next;
	if (del)
	{
		del((*l)->content);
		content = NULL;
	}
	else
		content = (*l)->content;
	free(*l);
	*l = next;
	return (content);
}
