/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_rev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 00:33:17 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/02 12:40:51 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_rev(t_list *l)
{
	t_list *l2;
	t_list *next;

	l2 = NULL;
	while (l)
	{
		next = l->next;
		ft_list_push(&l2, l);
		l = next;
	}
	return (l2);
}
