/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 01:13:28 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/28 22:38:50 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_list.h"

void	ft_list_pop(t_list **l, void (*del)(void *))
{
	t_list *next;

	next = (*l)->next;
	if (del)
		del((*l)->content);
	free(*l);
	*l = next;
}
