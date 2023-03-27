/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 01:24:13 by asoursou          #+#    #+#             */
/*   Updated: 2023/03/27 07:27:53 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **list, void (*f)(void *))
{
	t_list	*l;
	t_list	*next;

	l = *list;
	*list = NULL;
	while (l)
	{
		next = l->next;
		ft_lstdelone(l, f);
		l = next;
	}
}
