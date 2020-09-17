/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 01:13:28 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/17 19:18:46 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	*ft_list_pop(t_list **l, t_gfunction del)
{
	t_list	*elem;
	void	*content;

	if (!(elem = ft_list_popl(l)))
		return (NULL);
	if (del)
	{
		del(elem->content);
		content = NULL;
	}
	else
		content = elem->content;
	free(elem);
	return (content);
}
