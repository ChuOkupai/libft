/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 13:01:17 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/10 13:03:50 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_merge(t_list *l1, t_list *l2)
{
	if (!l1)
		return (l2);
	if (!l2)
		return (l1);
	ft_list_last(l1)->next = l2;
	return (l1);
}
