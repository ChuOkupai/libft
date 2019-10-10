/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 01:38:39 by asoursou          #+#    #+#             */
/*   Updated: 2019/10/10 21:31:01 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

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
			l = NULL;
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
