/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 01:24:13 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 17:29:30 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

static void	clear(t_list *l, const t_gfunction del)
{
	if (!l)
		return ;
	clear(l->next, del);
	if (del)
		del(l->content);
	free(l);
}

void		*ft_list_clear(t_list **list, t_gfunction del)
{
	clear(*list, del);
	*list = NULL;
	return (NULL);
}
