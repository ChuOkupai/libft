/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 23:31:42 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/16 01:09:15 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *l;
	
	if (!content)
		content_size = 0;
	if ((l = (t_list*)malloc(sizeof(t_list))) && (!content_size
		|| (l->content = (void*)malloc(sizeof(content_size)))))
	{
		if ((l->content_size = content_size))
			ft_memcpy(l->content, content, content_size);
		else
			l->content = NULL;
		l->next = NULL;
	}
	else
		ft_memdel((void**)&l);
	return (l);
}
