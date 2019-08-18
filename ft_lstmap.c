/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 01:38:39 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/18 18:02:40 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	del(void *content, size_t content_size)
{
	free(content);
	(void)content_size;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*e;
	t_list	*last;
	t_list	*new;

	new = NULL;
	last = NULL;
	while (lst)
	{
		if (!(e = ft_lstnew(lst->content, lst->content_size)))
		{
			ft_lstdel(&new, &del);
			break;
		}
		e = f(e);
		if (new)
			last->next = e;
		else
			new = e;
		last = e;
		lst = lst->next;
	}
	return (new);
}
