/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge_at.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:44:43 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/02 13:51:44 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_merge_at(t_list *l, t_list *subl, size_t position)
{
	t_list	*prev;
	t_list	*next;

	if (!position || !l || !subl)
	{
		ft_list_push_back(&subl, l);
		return (subl);
	}
	if (!(prev = ft_list_at(l, position - 1)))
	{
		ft_list_push_back(&l, subl);
		return (l);
	}
	next = prev->next;
	prev->next = subl;
	ft_list_last(subl)->next = next;
	return (l);
}
