/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_rev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 00:33:17 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/03 05:01:17 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_rev(t_list **l)
{
	t_list *prev;
	t_list *next;

	prev = NULL;
	while (*l)
	{
		next = (*l)->next;
		ft_list_push(&prev, *l);
		*l = next;
	}
	*l = prev;
}