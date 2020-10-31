/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 01:13:28 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/02 11:48:07 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	*ft_list_pop(t_list **list)
{
	t_list	*l;
	void	*c;

	if (!(l = ft_list_popl(list)))
		return (l);
	c = l->content;
	free(l);
	return (c);
}
