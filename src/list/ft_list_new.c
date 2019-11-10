/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 23:31:42 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:32:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_list.h"

t_list	*ft_list_new(void *content)
{
	t_list *l;

	if ((l = (t_list*)malloc(sizeof(t_list))))
	{
		l->content = content;
		l->next = NULL;
	}
	return (l);
}
