/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 23:31:42 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 13:39:14 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_memory.h"

t_list	*ft_list_new(void *content)
{
	t_list *l;

	if ((l = (t_list*)ft_malloc(sizeof(t_list))))
	{
		l->content = content;
		l->next = NULL;
	}
	return (l);
}
