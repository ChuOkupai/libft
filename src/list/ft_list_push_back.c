/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:50:55 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/12 19:19:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_back(t_list **l, t_list *elem)
{
	if (!elem)
		return (NULL);
	if (*l)
		ft_list_last(*l)->next = elem;
	else
		*l = elem;
	return (elem);
}
