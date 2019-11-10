/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 00:00:15 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:32:49 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_list_insert(t_list **l, t_list *elem,
		int (*cmp)(const void *, const void *))
{
	if (!*l || cmp(elem->content, (*l)->content) <= 0)
		ft_list_push(l, elem);
	else
		ft_list_insert(&(*l)->next, elem, cmp);
}
