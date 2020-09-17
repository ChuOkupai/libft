/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:41:01 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/17 19:42:27 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *l, const void *reference, t_gcompare cmp,
		t_gfunction function)
{
	while (l)
	{
		if (!cmp(reference, l->content))
			function(l->content);
		l = l->next;
	}
}
