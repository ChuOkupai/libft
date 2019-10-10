/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 01:38:39 by asoursou          #+#    #+#             */
/*   Updated: 2019/10/09 09:46:35 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	del(void *content)
{
	(void)content;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(void *))
{
	t_list	*e;
	t_list	*l;
	t_list	*prev;

	l = NULL;
	prev = NULL;
	while (lst)
	{
		if (!(e = f(lst->content)))
		{
			ft_lstclear(&l, del);
			break ;
		}
		if (l)
			prev->next = e;
		else
			l = e;
		prev = e;
		lst = lst->next;
	}
	return (l);
}
