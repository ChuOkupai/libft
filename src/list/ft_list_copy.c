/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 13:22:49 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/02 13:25:57 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_copy(t_list *l)
{
	t_list *l2;

	l2 = NULL;
	while (l)
		if (ft_list_push(&l2, ft_list_new(l->content)))
			l = l->next;
		else
			return (ft_list_clear(&l2, NULL));
	return (ft_list_rev(l2));
}
