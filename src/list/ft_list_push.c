/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 01:30:00 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/12 19:20:41 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push(t_list **l, t_list *elem)
{
	if (!elem)
		return (NULL);
	elem->next = *l;
	*l = elem;
	return (elem);
}
