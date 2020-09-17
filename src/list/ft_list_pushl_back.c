/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pushl_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:19:33 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/17 19:21:36 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_pushl_back(t_list **l, t_list *elem)
{
	if (!elem)
		return (NULL);
	if (*l)
		ft_list_last(*l)->next = elem;
	else
		*l = elem;
	return (elem);
}
