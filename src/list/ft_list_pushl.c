/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pushl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:58:38 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/17 19:21:51 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_pushl(t_list **l, t_list *elem)
{
	if (!elem)
		return (NULL);
	elem->next = *l;
	*l = elem;
	return (elem);
}
