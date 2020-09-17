/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_popl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:58:36 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/17 19:29:30 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_popl(t_list **l)
{
	t_list *first;

	if (!(first = *l))
		return (NULL);
	*l = first->next;
	first->next = NULL;
	return (first);
}
