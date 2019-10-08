/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 01:38:39 by asoursou          #+#    #+#             */
/*   Updated: 2019/10/08 11:23:09 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	del(void *content)
{
	(void)content;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list	*e;
	t_list	*l;
	t_list	*prev;

	l = NULL;
	prev = NULL;
	while (lst)
	{
		if (!(e = ft_lstnew(lst->content)))
		{
			ft_lstclear(&l, del);
			break ;
		}
		e = f(e);
		if (l)
			prev->next = e;
		else
			l = e;
		prev = e;
		lst = lst->next;
	}
	return (l);
}
