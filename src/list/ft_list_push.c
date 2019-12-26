/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 01:30:00 by asoursou          #+#    #+#             */
/*   Updated: 2019/12/26 14:21:01 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

int	ft_list_push(t_list **l, t_list *elem)
{
	if (!elem)
		return (-1);
	elem->next = *l;
	*l = elem;
	return (0);
}
