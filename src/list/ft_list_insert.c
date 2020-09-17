/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 00:00:15 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/17 19:14:33 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_insert(t_list **l, t_list *elem, t_gcompare cmp)
{
	if (!*l || cmp(elem->content, (*l)->content) <= 0)
		return (ft_list_pushl(l, elem));
	return (ft_list_insert(&(*l)->next, elem, cmp));
}
